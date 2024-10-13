## Execute Command

> ros2 launch robots map.launch.py

### To move robots

> ros2 run robots move1
> ros2 run robots move2

### Alternative Manual Way

Terminal 1:

> ros2 launch flatland_server server.launch world_path:=world/world.yaml

Terminal 2:

> ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 1 map world

Terminal 3:

> ros2 run nav2_map_server map_server --ros-args -p yaml_filename:=world/map.yaml

Terminal 4:

> ros2 lifecycle set /map_server configure
> ros2 lifecycle set /map_server activate

Terminal 5:

> ros2 run rviz2 rviz2
