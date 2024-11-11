import pandas as pd

# List of CSV file paths
csv_files = ["1.csv", "2.csv", "3.csv"]

# Read and combine CSV files
combined_csv = pd.concat([pd.read_csv(file) for file in csv_files])

# Reset index if needed (optional)
combined_csv.reset_index(drop=True, inplace=True)

# Save the combined DataFrame to a new CSV file
combined_csv.to_csv("combined_output.csv", index=False)

print("CSV files have been successfully merged into 'combined_output.csv'")

