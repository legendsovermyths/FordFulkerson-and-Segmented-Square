#ifndef MaxFlowMinCut_HPP
#define MaxFlowMinCut_HPP
#include <iostream>
#include <queue>
#include <vector>
#include "FordFulkerson.hpp"
using namespace std;
class MaxFlowMinCut
{
private:
    FordFulkerson *f;
    int nodes = 0, source = -1;
    void dfs(int i, vector<int> &visited, vector<vector<int>> &graph);

public:
    MaxFlowMinCut(int n, vector<vector<int>> edges, int s, int t);
    int getMaxFlow();
    vector<vector<int>> getMinCut();
};
#endif