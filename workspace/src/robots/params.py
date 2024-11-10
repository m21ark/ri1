import math

# Logging mode
LOG_MODE = True
STATISTIC_ANALYSIS = True
STOP_IF_COLLISION = True

RANDOM_START_POS = False

# PD Controller Constants
BASIC_CONTROLLER_1 = False 
BASIC_CONTROLLER_2 = False
Kp = 1  # Proportional gain (higher value makes the robot follow the wall more closely, but can lead to oscillations)
Kd = 1 # Derivative gain (higher value makes the robot follow the wall more smoothly, but can lead to overshooting)

# Robot 2 speficic parameters
SPEED_DIFF2 = 1.65 # 65% faster in both linear and angular speeds than robot 1
FOLLOW_DISTANCE = 3.5 # if robot 1 is at less than this distance, robot 2 will follow it

# Linear & Angular Max Speed
LIN_VEL_MAX = 1.75
ANG_VEL_MAX = 2 * math.pi / 3

# Distance to wall
IDEAL_DISTANCE = 1.75
IDEAL_DISTANCE_TOLERANCE = 0.45

# Finish point radius
FINISH_DISTANCE_RANGE = 1.5

def log(msg: str):
        if LOG_MODE:
            print(msg)
            
# Clamp functions

def clampInterval(value, min_val, max_val):
    return max(min_val, min(value, max_val))

def clamp(value, max_val):
    return clampInterval(value, -max_val, max_val) 
