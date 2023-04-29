import numpy as np
import random
import os

file_input = os.path.join(os.path.dirname(__file__), "../data/input.txt")


def generate_bipartite_graph(num_left_nodes, num_right_nodes, edge_probability):
    # Generate left and right nodes
    left_nodes = range(num_left_nodes)
    right_nodes = range(num_left_nodes, num_left_nodes + num_right_nodes)

    # Generate edges
    edges = [
        (i, j)
        for i in left_nodes
        for j in right_nodes
        if random.random() < edge_probability
    ]
    with open(file_input, "w") as f:
        f.write(str(len(edges)) + "\n")
        for x, y in edges:
            f.write(f"{x+1} {y+1}\n")


generate_bipartite_graph(100, 112, 0.6)
