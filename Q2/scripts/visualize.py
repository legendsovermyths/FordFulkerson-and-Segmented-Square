import numpy as np
import os
import matplotlib.pyplot as plt

file_path1 = os.path.join(os.path.dirname(__file__), "../data/output.txt")
file_path2 = os.path.join(os.path.dirname(__file__), "../data/input.txt")
file_image = os.path.join(os.path.dirname(__file__), "../image/result.png")


def plot_least_segmented_square(
    points, slopes, intercepts, segment_starts, segment_ends
):
    # plot the input points
    x_coords, y_coords = zip(*points)
    plt.scatter(x_coords, y_coords)

    # plot the line segments
    for i in range(len(segment_starts)):
        start_idx = segment_starts[i]
        end_idx = segment_ends[i]
        start = points[start_idx]
        end = points[end_idx]
        slope = slopes[i]
        intercept = intercepts[i]
        xs = [start[0], end[0]]
        ys = [slope * start[0] + intercept, slope * end[0] + intercept]
        plt.plot(xs, ys, "r-")
        segment_points_str = ", ".join(str(p) for p in range(start_idx, end_idx + 1))
        plt.annotate(
            f"Segment {i+1}: Points {segment_points_str}",
            (start[0], start[1]),
            fontsize=10,
        )
    plt.savefig(file_image)
    plt.show()


points = []
slopes = []
intercept = []
startSegment = []
endSegment = []
with open(file_path2, "r") as f:
    n = int(f.readline())
    for i in range(n):
        line = f.readline()
        point = list(map(float, line.split(" ")))
        points.append((point[0], point[1]))
points.sort(key=lambda x: x[0])
with open(file_path1, "r") as f:
    n = int(f.readline())
    for i in range(n):
        line = f.readline()
        sm = list(map(float, line.split(" ")))
        slopes.append(sm[0])
        intercept.append(sm[1])
    for i in range(n):
        line = f.readline()
        se = list(map(int, line.split(" ")))
        startSegment.append(se[0] - 1)
        endSegment.append(se[1] - 1)


# plot the result
plot_least_segmented_square(points, slopes, intercept, startSegment, endSegment)
