/**
 * @file main.cpp
 * @brief Main entry point of the program.
 */
#include "../include/FordFulkerson.hpp"
#include "../include/MaxFlowMinCut.hpp"
#include "../include/BipartiteMatching.hpp"
#include <chrono>
using namespace std::chrono;

/**
 * @brief The main function of the program.
 *
 * Reads the input from a file, constructs a MaxFlowMinCut object, computes the maximum flow,
 * and outputs the result and the execution time.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return The exit status of the program.
 */
int main(int argc, char *argv[])
{
    // Redirecting standard input to read from a file
    freopen("../data/input.txt", "r", stdin);
    freopen("../data/output.txt", "w", stdout);
    // Parsing the destination node from command-line argument
    int des = atoi(argv[1]);

    // Reading the edges from input file
    vector<vector<int>> edges;
    vector<int> temp(3);
    int edge;
    cin >> edge;
    for (int i = 0; i < edge; i++)
    {
        cin >> temp[0] >> temp[1] >> temp[2];
        edges.push_back(temp);
    }

    // BipartiteMatching *b = new BipartiteMatching(edges, des);
    // cout << "Maximum matching is : " << b->GetMaxBipartiteMatching() << '\n';
    // vector<pair<int, int>> res = b->GetPairwiseMatching();
    // cout << "Matching is: \n";
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i].first << " " << res[i].second << '\n';
    // }
    // Creating MaxFlowMinCut object and computing the maximum flow
    MaxFlowMinCut *f = new MaxFlowMinCut(des, edges, 1, des);
    auto start = high_resolution_clock::now();
    int ans = f->getMaxFlow();
    auto stop = high_resolution_clock::now();

    // Outputting the result and the execution time
    cout << ans << '\n';
    auto duration = duration_cast<microseconds>(stop - start);

    // Redirecting standard output to write to a file
    vector<vector<int>> mincut = f->getMinCut();
    int s1 = mincut[0].size(), s2 = mincut[1].size();
    cout << "mincut is:" << '\n';
    cout << "set 1:" << '\n';
    for (int i = 0; i < s1; i++)
    {
        cout << mincut[0][i] << " ";
    }
    cout << "\nset 2:" << '\n';
    for (int i = 0; i < s2; i++)
    {
        cout << mincut[1][i] << " ";
    }
    cout << '\n';
    freopen("../data/time.txt", "w", stdout);
    cout << duration.count();

    return 0;
}