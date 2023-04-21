#ifndef BipartiteMatching_HPP
#define BipartiteMatching_HPP
#include <iostream>
#include <queue>
#include <vector>
#include "FordFulkerson.hpp"
using namespace std;
class BipartiteMatching
{
private:
    FordFulkerson *f;
    int nodes = 0, solved = 0, bipartite = 0, maxMatching = -1;
    vector<vector<int>> graph;
    vector<int> div;
    void err();
    bool isBipartite(vector<int> &div);
    void convertGraph();

public:
    BipartiteMatching(vector<vector<int>> arr, int n);
    BipartiteMatching(vector<vector<int>> arr);
    int GetMaxBipartiteMatching();
};
#endif