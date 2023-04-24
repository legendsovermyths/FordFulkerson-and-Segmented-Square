#include "../include/Point.hpp"
#include "../include/Algorithm.hpp"

int main()
{
    freopen("input.txt", "r", stdin);
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
    A->printSolution();
}