#!/usr/bin/env python3
"""
generate_message_lookup.py
Script para generar la tabla de correspondencia de mensajes ROS <-> Unity.

Este script se usa con el paquete Unity ROS–TCP–Connector.
"""

import os
import sys
import yaml
from ament_index_python.packages import get_package_share_directory
import rclpy


def find_msg_packages():
    """Devuelve todos los paquetes ROS2 que contienen mensajes."""
    from rosidl_runtime_py import get_message_interfaces
    message_interfaces = get_message_interfaces()
    return message_interfaces.keys()


def generate_lookup(output_dir):
    """Genera el archivo .yaml para que Unity sepa dónde están los mensajes."""
    os.makedirs(output_dir, exist_ok=True)

    lookup_dict = {}
    for pkg in find_msg_packages():
        try:
            share_dir = get_package_share_directory(pkg)
            msg_path = os.path.join(share_dir, "msg")
            if os.path.exists(msg_path):
                lookup_dict[pkg] = msg_path
        except Exception:
            continue

    lookup_file = os.path.join(output_dir, "ros_tcp_endpoint.yaml")
    with open(lookup_file, "w") as f:
        yaml.dump(lookup_dict, f)

    print(f"✅ Archivo generado: {lookup_file}")
    print(f"   Paquetes detectados: {list(lookup_dict.keys())}")


def main(args=None):
    rclpy.init(args=args)
    output_dir = os.path.join(
        os.path.expanduser("~"),
        "urdf_ws",
        "src",
        "ros_tcp_endpoint",
        "config"
    )
    generate_lookup(output_dir)
    rclpy.shutdown()


if __name__ == "__main__":
    main()

