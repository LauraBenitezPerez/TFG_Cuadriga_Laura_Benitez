import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cartographer_ros',
            executable='cartographer_node',
            name='cartographer_node',
            output='screen',
            parameters=[{'use_sim_time': True}, 'your_package/config/cartographer_config.lua'],
            remappings=[('/scan', '/lidar_scan')]  # Remap de tópico LiDAR
        ),
    ])