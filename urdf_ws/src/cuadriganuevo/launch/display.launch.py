import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription

from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node 

def  generate_launch_description():
    rviz_config = os.path.join(get_package_share_directory('cuadriganuevo'),'config/rviz_config.rviz')

    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    urdf_file_name = 'cuadriganuevo.urdf'

    urdf = os.path.join(
        get_package_share_directory('cuadriganuevo'),'urdf',
        urdf_file_name)
    with open(urdf,'r') as infp:
        robot_desc = infp.read()
    
    return LaunchDescription([
        Node(
            package='joint_state_publisher_gui',
            executable='joint_state_publisher_gui',
            name='joint_state_publisher_gui'
        ),
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'use_sim_time':use_sim_time,'robot_description':robot_desc}],
            arguments=[urdf]
        ),
        Node(
            package='rviz2',
            namespace='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d',rviz_config]
        )
    ])