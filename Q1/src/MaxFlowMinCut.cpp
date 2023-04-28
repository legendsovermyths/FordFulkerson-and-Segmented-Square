/**
 * @file MaxFlowMinCut.cpp
 * @brief Implementation of the MaxFlowMinCut class methods.
 */
#include "../include/MaxFlowMinCut.hpp"

/**
 * @brief Constructs a MaxFlowMinCut object with the specified number of nodes, edges, source, and target.
 *
 * @param n The number of nodes in the graph.
 * @param edges The edges of the graph represented as an adjacency matrix.
 * @param s The source node.
 * @param t The target node.
 */
MaxFlowMinCut::MaxFlowMinCut(int n, vector<vector<int>> edges, int s, int t)
{
    nodes = n;
    source = s;
    f = new FordFulkerson(n, edges, s, t);
}

/**
 * @brief Performs a depth-first search to mark nodes as visited in the given graph.
 *
 * @param i The current node being visited.
 * @param visited A vector to keep track of visited nodes.
 * @param graph The graph represented as an adjacency matrix.
 */
void MaxFlowMinCut::dfs(int i, vector<int> &visited, vector<vector<int>> &graph)
{
    visited[i] = 1;
    int sz = graph[i].size();
    for (int j = 0; j < sz; j++)
    {
        if (graph[i][j] > 0 && !visited[j])
        {
            dfs(j, visited, graph);
        }
    }
}

/**
 * @brief Computes and returns the maximum flow in the graph.
 *
 * @return The maximum flow in the graph.
 */
int MaxFlowMinCut::getMaxFlow()
{
    int maxFlow = f->getMaxFlow();
    return maxFlow;
}

/**
 * @brief Computes and returns the minimum cut in the graph.
 *
 * The minimum cut is represented by a vector of two sets of nodes: the nodes on one side of the cut and
 * the nodes on the other side of the cut.
 *
 * @return The minimum cut in the graph.
 */
vector<vector<int>> MaxFlowMinCut::getMinCut()
{
    vector<vector<int>> graph = f->getresidualgraph();
    vector<vector<int>> cut(2);
    vector<int> visited(nodes + 1, 0);
    dfs(source, visited, graph);

    for (int i = 1; i <= nodes; i++)
    {
        if (visited[i] == 1)
        {
            cut[0].push_back(i);
        }
        else
        {
            cut[1].push_back(i);
        }
    }

    return cut;
}