/**
 * @file BipartiteMatching.cpp
 * @brief Implementation of the BipartiteMatching class methods.
 */
#include "../include/BipartiteMatching.hpp"
/**
 * @brief Constructs a BipartiteMatching object from a given adjacency matrix.
 *
 * @param arr The adjacency matrix representing the graph.
 */
BipartiteMatching::BipartiteMatching(vector<vector<int>> arr)
{
    nodes = arr.size();
    graph = arr;
    div = vector<int>(nodes + 1, -1);

    if (!isBipartite(div))
    {
        err();
        bipartite = 0;
    }
    else
    {
        bipartite = 1;
        convertGraph();
    }
}

/**
 * @brief Constructs a BipartiteMatching object from a given edge list and the number of nodes.
 *
 * @param arr The edge list representing the graph.
 * @param n The number of nodes in the graph.
 */
BipartiteMatching::BipartiteMatching(vector<vector<int>> arr, int n)
{
    nodes = n;
    graph = vector<vector<int>>(nodes + 1, vector<int>(nodes + 1, 0));
    int sz = arr.size();
    for (int i = 0; i < sz; i++)
    {
        graph[arr[i][0]][arr[i][1]] = 1;
        graph[arr[i][1]][arr[i][0]] = 1;
    }

    div = vector<int>(nodes + 1, -1);

    if (!isBipartite(div))
    {
        err();
        bipartite = 0;
    }
    else
    {
        bipartite = 1;
        convertGraph();
    }
}

/**
 * @brief Checks if the given graph is bipartite.
 *
 * @param div The vector representing the division of nodes into two groups.
 * @return True if the graph is bipartite, False otherwise.
 */
bool BipartiteMatching::isBipartite(vector<int> &div)
{
    queue<int> q;
    int node, as;

    for (int i = 1; i < nodes + 1; i++)
    {
        if (div[i] != -1)
            continue;

        div[i] = 0;
        q.push(i);

        while (!q.empty())
        {
            node = q.front();
            q.pop();
            as = div[node];

            for (int j = 1; j < nodes + 1; j++)
            {
                if (graph[node][j] > 0)
                {
                    if (div[j] == as)
                        return false;
                    if (div[j] == -1)
                        q.push(j);
                    div[j] = as ^ 1;
                }
            }
        }
    }

    return true;
}

/**
 * @brief Prints an error message indicating that the graph is not bipartite.
 */
void BipartiteMatching::err()
{
    cerr << "The Graph is not Bipartite\n";
}

/**
 * @brief Converts the bipartite graph to a new graph where edges connect nodes of different groups.
 * If the graph is not bipartite, an error message is printed.
 */
void BipartiteMatching::convertGraph()
{
    if (bipartite == 0)
    {
        err();
        return;
    }

    vector<vector<int>> newGraph(nodes + 2, vector<int>(nodes + 2, 0));

    for (int i = 0; i < nodes + 1; i++)
    {
        for (int j = 0; j < nodes + 1; j++)
        {
            if (graph[i][j] == 1)
            {
                if (div[i] == 1)
                {
                    newGraph[i][j] = 1;
                    newGraph[0][i] = 1;
                    newGraph[j][nodes + 1] = 1;
                }
                else
                {
                    newGraph[0][j] = 1;
                    newGraph[j][i] = 1;
                    newGraph[i][nodes + 1] = 1;
                }
            }
        }
    }

    graph = newGraph;
}

/**
 * @brief Calculates the maximum bipartite matching in the graph.
 * If the graph is not bipartite, an error message is printed.
 *
 * @return The maximum bipartite matching.
 */
int BipartiteMatching::GetMaxBipartiteMatching()
{
    if (bipartite == 0)
    {
        err();
        return 0;
    }

    f = new FordFulkerson(graph);
    maxMatching = f->getMaxFlow();

    return maxMatching;
}
