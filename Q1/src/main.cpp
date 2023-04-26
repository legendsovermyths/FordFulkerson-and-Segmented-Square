#include "../include/FordFulkerson.hpp"
#include "../include/MaxFlowMinCut.hpp"
#include "../include/BipartiteMatching.hpp"
#include <chrono>
using namespace std::chrono;

int main(int argc, char *argv[])
{
    freopen("../data/input.txt", "r", stdin);
    int des = atoi(argv[1]);
    vector<vector<int>> edges;
    vector<int> temp(3);
    int edge;
    cin >> edge;
    for (int i = 0; i < edge; i++)
    {
        cin >> temp[0] >> temp[1] >> temp[2];
        edges.push_back(temp);
    }

    MaxFlowMinCut *f = new MaxFlowMinCut(des, edges, 1, des);
    auto start = high_resolution_clock::now();
    int ans = f->getMaxFlow();
    auto stop = high_resolution_clock::now();
    cout << ans << '\n';
    auto duration = duration_cast<microseconds>(stop - start);
    freopen("../data/time.txt", "w", stdout);
    cout << duration.count();
}
