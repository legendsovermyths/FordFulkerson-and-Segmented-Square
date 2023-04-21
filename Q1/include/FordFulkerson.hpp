#ifndef FordFulkerson_HPP
#define FordFulkerson_HPP
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1073741824
class FordFulkerson
{
private:
    int nodes;
    vector<vector<int>> graph;
    vector<vector<int>> residualGraph;
    int source, dest;
    int solved = 0, maxFlow = 0;
    bool dfs(int s, int t, vector<int> &parent, int threshold, vector<int> &visited);
    void solve();

public:
    FordFulkerson(int n, vector<vector<int>> arr, int s, int t);
    FordFulkerson(vector<vector<int>> arr);
    vector<vector<int>> getresidualgraph();
    int getMaxFlow();
};
#endif
