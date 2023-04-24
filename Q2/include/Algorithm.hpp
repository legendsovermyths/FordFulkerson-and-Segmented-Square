#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits>
#include "Point.hpp"
#define N 1005
#define MAX numeric_limits<double>::infinity()
#define double long double
using namespace std;
class Algorithm
{
private:
    int preX[N], preY[N], preXY[N], preXsqr[N];
    double m[N][N], c[N][N], E[N][N], opt[N], optSeg[N];
    vector<pair<double, double>> results;
    vector<int> startSegment, endSegment;
    vector<double> errors;
    int numSegments;
    vector<Point *> points;
    double sumX, sumY, sumXY, sumXsqr, d, cost, error;
    int numPoints, solved = 0;
    static bool compare(Point *p1, Point *p2);
    void leastSegmentedSquare();
    void constructSegments();
    void constructSolution();

public:
    Algorithm(vector<Point *> p, int n, double ct);
    vector<pair<double, double>> getSegments();
    double getError();
    vector<double> getErrors();
    int getNumSegments();
    vector<vector<int>> getintervals();
    void printSolution();
};
#endif
