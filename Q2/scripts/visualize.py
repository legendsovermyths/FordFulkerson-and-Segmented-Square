import numpy as np
import matplotlib.pyplot as plt


def plot_least_segmented_square(points, slopes, intercepts, segment_starts, segment_ends):
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
        ys = [slope*start[0] + intercept, slope*end[0] + intercept]
        plt.plot(xs, ys, 'r-')
        segment_points_str = ', '.join(str(p)
                                       for p in range(start_idx, end_idx+1))
        plt.annotate(
            f"Segment {i+1}: Points {segment_points_str}", (start[0], start[1]), fontsize=10)

    plt.show()


# sample data
points = [(1.1, 1), (2, 2.1), (3.1, 3), (4, 4.1), (5.1, 4.9),
          (6.2, 6.3), (6.8, 7.1), (11.2, 10.9), (15, 17), (16, 18), (19, 21)]
cost = 1

# run least segmented square algorithm
slopes = [1, 1]
intercept = [0, 2.1]
startSegment = [0, 8]
endSegment = [7, 10]
plot_least_segmented_square(
    points, slopes, intercept, startSegment, endSegment)

# plot the result
