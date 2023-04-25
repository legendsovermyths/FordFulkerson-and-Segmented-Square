#include "../include/FordFulkerson.hpp"

FordFulkerson::FordFulkerson(int n, vector<vector<int>> arr, int s, int t)
{
  nodes = n, source = s, dest = t;
  graph = vector<vector<int>>(nodes + 1, vector<int>(nodes + 1, 0));
  residualGraph = vector<vector<int>>(nodes + 1, vector<int>(nodes + 1, 0));
  for (int i = 0; i < arr.size(); i++)
  {
    graph[arr[i][0]][arr[i][1]] = arr[i][2];
    residualGraph[arr[i][0]][arr[i][1]] = arr[i][2];
  }
}
FordFulkerson::FordFulkerson(vector<vector<int>> arr)
{
  nodes = arr.size(), source = 0, dest = nodes - 1;
  graph = arr, residualGraph = arr;
}
bool FordFulkerson::dfs(int s, int t, vector<int> &parent, int threshold, vector<int> &visited)
{
  visited[s] = 1;
  if (s == t)
  {
    return true;
  }
  bool rvalue = false;
  visited[s] = 1;
  for (int j = 0; j < residualGraph[s].size(); j++)
  {
    if (residualGraph[s][j] >= threshold && !visited[j])
    {
      parent[j] = s;
      rvalue |= dfs(j, t, parent, threshold, visited);
    }
  }
  return rvalue;
}
int FordFulkerson::getMaxFlow()
{
  if (solved == 0)
    solve();
  int flow = this->maxFlow;
  return flow;
}
vector<vector<int>> FordFulkerson::getresidualgraph()
{
  if (solved == 0)
    solve();
  vector<vector<int>> res = this->residualGraph;
  return res;
}
void FordFulkerson::solve()
{
  solved = 1;
  vector<int> parent(nodes + 1, 0), visited(nodes + 1, 0);
  int maxFlow = 0;
  int threshold = MAX;
  while (threshold > 0)
  {
    parent = vector<int>(nodes + 1, 0), visited = vector<int>(nodes + 1, 0);
    while (dfs(source, dest, parent, threshold, visited))
    {
      int flow = threshold, u = dest, v;
      v = dest;
      while (v != source)
      {
        u = parent[v];
        residualGraph[u][v] -= flow;
        residualGraph[v][u] += flow;
        v = parent[v];
      }
      maxFlow += flow;
      parent = vector<int>(nodes + 1, 0), visited = vector<int>(nodes + 1, 0);
    }
    threshold /= 2;
  }
  this->maxFlow = maxFlow;
}
