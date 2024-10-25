# How to Run Project

Please execute the below present commands in the workspace folder.

## Build

> colcon build (This command might fail the 1st time due to dependencies)
> source install/setup.bash

## Execute Command

> ros2 launch robots map.launch.py

### To move robots independently

> ros2 run robots move1
> ros2 run robots move2

### To Run an episode with both robots moving

> ros2 run robots episode

## For statistic map

> ros2 run robots statistics

Result PNG can be found in 'logs/' directory.