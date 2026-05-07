#!/usr/bin/env python3

import argparse
import math
import xml.etree.ElementTree as ET
from pathlib import Path

import numpy as np
import matplotlib.pyplot as plt


# R global eliminada (era código muerto, estaba duplicada dentro de gps_a_xy_unity)


def leer_kml(kml_path):
    """
    Lee un archivo KML y extrae todas las coordenadas encontradas.
    Devuelve una lista de puntos (lon, lat, alt).
    """
    tree = ET.parse(kml_path)
    root = tree.getroot()

    coords = []

    for elem in root.iter():
        if elem.tag.endswith("coordinates") and elem.text:
            texto = elem.text.strip()
            puntos = texto.split()

            for p in puntos:
                partes = p.split(",")
                if len(partes) >= 2:
                    lon = float(partes[0])
                    lat = float(partes[1])
                    alt = float(partes[2]) if len(partes) >= 3 else 0.0
                    coords.append((lon, lat, alt))

    return np.array(coords)


def gps_a_xy_unity(coords, lat0, lon0):
    """
    Conversión GPS -> XY usando la misma lógica que la función LLR2XYR
    empleada en la controladora adaptada.

    coords debe tener columnas:
    coords[:, 0] = longitud
    coords[:, 1] = latitud
    coords[:, 2] = altitud

    # *** CAMBIO: lat0 y lon0 ahora se reciben como parámetros en vez de
    # estar hardcodeados. Así el origen se calcula desde el primer punto
    # real del recorrido y no desde un valor fijo. ***
    """

    R = 6378137.0

    lat = np.deg2rad(coords[:, 1])
    lon = np.deg2rad(coords[:, 0])

    lat0_rad = math.radians(lat0)  # *** CAMBIO: antes era math.radians(36.7171415) ***
    lon0_rad = math.radians(lon0)  # *** CAMBIO: antes era math.radians(-4.4895005) ***

    dLat = lat - lat0_rad
    dLon = lon - lon0_rad

    X = dLat * R
    Y = -dLon * R * math.cos(lat0_rad)

    return np.column_stack((X, Y))


def distancia_punto_segmento(p, a, b):
    """
    Distancia mínima de un punto p a un segmento definido por a-b.
    """
    ap = p - a
    ab = b - a

    ab2 = np.dot(ab, ab)

    if ab2 == 0:
        return np.linalg.norm(p - a)

    t = np.dot(ap, ab) / ab2
    t = max(0, min(1, t))

    proyeccion = a + t * ab

    return np.linalg.norm(p - proyeccion)


def error_a_trayectoria(puntos, trayectoria_ref):
    """
    Para cada punto de una trayectoria, calcula la distancia mínima
    a la trayectoria de referencia.
    """
    errores = []

    for p in puntos:
        distancias = []

        for i in range(len(trayectoria_ref) - 1):
            a = trayectoria_ref[i]
            b = trayectoria_ref[i + 1]
            d = distancia_punto_segmento(p, a, b)
            distancias.append(d)

        errores.append(min(distancias))

    return np.array(errores)


def main():
    parser = argparse.ArgumentParser(description="Comparar dos trayectorias KML")
    parser.add_argument("kml_real", help="Archivo KML del robot real")
    parser.add_argument("kml_sim", help="Archivo KML de la simulación")
    parser.add_argument("--out", default="comparacion", help="Prefijo de salida")

    args = parser.parse_args()

    kml_real = Path(args.kml_real)
    kml_sim = Path(args.kml_sim)

    coords_real = leer_kml(kml_real)
    coords_sim = leer_kml(kml_sim)

    if len(coords_real) == 0:
        raise RuntimeError("No se encontraron coordenadas en el KML real.")

    if len(coords_sim) == 0:
        raise RuntimeError("No se encontraron coordenadas en el KML simulado.")

    # *** CAMBIO: el origen se extrae del primer punto del KML real,
    # en vez de usar Latitud0=36.7171415 y Longitud0=-4.4895005 fijos.
    # Así ambas trayectorias se miden desde el mismo punto de partida. ***
    lat0 = coords_real[0, 1]
    lon0 = coords_real[0, 0]

    print(f"Origen dinámico: lat={lat0:.7f}, lon={lon0:.7f}")

    xy_real = gps_a_xy_unity(coords_real, lat0, lon0)
    xy_sim  = gps_a_xy_unity(coords_sim,  lat0, lon0)  # *** CAMBIO: misma función, mismo origen ***

    # Error: distancia de cada punto simulado a la trayectoria real
    errores = error_a_trayectoria(xy_sim, xy_real)

    error_medio = np.mean(errores)
    error_max   = np.max(errores)
    error_min   = np.min(errores)
    error_std   = np.std(errores)

    print("Resultados:")
    print(f"Error medio: {error_medio:.3f} m")
    print(f"Error máximo: {error_max:.3f} m")
    print(f"Error mínimo: {error_min:.3f} m")
    print(f"Desviación típica: {error_std:.3f} m")

    # Guardar métricas
    with open(f"{args.out}_metricas.txt", "w", encoding="utf-8") as f:
        f.write("Comparación trayectoria real vs simulada\n")
        f.write(f"Origen: lat={lat0:.7f}, lon={lon0:.7f}\n")  # *** CAMBIO: se guarda el origen usado ***
        f.write(f"Error medio: {error_medio:.3f} m\n")
        f.write(f"Error máximo: {error_max:.3f} m\n")
        f.write(f"Error mínimo: {error_min:.3f} m\n")
        f.write(f"Desviación típica: {error_std:.3f} m\n")

    # Gráfica de trayectorias
    plt.figure(figsize=(8, 6))
    plt.plot(xy_real[:, 0], xy_real[:, 1], label="Robot real")
    plt.plot(xy_sim[:, 0],  xy_sim[:, 1],  label="Simulación")
    plt.xlabel("X local [m]")
    plt.ylabel("Y local [m]")
    plt.title("Comparación de trayectorias")
    plt.axis("equal")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.savefig(f"{args.out}_trayectorias.png", dpi=300)
    plt.close()  # *** CAMBIO: se cierra la figura para liberar memoria ***

    # Gráfica de error
    plt.figure(figsize=(8, 4))
    plt.plot(errores)
    plt.xlabel("Muestra de la trayectoria simulada")
    plt.ylabel("Error respecto a trayectoria real [m]")
    plt.title("Error entre trayectoria simulada y trayectoria real")
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(f"{args.out}_error.png", dpi=300)
    plt.close()  # *** CAMBIO: se cierra la figura para liberar memoria ***

    print(f"\nArchivos generados:")
    print(f"- {args.out}_trayectorias.png")
    print(f"- {args.out}_error.png")
    print(f"- {args.out}_metricas.txt")


if __name__ == "__main__":
    main()