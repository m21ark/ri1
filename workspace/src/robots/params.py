import math

# Logging mode
LOG_MODE = True
STATISTIC_ANALYSIS = True
STOP_IF_COLLISION = False

RANDOM_START_POS = False 

# Robot 2 speficic parameters
SPEED_DIFF2 = 1.65 # 65% faster in both linear and angular speeds than robot 1
FOLLOW_DISTANCE = 3.5 # if robot 1 is at less than this distance, robot 2 will follow it

# Linear & Angular Max Speed
LIN_VEL_MAX = 0.8
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
