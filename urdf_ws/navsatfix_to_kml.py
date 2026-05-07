#!/usr/bin/env python3

import argparse
import math
from pathlib import Path

from rosbags.highlevel import AnyReader
from rosbags.typesys import Stores, get_typestore


def build_kml(coords, name="Trayectoria Cuadriga", color="ff0000ff", width=3):
    lines = [
        '<?xml version="1.0" encoding="UTF-8"?>',
        '<kml xmlns="http://www.opengis.net/kml/2.2">',
        '  <Document>',
        f'    <name>{name}</name>',
        '    <Placemark>',
        f'      <name>{name}</name>',
        '      <Style>',
        '        <LineStyle>',
        f'          <color>{color}</color>',
        f'          <width>{width}</width>',
        '        </LineStyle>',
        '      </Style>',
        '      <LineString>',
        '        <tessellate>1</tessellate>',
        '        <coordinates>',
    ]

    for lon, lat, alt in coords:
        lines.append(f'          {lon},{lat},{alt}')

    lines += [
        '        </coordinates>',
        '      </LineString>',
        '    </Placemark>',
        '  </Document>',
        '</kml>',
    ]
    return "\n".join(lines)


def choose_typestore(distro_name: str):
    distro_name = distro_name.lower()

    mapping = {
        "foxy": Stores.ROS2_FOXY,
        "galactic": Stores.ROS2_GALACTIC,
        "humble": Stores.ROS2_HUMBLE,
        "iron": Stores.ROS2_IRON,
        "jazzy": Stores.ROS2_JAZZY,
        "latest": Stores.LATEST,
    }

    if distro_name not in mapping:
        raise ValueError(
            f"Distro no soportada: {distro_name}. "
            f"Usa una de: {', '.join(mapping.keys())}"
        )

    return get_typestore(mapping[distro_name])


def main():
    parser = argparse.ArgumentParser(
        description="Convertir un topic sensor_msgs/msg/NavSatFix de rosbag2 a KML"
    )
    parser.add_argument(
        "bag_path",
        help="Ruta a la carpeta del rosbag2",
    )
    parser.add_argument(
        "--topic",
        default="/Cuadriga/fixposition/navsatfix",
        help="Topic NavSatFix a exportar",
    )
    parser.add_argument(
        "--output",
        default="cuadriga_real.kml",
        help="Archivo KML de salida",
    )
    parser.add_argument(
        "--distro",
        default="latest",
        help="Distro ROS2 del bag: foxy, galactic, humble, iron, jazzy o latest",
    )
    parser.add_argument(
        "--name",
        default="Trayectoria Cuadriga",
        help="Nombre de la trayectoria en el KML",
    )

    args = parser.parse_args()

    bag_path = Path(args.bag_path)
    if not bag_path.exists():
        print(f"ERROR: no existe la ruta {bag_path}")
        return

    print("--- Iniciando conversión ---")
    print(f"Bag:   {bag_path}")
    print(f"Topic: {args.topic}")
    print(f"KML:   {args.output}")
    print(f"Distro tipestore: {args.distro}")

    coords = []
    puntos_contados = 0

    try:
        typestore = choose_typestore(args.distro)

        with AnyReader([bag_path], default_typestore=typestore) as reader:
            connections = [c for c in reader.connections if c.topic == args.topic]

            if not connections:
                print(f"\nERROR: no se encontró el topic '{args.topic}'")
                print("\nTopics disponibles en el bag:")
                for c in reader.connections:
                    print(f" - {c.topic}   ({c.msgtype})")
                return

            for connection, timestamp, rawdata in reader.messages(connections=connections):
                msg = reader.deserialize(rawdata, connection.msgtype)

                lat = msg.latitude
                lon = msg.longitude
                alt = msg.altitude

                if any(math.isnan(v) for v in (lat, lon, alt)):
                    continue

                if lat == 0.0 and lon == 0.0:
                    continue

                # KML usa longitud, latitud, altitud
                coords.append((lon, lat, alt))
                puntos_contados += 1

        if not coords:
            print("\nNo se encontraron mensajes válidos de NavSatFix.")
            return

        kml_text = build_kml(coords, name=args.name)

        output_path = Path(args.output)
        output_path.write_text(kml_text, encoding="utf-8")

        print(f"\n¡Éxito! Se han exportado {puntos_contados} puntos.")
        print(f"Archivo generado: {output_path.resolve()}")

    except Exception as e:
        print(f"\nError crítico: {e}")


if __name__ == "__main__":
    main()