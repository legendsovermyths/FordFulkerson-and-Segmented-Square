#include "../include/BipartiteMatching.hpp"
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
BipartiteMatching::BipartiteMatching(vector<vector<int>> arr, int n)
{
    nodes = n;
    graph = vector<vector<int>>(nodes + 1, vector<int>(nodes + 1, 0));
    for (int i = 0; i < arr.size(); i++)
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
void BipartiteMatching::err()
{
    cerr << "The Graph is not Bipartite\n";
}
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
