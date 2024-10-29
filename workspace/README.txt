# RI Assignment 1

This project was developed for our Intelligent Robotics course at FEUP.

The goal was to develop two simple reactive robots in a map with a tilde-shaped wall so that:

- R1 follows wall slowly
- R2 follows wall or R1 (whichever is closest)

## Requirements

The project was done using `ROS 2 Humble` with `Flatland` and `Rviz` for simulation and visualization. The programming was done in `Python 3.10.12`.

After much troubleshooting, the team found that `ROS 2` is very sensible to python package versions, being the most critical one setuptools which should be specifically set to `65.0.0`.

## Directory Structure

The workspace folder is where the project is located and should contain the following directories:

> **flatland/** Contains the source code for the currently compatible version for `ROS 2 Humble`
> **src/** Contains a single ROS package named `robots` where the python scripts reside
> **world/** Contains YAML configuration files for both the robots and the world map

### Parametrization

The robot control scripts are parameterized in a Python file, `workspace/src/robots/params.py`, with global variables that can be tweaked.

#### Logging

In the parameters configuration there is a variable `STATISTIC_ANALYSIS = False` which can be changed to collect robot metrics. They are stored on a directory `logs/` that will be created. 

## How to Compile and Execute

Please execute the following commands in the workspace folder.

### Build

> colcon build

**Note:** The `colcon build` command may fail on the first attempt due to C++ dependencies, but running it again usually resolves the issue.

> source install/setup.bash

### Execution

To start the Flatland+Rviz simulation window:

> ros2 launch robots map.launch.py

Then, you can choose to move both robots and run an episode:

> ros2 launch robots episode.launch.py

Alternatively, you can move each robot independently:

> ros2 run robots move1
> ros2 run robots move2

#### Collecting Statistics

To compress collected statistics into a single PNG:

> ros2 run robots statistics

The result PNG can be found in the `logs/` directory.

