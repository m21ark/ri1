from launch import LaunchDescription
from launch.actions import ExecuteProcess, RegisterEventHandler, LogInfo
from launch_ros.actions import LifecycleNode, Node
from launch_ros.events.lifecycle import ChangeState
from launch.event_handlers import OnProcessStart

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

    # 3. Map server
    map_server_node = LifecycleNode(
        package='nav2_map_server',
        executable='map_server',
        name='map_server',
        namespace='',
        output='screen',
        parameters=[{'yaml_filename': 'world/map.yaml'}]
    )

    # Automatically configure map_server when it starts
    configure_map_push = RegisterEventHandler(
        OnProcessStart(
            target_action=map_server_node,
            on_start=[
                ExecuteProcess(
                    cmd=['ros2', 'lifecycle', 'set', '/map_server', 'configure'],
                    output='screen'
                ),
                ExecuteProcess(
                    cmd=['ros2', 'lifecycle', 'set', '/map_server', 'activate'],
                    output='screen'
                )
            ]
        )
    )

    # RViz2
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen'
    )

    return LaunchDescription([
        flatland_server,
        static_transform_publisher,
        map_server_node,
        configure_map_push,
        rviz_node,
    ])
