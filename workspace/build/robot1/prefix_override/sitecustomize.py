import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/m/Desktop/S1/RI/proj1/workspace/install/robot1'
