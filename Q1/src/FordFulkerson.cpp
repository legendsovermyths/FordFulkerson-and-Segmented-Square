/**
 * @file FordFulkerson.cpp
 * @brief Implementation of the FordFulkerson class methods.
 */
#include "../include/FordFulkerson.hpp"

/**
 * @brief Constructs a FordFulkerson object with the given parameters.
 *
 * @param n The number of nodes in the graph.
 * @param arr A vector of vectors representing the graph's adjacency matrix.
 * @param s The source node.
 * @param t The sink node.
 */
FordFulkerson::FordFulkerson(int n, vector<vector<int>> arr, int s, int t) {
    nodes = n;
    source = s;
    dest = t;
    graph = vector<vector<int>>(nodes + 1, vector<int>(nodes + 1, 0));
    residualGraph = vector<vector<int>>(nodes + 1, vector<int>(nodes + 1, 0));
    for (int i = 0; i < arr.size(); i++) {
        graph[arr[i][0]][arr[i][1]] = arr[i][2];
        residualGraph[arr[i][0]][arr[i][1]] = arr[i][2];
    }
}

/**
 * @brief Constructs a FordFulkerson object with the given adjacency matrix.
 * The source node is set to 0 and the sink node is set to nodes - 1.
 *
 * @param arr A vector of vectors representing the graph's adjacency matrix.
 */
FordFulkerson::FordFulkerson(vector<vector<int>> arr) {
    nodes = arr.size();
    source = 0;
    dest = nodes - 1;
    graph = arr;
    residualGraph = arr;
}

/**
 * @brief Performs depth-first search (DFS) on the residual graph to find an augmenting path.
 *
 * @param s The current node being visited.
 * @param t The sink node.
 * @param parent A reference to the vector storing the parent node for each node in the path.
 * @param threshold The minimum capacity required for an edge to be traversed.
 * @param visited A reference to the vector indicating whether a node has been visited.
 * @return True if an augmenting path is found, false otherwise.
 */
bool FordFulkerson::dfs(int s, int t, vector<int> &parent, int threshold, vector<int> &visited) {
    visited[s] = 1;
    if (s == t) {
        return true;
    }
    bool rvalue = false;
    visited[s] = 1;
    for (int j = 0; j < residualGraph[s].size(); j++) {
        if (residualGraph[s][j] >= threshold && !visited[j]) {
            parent[j] = s;
            rvalue |= dfs(j, t, parent, threshold, visited);
        }
    }
    return rvalue;
}

/**
 * @brief Solves the maximum flow problem using the Ford-Fulkerson algorithm and returns the maximum flow value.
 *
 * @return The maximum flow value in the graph.
 */
int FordFulkerson::getMaxFlow() {
    if (solved == 0)
        solve();
    int flow = this->maxFlow;
    return flow;
}

/**
 * @brief Retrieves the residual graph after solving the maximum flow problem.
 *
 * @return A vector of vectors representing the residual graph's adjacency matrix.
 */
vector<vector<int>> FordFulkerson::getresidualgraph() {
    if (solved == 0)
        solve();
    vector<vector<int>> res = this->residualGraph;
    return res;
}

/**
 * @brief Solves the maximum flow problem using the Ford-Fulkerson algorithm.
 * The result is stored in the object's member variables.
 */
void FordFulkerson::solve() {
    solved = 1;
    vector<int> parent(nodes + 1, 0);
    vector<int> visited(nodes + 1, 0);
    int maxFlow = 0;
    int threshold = MAX;

    while (threshold > 0) {
        parent = vector<int>(nodes + 1, 0);
        visited = vector<int>(nodes + 1, 0);

        while (dfs(source, dest, parent, threshold, visited)) {
            int flow = threshold;
            int u = dest;
            int v;

            v = dest;
            while (v != source) {
                u = parent[v];
                residualGraph[u][v] -= flow;
                residualGraph[v][u] += flow;
                v = parent[v];
            }
            maxFlow += flow;

            parent = vector<int>(nodes + 1, 0);
            visited = vector<int>(nodes + 1, 0);
        }

        threshold /= 2;
    }

    this->maxFlow = maxFlow;
}
