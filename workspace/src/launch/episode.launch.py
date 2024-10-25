from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='robots',
            executable='move1',
            name='move1'
        ),
        Node(
            package='robots',
            executable='move2',
            name='move2'
        )
    ])
