WORKSPACE_DIR := $(shell pwd)
BUILD_DIR := $(WORKSPACE_DIR)/build
INSTALL_DIR := $(WORKSPACE_DIR)/install
LOG_DIR := $(WORKSPACE_DIR)/log

# Targets
all: build

build:
	@echo "Building the workspace..."
	colcon build --symlink-install
	@echo "Sourcing the workspace..."
	@echo "source $(INSTALL_DIR)/setup.bash"

launch:
	@echo "Launching both robots..."
	ros2 launch robot1 spawn_robots.launch.py

launch1:
	@echo "Launching robot1..."
	ros2 launch robot1 spawn_robot1.launch.py

launch2:
	@echo "Launching robot2..."
	ros2 launch robot2 spawn_robot2.launch.py

clean:
	@echo "Cleaning the build..."
	colcon clean

.PHONY: all build launch clean
