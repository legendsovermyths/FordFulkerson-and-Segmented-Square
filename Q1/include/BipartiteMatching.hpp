/**
 * @file BipartiteMatching.hpp
 * @brief Declaration of the BipartiteMatching class.
 */

#ifndef BipartiteMatching_HPP
#define BipartiteMatching_HPP
#include "FordFulkerson.hpp"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/**
 * @class BipartiteMatching
 * @brief Class for solving the maximum bipartite matching problem using the Ford-Fulkerson algorithm.
 */
class BipartiteMatching {
  private:
    FordFulkerson *f;          /**< Pointer to the Ford-Fulkerson object. */
    int nodes = 0;             /**< Number of nodes in the graph. */
    int solved = 0;            /**< Flag to indicate whether the problem has been solved. */
    int bipartite = 0;         /**< Flag to indicate whether the graph is bipartite. */
    int maxMatching = -1;      /**< Maximum matching size. */
    vector<vector<int>> graph; /**< Adjacency list representation of the graph. */
    vector<int> div;           /**< Vertex division into two sets. */

    /**
     * @brief Prints an error message and exits the program.
     */
    void err();

    /**
     * @brief Checks if the graph is bipartite.
     * @param div A reference to the vector storing the division of vertices into two sets.
     * @return True if the graph is bipartite, false otherwise.
     */
    bool isBipartite(vector<int> &div);

    /**
     * @brief Converts the graph representation from adjacency matrix to adjacency list.
     */
    void convertGraph();

  public:
    /**
     * @brief Constructs a BipartiteMatching object with the given parameters.
     * @param arr A vector of vectors representing the adjacency matrix of the graph.
     * @param n The number of nodes in the graph.
     */
    BipartiteMatching(vector<vector<int>> arr, int n);

    /**
     * @brief Constructs a BipartiteMatching object with the given adjacency matrix.
     * The number of nodes is automatically determined from the matrix size.
     * @param arr A vector of vectors representing the adjacency matrix of the graph.
     */
    BipartiteMatching(vector<vector<int>> arr);

    /**
     * @brief Calculates and returns the maximum bipartite matching size.
     * @return The maximum bipartite matching size.
     */
    int GetMaxBipartiteMatching();
};

#endif