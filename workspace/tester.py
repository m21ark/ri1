import subprocess
import time
from math import pi
import itertools
import os
import signal
import pandas as pd
from robots.statistics import extract_data

lin_vel_max_values = [1.8, 2.0]
ang_vel_max_values = [pi / 3, 2 * pi / 3, pi]
ideal_distance_values = [1.5, 1.6, 1.7, 1.8]
ideal_distance_tolerance_values = [0.2, 0.3, 0.4, 0.5]

# Generate all combinations of parameters
param_combinations = list(itertools.product(
    lin_vel_max_values, ang_vel_max_values,
    ideal_distance_values, ideal_distance_tolerance_values
))

def update_params_file(lin_vel_max, ang_vel_max, ideal_distance, ideal_distance_tolerance):
    with open("src/robots/params.py", "a") as file:  
              
        # Update the lines with the new parameter values
        file.write(f"LIN_VEL_MAX = {lin_vel_max}\n")
        file.write(f"ANG_VEL_MAX = {ang_vel_max}\n")
        file.write(f"IDEAL_DISTANCE = {ideal_distance}\n")
        file.write(f"IDEAL_DISTANCE_TOLERANCE = {ideal_distance_tolerance}\n\n")
        file.close()

def run_simulation():
    # Start Terminal 1 command for map launch in a new session
    process1 = subprocess.Popen(
        "source ~/.bashrc && colcon build && source ~/.bashrc && ros2 launch robots map.launch.py",
        shell=True,
        executable="/bin/bash",
        preexec_fn=os.setsid  # Start the process in a new session
    )

    time.sleep(10)  # Wait for the map to load

    # Start Terminal 2 command for episode and statistics
    process2 = subprocess.run(
        "ros2 launch robots episode.launch.py",
        shell=True,
        executable="/bin/bash"
    )

    # After process2 finishes, terminate the entire process group of process1
    if process2.returncode == 0:
        os.killpg(os.getpgid(process1.pid), signal.SIGTERM)  # Send SIGTERM to all processes in the group
        time.sleep(10)  # Allow time for everything to shut down

def store_simulation_results(df, lin_vel_max, ang_vel_max, ideal_distance, ideal_distance_tolerance):
    robot1_data = extract_data('logs/log_move1.txt')
    robot2_data = extract_data('logs/log_move2.txt')
    
    r1 = robot1_data['num_collisions'], robot1_data['avg_velocity'], robot1_data['avg_distance_wall'], robot1_data['correct_percentage_distance_wall'], robot1_data['time_taken']
    r2 = robot2_data['num_collisions'], robot2_data['avg_velocity'], robot2_data['avg_distance_wall'], robot2_data['correct_percentage_distance_wall'], robot2_data['time_taken']
    

    # Append the results to the dataframe
    df.loc[len(df)] = ['robot1', lin_vel_max, ang_vel_max, ideal_distance, ideal_distance_tolerance, *r1]
    df.loc[len(df)] = ['robot2', lin_vel_max, ang_vel_max, ideal_distance, ideal_distance_tolerance, *r2]
    
def main():
    
    print(f"Total number of combinations: {len(param_combinations)}")    
    conf = input("Do you want to continue? (y/n): ")
    if conf != 'y':
        return
    
    # create a new dataframe
    df = pd.DataFrame(columns=['robot', 'lin_vel_max', 'ang_vel_max', 'ideal_distance', 'ideal_distance_tolerance', 'num_collisions', 'avg_velocity', 'avg_distance_wall', 'correct_percentage_distance_wall', 'time_taken'])
    
    # Iterate over each combination
    for params in param_combinations:
        lin_vel_max, ang_vel_max, ideal_distance, ideal_distance_tolerance = params
        
        # Update the params file with the new parameter values
        update_params_file(lin_vel_max, ang_vel_max, ideal_distance, ideal_distance_tolerance)
        
        # Run the simulation
        print(f"Running simulation with parameters: {params}")
        run_simulation()
        print("Episode is done. Storing the results...")
        store_simulation_results(df, lin_vel_max, ang_vel_max, ideal_distance, ideal_distance_tolerance)
        df.to_csv('logs/simulation_results.csv', index=False)
        print("Simulation completed.")
        
if __name__ == "__main__":
    main()