KD = 0.1
KP = 0.1
KD = 0.1
KP = 0.1
KD = 0.1
KP = 0.1
KD = 0.1
KP = 0.1
KD = 0.1
KP = 3
KD = 3
KP = 0.1
KD = 3
KP = 3
KD = 0.1
KP = 0.1
KD = 0.1
KP = 0.32499999999999996
KD = 0.1
KP = 0.5499999999999999
KD = 0.1
KP = 0.7749999999999999
KD = 0.1
KP = 0.9999999999999999
KD = 0.1
KP = 1.225
KD = 0.1
KP = 1.45
KD = 0.1
KP = 1.6749999999999998
KD = 0.1
KP = 1.9
KD = 0.32499999999999996
KP = 0.1
KD = 0.32499999999999996
KP = 0.32499999999999996
KD = 0.32499999999999996
KP = 0.5499999999999999
KD = 0.32499999999999996
KP = 0.7749999999999999
KD = 0.32499999999999996
KP = 0.9999999999999999
KD = 0.32499999999999996
KP = 1.225
KD = 0.32499999999999996
KP = 1.45
KD = 0.32499999999999996
KP = 1.6749999999999998
KD = 0.32499999999999996
KP = 1.9
KD = 0.5499999999999999
KP = 0.1
KD = 0.5499999999999999
KP = 0.32499999999999996
KD = 0.5499999999999999
KP = 0.5499999999999999
KD = 0.5499999999999999
KP = 0.7749999999999999
KD = 0.5499999999999999
KP = 0.9999999999999999
KD = 0.5499999999999999
KP = 1.225
KD = 0.5499999999999999
KP = 1.45
KD = 0.5499999999999999
KP = 1.6749999999999998
KD = 0.5499999999999999
KP = 1.9
KD = 0.7749999999999999
KP = 0.1
KD = 0.7749999999999999
KP = 0.32499999999999996
KD = 0.7749999999999999
KP = 0.5499999999999999
KD = 0.7749999999999999
KP = 0.7749999999999999
KD = 0.7749999999999999
KP = 0.9999999999999999
KD = 0.7749999999999999
KP = 1.225
KD = 0.7749999999999999
KP = 1.45
KD = 0.7749999999999999
KP = 1.6749999999999998
KD = 0.7749999999999999
KP = 1.9
KD = 0.9999999999999999
KP = 0.1
KD = 0.9999999999999999
KP = 0.32499999999999996
KD = 0.9999999999999999
KP = 0.5499999999999999
KD = 0.9999999999999999
KP = 0.7749999999999999
KD = 0.9999999999999999
KP = 0.9999999999999999
KD = 0.9999999999999999
KP = 1.225
KD = 0.9999999999999999
KP = 1.45
KD = 0.9999999999999999
KP = 1.6749999999999998
KD = 0.9999999999999999
KP = 1.9
KD = 1.225
KP = 0.1
KD = 1.225
KP = 0.32499999999999996
KD = 1.225
KP = 0.5499999999999999
KD = 1.225
KP = 0.7749999999999999
KD = 1.225
KP = 0.9999999999999999
KD = 1.225
KP = 1.225
KD = 1.225
KP = 1.45
KD = 1.225
KP = 1.6749999999999998
KD = 1.225
KP = 1.9
KD = 1.45
KP = 0.1
KD = 1.45
KP = 0.32499999999999996
KD = 1.45
KP = 0.5499999999999999
KD = 1.45
KP = 0.7749999999999999
KD = 1.45
KP = 0.9999999999999999
KD = 1.45
KP = 1.225
KD = 1.45
KP = 1.45
KD = 1.45
KP = 1.6749999999999998
KD = 1.45
KP = 1.9
KD = 1.6749999999999998
KP = 0.1
KD = 1.6749999999999998
KP = 0.32499999999999996
KD = 1.6749999999999998
KP = 0.5499999999999999
KD = 1.6749999999999998
KP = 0.7749999999999999
KD = 1.6749999999999998
KP = 0.9999999999999999
KD = 1.6749999999999998
KP = 1.225
KD = 1.6749999999999998
KP = 1.45
KD = 1.6749999999999998
KP = 1.6749999999999998
KD = 1.6749999999999998
KP = 1.9
KD = 1.9
KP = 0.1
KD = 1.9
KP = 0.32499999999999996
KD = 1.9
KP = 0.5499999999999999
KD = 1.9
KP = 0.7749999999999999
KD = 1.9
KP = 0.9999999999999999
KD = 1.9
KP = 1.225
KD = 1.9
KP = 1.45
KD = 1.9
KP = 1.6749999999999998
KD = 1.9
KP = 1.9
Kd = 0.1
Kp = 0.1
Kd = 0.1
Kp = 0.32499999999999996
Kd = 0.1
Kp = 0.5499999999999999
Kd = 0.1
Kp = 0.7749999999999999
Kd = 0.1
Kp = 0.9999999999999999
Kd = 0.1
Kp = 1.225
Kd = 0.1
Kp = 1.45
Kd = 0.1
Kp = 1.6749999999999998
Kd = 0.1
Kp = 1.9
Kd = 0.32499999999999996
Kp = 0.1
Kd = 0.32499999999999996
Kp = 0.32499999999999996
Kd = 0.32499999999999996
Kp = 0.5499999999999999
Kd = 0.32499999999999996
Kp = 0.7749999999999999
Kd = 0.32499999999999996
Kp = 0.9999999999999999
Kd = 0.32499999999999996
Kp = 1.225
Kd = 0.32499999999999996
Kp = 1.45
Kd = 0.32499999999999996
Kp = 1.6749999999999998
Kd = 0.32499999999999996
Kp = 1.9
Kd = 0.5499999999999999
Kp = 0.1
Kd = 0.5499999999999999
Kp = 0.32499999999999996
Kd = 0.5499999999999999
Kp = 0.5499999999999999
Kd = 0.5499999999999999
Kp = 0.7749999999999999
Kd = 0.5499999999999999
Kp = 0.9999999999999999
Kd = 0.5499999999999999
Kp = 1.225
Kd = 0.5499999999999999
Kp = 1.45
Kd = 0.5499999999999999
Kp = 1.6749999999999998
Kd = 0.5499999999999999
Kp = 1.9
Kd = 0.7749999999999999
Kp = 0.1
Kd = 0.7749999999999999
Kp = 0.32499999999999996
Kd = 0.7749999999999999
Kp = 0.5499999999999999
Kd = 0.7749999999999999
Kp = 0.7749999999999999
Kd = 0.7749999999999999
Kp = 0.9999999999999999
Kd = 0.7749999999999999
Kp = 1.225
Kd = 0.7749999999999999
Kp = 1.45
Kd = 0.7749999999999999
Kp = 1.6749999999999998
Kd = 0.7749999999999999
Kp = 1.9
Kd = 0.9999999999999999
Kp = 0.1
Kd = 0.9999999999999999
Kp = 0.32499999999999996
Kd = 0.9999999999999999
Kp = 0.5499999999999999
Kd = 0.9999999999999999
Kp = 0.7749999999999999
Kd = 0.9999999999999999
Kp = 0.9999999999999999
Kd = 0.9999999999999999
Kp = 1.225
Kd = 0.9999999999999999
Kp = 1.45
Kd = 0.9999999999999999
Kp = 1.6749999999999998
Kd = 0.9999999999999999
Kp = 1.9
Kd = 1.225
Kp = 0.1
Kd = 1.225
Kp = 0.32499999999999996
Kd = 1.225
Kp = 0.5499999999999999
Kd = 1.225
Kp = 0.7749999999999999
Kd = 1.225
Kp = 0.9999999999999999
Kd = 1.225
Kp = 1.225
Kd = 1.225
Kp = 1.45
Kd = 1.225
Kp = 1.6749999999999998
Kd = 1.225
Kp = 1.9
Kd = 1.45
Kp = 0.1
Kd = 1.45
Kp = 0.32499999999999996
Kd = 1.45
Kp = 0.5499999999999999
Kd = 1.45
Kp = 0.7749999999999999
Kd = 1.45
Kp = 0.9999999999999999
Kd = 1.45
Kp = 1.225
Kd = 1.45
Kp = 1.45
Kd = 1.45
Kp = 1.6749999999999998
Kd = 1.45
Kp = 1.9
Kd = 1.6749999999999998
Kp = 0.1
Kd = 1.6749999999999998
Kp = 0.32499999999999996
Kd = 1.6749999999999998
Kp = 0.5499999999999999
Kd = 1.6749999999999998
Kp = 0.7749999999999999
Kd = 1.6749999999999998
Kp = 0.9999999999999999
Kd = 1.6749999999999998
Kp = 1.225
Kd = 1.6749999999999998
Kp = 1.45
Kd = 1.6749999999999998
Kp = 1.6749999999999998
Kd = 1.6749999999999998
Kp = 1.9
Kd = 1.9
Kp = 0.1
Kd = 1.9
Kp = 0.32499999999999996
Kd = 1.9
Kp = 0.5499999999999999
Kd = 1.9
Kp = 0.7749999999999999
Kd = 1.9
Kp = 0.9999999999999999
Kd = 1.9
Kp = 1.225
Kd = 1.9
Kp = 1.45
Kd = 1.9
Kp = 1.6749999999999998
Kd = 1.9
Kp = 1.9
