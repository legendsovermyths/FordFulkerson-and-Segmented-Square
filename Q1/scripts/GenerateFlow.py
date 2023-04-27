import numpy as np
import os
import sys
from collections import deque

file_test = os.path.join(
    os.path.dirname(__file__), "../tests/test" + sys.argv[1] + ".txt"
)
file_input = os.path.join(os.path.dirname(__file__), "../data/input.txt")
file_res = os.path.join(os.path.dirname(__file__), "../data/res.txt")


def generate_graph(n, max_capacity):
    """
    Generate a random graph with n nodes and random capacities up to max_capacity.
    """
    graph = np.zeros((n, n))
    for i in range(n):
        for j in range(i + 1, n):
            graph[i][j] = np.random.randint(0, max_capacity)
            graph[j][i] = 0
    return graph


def write_graph_to_file(graph, filename):
    """
    Write the graph as a list of edges and their capacities to a file.
    """
    n = len(graph)
    edges = 0
    for i in range(n):
        for j in range(i + 1, n):
            if graph[i][j] > 0:
                edges += 1
    with open(file_test, "w") as f:
        f.write(f"{edges}\n")
        for i in range(n):
            for j in range(i + 1, n):
                if graph[i][j] > 0:
                    f.write(f"{i+1} {j+1} {int(graph[i][j])}\n")
    with open(filename, "w") as f:
        f.write(f"{edges}\n")
        for i in range(n):
            for j in range(i + 1, n):
                if graph[i][j] > 0:
                    f.write(f"{i+1} {j+1} {int(graph[i][j])}\n")


class Graph:
    def __init__(self, graph):
        self.graph = graph  # residual graph
        self.ROW = len(graph)
        # self.COL = len(gr[0])

    """Returns true if there is a path from source 's' to sink 't' in
    residual graph. Also fills parent[] to store the path """

    def BFS(self, s, t, parent):
        # Mark all the vertices as not visited
        visited = [False] * (self.ROW)

        # Create a queue for BFS
        queue = []

        # Mark the source node as visited and enqueue it
        queue.append(s)
        visited[s] = True

        # Standard BFS Loop
        while queue:
            # Dequeue a vertex from queue and print it
            u = queue.pop(0)

            # Get all adjacent vertices of the dequeued vertex u
            # If a adjacent has not been visited, then mark it
            # visited and enqueue it
            for ind, val in enumerate(self.graph[u]):
                if visited[ind] == False and val > 0:
                    # If we find a connection to the sink node,
                    # then there is no point in BFS anymore
                    # We just have to set its parent and can return true
                    queue.append(ind)
                    visited[ind] = True
                    parent[ind] = u
                    if ind == t:
                        return True

        # We didn't reach sink in BFS starting
        # from source, so return false
        return False

    # Returns the maximum flow from s to t in the given graph
    def FordFulkerson(self, source, sink):
        # This array is filled by BFS and to store path
        parent = [-1] * (self.ROW)

        max_flow = 0  # There is no flow initially

        # Augment the flow while there is path from source to sink
        while self.BFS(source, sink, parent):
            # Find minimum residual capacity of the edges along the
            # path filled by BFS. Or we can say find the maximum flow
            # through the path found.
            path_flow = float("Inf")
            s = sink
            while s != source:
                path_flow = min(path_flow, self.graph[parent[s]][s])
                s = parent[s]

            # Add path flow to overall flow
            max_flow += path_flow

            # update residual capacities of the edges and reverse edges
            # along the path
            v = sink
            while v != source:
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = parent[v]

        return max_flow


# Generate a random graph and write it to a file
graph = generate_graph(int(sys.argv[1]), 100)
write_graph_to_file(graph, file_input)
g = Graph(graph)
# Compute the maximum flow using the Ford-Fulkerson algorithm and print it
source = 0
sink = int(sys.argv[1]) - 1
max_flow = g.FordFulkerson(source, sink)
print(f"{int(max_flow)}")
