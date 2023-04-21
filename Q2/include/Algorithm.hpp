#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include "Point.hpp"
#define N 1005
#define MAX 1000000000
using namespace std;
class Algorithm
{
private:
    long long int preX[N], preY[N], preXY[N], preXsqr[N];
    double m[N][N], c[N][N], E[N][N], opt[N], optSeg[N];
    vector<Point *> points;
    long long sumX, sumY, sumXY, sumXsqr, d, cost;
    int numPoints;
    bool compare(Point *p1, Point *p2);
    void solve();

public:
    Algorithm(vector<Point *> p, int n, long long ct);
};
#endif
