from launch import LaunchDescription
from launch.actions import ExecuteProcess, TimerAction
from launch_ros.actions import LifecycleNode, Node

def generate_launch_description():

    # 1. Flatland server
    flatland_server = ExecuteProcess(
        cmd=['ros2', 'launch', 'flatland_server', 'server.launch', 'world_path:=world/world.yaml'],
        output='screen'
    )

    # 2. Static transform publisher (map -> world)
    static_transform_publisher = ExecuteProcess(
        cmd=['ros2', 'run', 'tf2_ros', 'static_transform_publisher', '0', '0', '0', '0', '0', '0', '1', 'map', 'world'],
        output='screen'
    )

    # 3. Map server as a lifecycle node
    map_server_node = LifecycleNode(
        package='nav2_map_server',
        executable='map_server',
        name='map_server',
        output='screen',
        parameters=[{'yaml_filename': 'world/map.yaml'}],
        namespace=''
    )

    # 4. Configure the map server
    configure_map_server = ExecuteProcess(
        cmd=['ros2', 'lifecycle', 'set', '/map_server', 'configure'],
        output='screen'
    )

    # 5. Activate the map server after configuration
    activate_map_server = ExecuteProcess(
        cmd=['ros2', 'lifecycle', 'set', '/map_server', 'activate'],
        output='screen'
    )

    # Add a delay before activation to ensure configuration is complete
    delayed_activation = TimerAction(
        period=5.0,  # Wait for 5 seconds before activating
        actions=[activate_map_server]
    )

    # 6. RViz2 launch with a delay
    rviz_node = TimerAction(
        period=5.0,  # Wait for 5 seconds before starting RViz
        actions=[Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=["-d", "rviz/map.rviz"],
            output='screen'
        )]
    )

    return LaunchDescription([
        flatland_server,
        static_transform_publisher,
        map_server_node,
        configure_map_server,   # Immediately configure map server
        delayed_activation,     # Delay activation by 5 seconds
        rviz_node               # Delay RViz by 5 seconds
    ])
