#include "../include/MaxFlowMinCut.hpp"

MaxFlowMinCut::MaxFlowMinCut(int n, vector<vector<int>> edges, int s, int t)
{
    nodes = n, source = s;
    f = new FordFulkerson(n, edges, s, t);
}
void MaxFlowMinCut::dfs(int i, vector<int> &visited, vector<vector<int>> &graph)
{
    visited[i] = 1;
    for (int j = 0; j < graph[i].size(); j++)
    {
        if (graph[i][j] > 0 && !visited[j])
        {
            dfs(j, visited, graph);
        }
    }
}
int MaxFlowMinCut::getMaxFlow()
{
    int maxFlow = f->getMaxFlow();
    return maxFlow;
}
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
