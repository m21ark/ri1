import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    # Get the path to your URDF file
    urdf_file1 = os.path.join(
        get_package_share_directory('robot1'),
        'urdf',
        'robot1.urdf')
    
    urdf_file2 = os.path.join(
    get_package_share_directory('robot2'),
    'urdf',
    'robot2.urdf')
    
    return LaunchDescription([
        # Start Gazebo
        ExecuteProcess(
            cmd=['gazebo', '--verbose', '-s', 'libgazebo_ros_factory.so'],
            output='screen'),

        # Spawn Robot 1
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=['-entity', 'robot1', '-file', urdf_file1],
            output='screen'),

        # Spawn Robot 2
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=['-entity', 'robot2', '-file', urdf_file2],
            output='screen')
    ])
