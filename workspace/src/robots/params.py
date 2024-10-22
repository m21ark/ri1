import math

# Logging mode
LOG_MODE = True
STATISTIC_ANALYSIS = True

# Robot 2 speficic parameters
SPEED_DIFF2 = 2 # 100% faster in both linear and angular speeds than robot 1
FOLLOW_DISTANCE = 4 # if robot 1 is at less than this distance, robot 2 will follow it

# Linear Speed
LIN_VEL_MAX = 2
LIN_ACC_MAX = 1

# Angular Speed
ANG_VEL_MAX = 2 * math.pi / 3
ANG_ACC_MAX = math.pi / 3

# Distance to wall
IDEAL_DISTANCE = 1.75
IDEAL_DISTANCE_TOLERANCE = 0.3
FRONT_CRITICAL_DISTANCE = IDEAL_DISTANCE - 2 * IDEAL_DISTANCE_TOLERANCE
FRONT_SLOWDOWN_DISTANCE = IDEAL_DISTANCE - IDEAL_DISTANCE_TOLERANCE

MAX_LINEAR_ACC = 2
IDEAL_VEL = 1.5

FINISH_DISTANCE_RANGE = 2

def log(msg: str):
        if LOG_MODE:
            print(msg)
            
# Clamp function

def clampInterval(value, min_val, max_val):
    return max(min_val, min(value, max_val))

def clamp(value, max_val):
    return clampInterval(value, -max_val, max_val) 