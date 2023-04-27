import pandas as pd
import matplotlib.pyplot as plt
import os

# Read in the CSV file
file_result = os.path.join(os.path.dirname(__file__), "../data/results.csv")
file_result_image = os.path.join(os.path.dirname(__file__), "../image/results.png")
df = pd.read_csv(file_result)

# Extract the test number and time columns

df["test"] = df["test"].str[4:]
df["test"] = pd.to_numeric(df["test"])
test_number = df["test"]
time = df["time(microseconds)"]
print(test_number)
# Create a scatter plot with test number on the x-axis and time on the y-axis
plt.scatter(test_number, time)

# Set the axis labels and title
plt.xlabel("Test Size")
plt.ylabel("Time(in microsec)")
plt.title("Test Results")
plt.savefig(file_result_image)

# Display the plot
plt.show()
