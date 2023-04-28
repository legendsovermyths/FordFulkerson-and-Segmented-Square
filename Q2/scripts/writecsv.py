import os
import sys
import csv

file_csv = os.path.join(os.path.dirname(__file__), "../data/results.csv")
file_time = os.path.join(os.path.dirname(__file__), "../data/time.txt")

t = ""
with open(file_time, "r") as f:
    t = f.readline()

with open(file_csv, mode="a", newline="") as file:
    writer = csv.writer(file)
    data = ["test" + sys.argv[1], int(t)]
    writer.writerow(data)
