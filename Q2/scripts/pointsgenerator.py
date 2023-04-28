import random
import sys
import os

file_input = os.path.join(os.path.dirname(__file__), "../data/input.txt")


def generate_points(n):
    # generate a random slope and y-intercept for the line
    slope = random.uniform(-1, 1)
    intercept = random.uniform(-10, 10)

    # generate points with some deviation from the line
    points = []
    for i in range(n):
        x = random.uniform(-100, 100)
        y = slope * x + intercept + random.uniform(-10, 10)
        points.append((x, y))

    return points


# example usage: generate 10 points
points = generate_points(int(sys.argv[1]))
with open(file_input, "w") as f:
    f.write(sys.argv[1] + "\n")
    for x, y in points:
        f.write(f"{x} {y}\n")
    f.write(str(random.randint(0, 10000)))
print(sys.argv[1])
