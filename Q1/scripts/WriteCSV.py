import os
import sys
import csv

file_output1 = os.path.join(os.path.dirname(__file__), "../bin/output1.txt")
file_output2 = os.path.join(os.path.dirname(__file__), "../bin/output2.txt")
file_time = os.path.join(os.path.dirname(__file__), "../data/time.txt")
file_csv = os.path.join(os.path.dirname(__file__), "../data/results.csv")
a1 = "1"
a1 = "2"
t = ""
data = []
with open(file_output1, "r") as f:
    a1 = f.readline()
with open(file_output1, "r") as f:
    a2 = f.readline()
with open(file_time, "r") as f:
    t = f.readline()
with open(file_csv, mode="a", newline="") as file:
    writer = csv.writer(file)
    if a1 == a2:
        print("Accepted")
        data = ["test" + sys.argv[1], "Accept", int(t)]
    else:
        print("Rejected")
        data = ["test" + sys.argv[1], "Reject", int(t)]
    writer.writerow(data)
print("Data appended to the file successfully.")
