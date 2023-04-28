#include "../include/Point.hpp"
#include "../include/Algorithm.hpp"

int main()
{
    freopen("../data/input.txt", "r", stdin);
    freopen("../data/output.txt", "w", stdout);
    int numPoint;
    cin >> numPoint;
    vector<Point *> points;
    double x, y;
    points.push_back(new Point(0, 0));
    for (int i = 0; i < numPoint; i++)
    {
        cin >> x >> y;
        Point *p = new Point(x, y);
        points.push_back(p);
    }
    double cst = 0;
    cin >> cst;
    Algorithm *A = new Algorithm(points, numPoint, cst);
    vector<pair<double, double>> slope = A->getSegments();
    vector<vector<int>> startend = A->getintervals();
    int numsegments = A->getNumSegments();
    cout << numsegments << '\n';
    for (int i = 0; i < numsegments; i++)
    {
        cout << slope[i].first << " " << slope[i].second << '\n';
    }
    for (int i = 0; i < numsegments; i++)
    {
        cout << startend[0][i] << " " << startend[1][i] << '\n';
    }

    A->printSolution();
}