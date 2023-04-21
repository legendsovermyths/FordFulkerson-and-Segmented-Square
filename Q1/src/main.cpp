#include "../include/FordFulkerson.hpp"
#include "../include/MaxFlowMinCut.hpp"
#include "../include/BipartiteMatching.hpp"

int main()
{
    vector<vector<int>> edges = {{1, 2, 16}, {1, 3, 13}, {2, 3, 10}, {2, 4, 12}, {3, 2, 4}, {3, 5, 14}, {4, 3, 9}, {4, 6, 20}, {5, 4, 7}, {5, 6, 4}};
    MaxFlowMinCut *f = new MaxFlowMinCut(6, edges, 1, 6);
    int ans = f->getMaxFlow();
    vector<vector<int>> minCut = f->getMinCut();
    cout << "Maximum Flow is: " << ans << '\n';
    cout << "Min cut is\n";
    cout << "set 1: ";
    for (int i = 0; i < minCut[0].size(); i++)
        cout << minCut[0][i] << " ";
    cout << '\n'
         << "set 2: ";
    for (int i = 0; i < minCut[1].size(); i++)
        cout << minCut[1][i] << " ";
    cout << '\n';
    vector<vector<int>> graph = {{1, 8, 1}, {1, 9}, {3, 7}, {3, 10}, {4, 9}, {5, 9}, {5, 10}, {6, 12}};
    BipartiteMatching *f2 = new BipartiteMatching(graph, 12);
    cout << f2->GetMaxBipartiteMatching() << endl;
}
