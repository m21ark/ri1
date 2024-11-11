import pandas as pd

df = pd.read_csv("combined_output.csv")


robot1_data = df[df["robot"] == "robot1"].dropna(subset=["avg_distance_wall", "correct_percentage_distance_wall", "time_taken"])
robot2_data = df[df["robot"] == "robot2"].dropna(subset=["avg_distance_wall", "correct_percentage_distance_wall", "time_taken"])

# Defining a function to get the kd, kp pairs for max and min of each column
def get_max_min_pairs(data, variables):
    results = {}
    for variable in variables:
        max_idx = data[variable].idxmax()
        min_idx = data[variable].idxmin()
        results[variable] = {
            "max": {"kd": data.loc[max_idx, "kd"], "kp": data.loc[max_idx, "kp"], variable: data.loc[max_idx, variable]},
            "min": {"kd": data.loc[min_idx, "kd"], "kp": data.loc[min_idx, "kp"], variable: data.loc[min_idx, variable]}
        }
    return results

# Variables to analyze
variables = ["avg_distance_wall", "correct_percentage_distance_wall", "time_taken"]

# Getting the results for robot1 and robot2
robot1_results = get_max_min_pairs(robot1_data, variables)
robot2_results = get_max_min_pairs(robot2_data, variables)

print(robot1_results, robot2_results)