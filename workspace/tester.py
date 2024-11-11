import subprocess
import time
from math import pi
import itertools
import os
import signal
import pandas as pd
import numpy as np
from robots.statistics import extract_data

kd_min, kd_max = 0.1, 1.9
kp_min, kp_max = 2.12, 3.92

step = 0.20

def generate_values(min_val, max_val, step):
    num_steps = int((max_val - min_val) / step) + 1  # Calculate the number of points
    return np.linspace(min_val, max_val, num_steps).tolist()

kd = generate_values(kd_min, kd_max, step)
kp = generate_values(kp_min, kp_max, step)


# Generate all combinations of parameters
param_combinations = list(itertools.product(
    kd, kp
))

def update_params_file(kd, kp):
    with open("src/robots/params.py", "a") as file:  
              
        # Update the lines with the new parameter values
        file.write(f"Kd = {kd}\n")
        file.write(f"Kp = {kp}\n")
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

    try:
        # Start Terminal 2 command for episode and statistics with a timeout
        process2 = subprocess.run(
            "ros2 launch robots episode.launch.py",
            shell=True,
            executable="/bin/bash",
            timeout=120  # Set timeout to 2 minutes (120 seconds)
        )

        # Check if process2 finished successfully
        if process2.returncode == 0:
            print("Simulation completed successfully within 2 minutes.")

    except subprocess.TimeoutExpired:
        print("Simulation exceeded 2 minutes. Terminating processes...")
        # Terminate the entire process group of process1 if timeout is reached
        os.killpg(os.getpgid(process1.pid), signal.SIGTERM)
        time.sleep(10)  # Allow time for everything to shut down

    finally:
        # Make sure process1 is terminated if still running
        if process1.poll() is None:
            os.killpg(os.getpgid(process1.pid), signal.SIGTERM)

def store_simulation_results(df, kd, kp):
    robot1_data = extract_data('logs/log_move1.txt')
    robot2_data = extract_data('logs/log_move2.txt')
    
    r1 = robot1_data['avg_distance_wall'], robot1_data['correct_percentage_distance_wall'], robot1_data['time_taken']
    r2 = robot2_data['avg_distance_wall'], robot2_data['correct_percentage_distance_wall'], robot2_data['time_taken']
    
    # Append the results to the dataframe
    df.loc[len(df)] = ['robot1', kd, kp, *r1]
    df.loc[len(df)] = ['robot2', kd, kp, *r2]
    
def main():
    
    print(f"Total number of combinations: {len(param_combinations)}")    
    conf = input("Do you want to continue? (y/n): ")
    if conf != 'y':
        return
    
    # create a new dataframe
    df = pd.DataFrame(columns=['robot', 'kd', 'kp', 'avg_distance_wall', 'correct_percentage_distance_wall', 'time_taken'])
    
    # Iterate over each combination
    for params in param_combinations:
        kd, kp = params
        
        # Update the params file with the new parameter values
        update_params_file(kd, kp)
        
        # Run the simulation
        print(f"Running simulation with parameters: {params}")
        
        # RUBEN: ADICIONAR UM BREAK DA SIMULACAO CASO CORRA HA MAIS DE 2MIN POR EX.
        run_simulation()
        print("Episode is done. Storing the results...")
        store_simulation_results(df, kd, kp)
        df.to_csv('logs/simulation_results.csv', index=False)
        print("Simulation completed.")
        
    
        
if __name__ == "__main__":
    main()
