/**
 * @file FordFulkerson.hpp
 * @brief Declaration of the FordFulkerson class.
 */
#ifndef FordFulkerson_HPP
#define FordFulkerson_HPP
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1073741824
/**
 * @class FordFulkerson
 * @brief Class for solving the maximum flow problem using the Ford-Fulkerson algorithm.
 */
class FordFulkerson {
  private:
    int nodes;                         /**< Number of nodes in the graph. */
    vector<vector<int>> graph;         /**< Adjacency matrix representation of the graph. */
    vector<vector<int>> residualGraph; /**< Residual graph after augmenting paths. */
    int source;                        /**< Source node of the graph. */
    int dest;                          /**< Destination node of the graph. */
    int solved = 0;                    /**< Flag to indicate whether the problem has been solved. */
    int maxFlow = 0;                   /**< Maximum flow value. */

    /**
     * @brief Depth-first search function to find augmenting paths in the graph.
     * @param s The source node of the path.
     * @param t The destination node of the path.
     * @param parent A reference to the vector storing the parent nodes of each node in the path.
     * @param threshold The minimum capacity of edges in the path.
     * @param visited A reference to the vector storing the visited nodes during the search.
     * @return True if an augmenting path is found, false otherwise.
     */
    bool dfs(int s, int t, vector<int> &parent, int threshold, vector<int> &visited);

    /**
     * @brief Solves the maximum flow problem using the Ford-Fulkerson algorithm.
     */
    void solve();

  public:
    /**
     * @brief Constructs a FordFulkerson object with the given parameters.
     * @param n The number of nodes in the graph.
     * @param arr A vector of vectors representing the adjacency matrix of the graph.
     * @param s The source node of the graph.
     * @param t The destination node of the graph.
     */
    FordFulkerson(int n, vector<vector<int>> arr, int s, int t);

    /**
     * @brief Constructs a FordFulkerson object with the given adjacency matrix.
     * The number of nodes is automatically determined from the matrix size.
     * @param arr A vector of vectors representing the adjacency matrix of the graph.
     */
    FordFulkerson(vector<vector<int>> arr);

    /**
     * @brief Returns the residual graph after running the Ford-Fulkerson algorithm.
     * @return The residual graph as a vector of vectors.
     */
    vector<vector<int>> getresidualgraph();

    /**
     * @brief Returns the maximum flow value calculated by the Ford-Fulkerson algorithm.
     * @return The maximum flow value.
     */
    int getMaxFlow();
};

#endif
