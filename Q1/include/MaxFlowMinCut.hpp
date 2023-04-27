/**
 * @file MaxFlowMinCut.hpp
 * @brief Declaration of the MaxFlowMinCut class.
 */
#ifndef MaxFlowMinCut_HPP
#define MaxFlowMinCut_HPP
#include <iostream>
#include <queue>
#include <vector>
#include "FordFulkerson.hpp"
using namespace std;
/**
 * @class MaxFlowMinCut
 * @brief Class for computing the maximum flow and minimum cut in a graph using the Ford-Fulkerson algorithm.
 */
class MaxFlowMinCut {
  private:
    FordFulkerson *f; /**< Pointer to the Ford-Fulkerson object. */
    int nodes = 0;    /**< Number of nodes in the graph. */
    int source = -1;  /**< Source node in the graph. */

    /**
     * @brief Depth-first search function to find the nodes reachable from a given node.
     * @param i The current node being explored.
     * @param visited A reference to the vector storing the visited status of each node.
     * @param graph A reference to the graph representation.
     */
    void dfs(int i, vector<int> &visited, vector<vector<int>> &graph);

  public:
    /**
     * @brief Constructs a MaxFlowMinCut object with the given parameters.
     * @param n The number of nodes in the graph.
     * @param edges A vector of vectors representing the edges in the graph.
     * @param s The source node in the graph.
     * @param t The sink node in the graph.
     */
    MaxFlowMinCut(int n, vector<vector<int>> edges, int s, int t);

    /**
     * @brief Computes and returns the maximum flow in the graph.
     * @return The maximum flow in the graph.
     */
    int getMaxFlow();

    /**
     * @brief Computes and returns the minimum cut in the graph.
     * @return The minimum cut as a vector of vectors representing the edges of the cut.
     */
    vector<vector<int>> getMinCut();
};
#endif


