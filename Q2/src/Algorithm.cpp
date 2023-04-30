#include "../include/Algorithm.hpp"
bool Algorithm::compare(Point *p1, Point *p2)
{
    if (p1->x != p2->x)
        return p1->x < p2->x;
    return p1->y < p2->y;
}
Algorithm::Algorithm(vector<Point *> p, int n, double ct)
{
    points = p, numPoints = n, cost = ct;
    preX[0] = preY[0] = preXY[0] = preXsqr[0] = 0;
    sort(points.begin() + 1, points.end(), compare);
}

void Algorithm::leastSegmentedSquare()
{
    for (int j = 1; j <= numPoints; j++)
    {
        preX[j] = preX[j - 1] + points[j]->x;
        preY[j] = preY[j - 1] + points[j]->y;
        preXY[j] = preXY[j - 1] + points[j]->x * points[j]->y;
        preXsqr[j] = preXsqr[j - 1] + points[j]->x * points[j]->x;
        for (int i = 1; i <= j; i++)
        {
            double interval = j - i + 1;
            sumX = preX[j] - preX[i - 1];
            sumY = preY[j] - preY[i - 1];
            sumXY = preXY[j] - preXY[i - 1];
            sumXsqr = preXsqr[j] - preXsqr[i - 1];

            double num = interval * sumXY - sumX * sumY;
            if (num == 0)
                m[i][j] = 0.0;
            else
            {
                double denom = interval * sumXsqr - sumX * sumX;
                m[i][j] = (denom == 0) ? MAX : (num / denom);
            }
            c[i][j] = (sumY - m[i][j] * sumX) / interval;
            E[i][j] = 0.0;
            for (int k = i; k <= j; k++)
            {
                double tmp = points[k]->y - m[i][j] * points[k]->x - c[i][j];
                E[i][j] += tmp * tmp;
            }
        }
    }
}
void Algorithm::constructSegments()
{
    opt[0] = optSeg[0] = 0;
    for (int j = 1; j <= numPoints; j++)
    {
        int i, k;
        double mn;
        for (i = 1, mn = MAX, k = 0; i <= j; i++)
        {
            double tmp = E[i][j] + opt[i - 1];
            if (tmp < mn)
            {
                mn = tmp;
                k = i;
            }
        }
        opt[j] = mn + cost;
        optSeg[j] = k;
    }
    solved = 1;

    return;
}
void Algorithm::printSolution()
{
    if (solved == 0)
        constructSolution();
    printf("\nCost of the optimal solution : %f\n", opt[numPoints]);
    printf("\nAn optimal solution :\n");
    for (int i = 0; i < numSegments; i++)
    {
        printf("Segment y = %f * x + %f from points %d to %d with square error %f.\n",
               results[i].first, results[i].second, startSegment[i], endSegment[i], errors[i]);
    }
}
void Algorithm::constructSolution()
{
    error = opt[numPoints];
    if (solved == 0)
    {
        leastSegmentedSquare();
        constructSegments();
    }
    stack<int> segments;
    for (int i = numPoints, j = optSeg[numPoints]; i > 0; i = j - 1, j = optSeg[i])
    {
        segments.push(i);
        segments.push(j);
    }
    while (!segments.empty())
    {
        int i = segments.top();
        segments.pop();
        int j = segments.top();
        segments.pop();
        results.push_back(make_pair(m[i][j], c[i][j]));
        errors.push_back(E[i][j]);
        startSegment.push_back(i);
        endSegment.push_back(j);
    }
    numSegments = errors.size();
}
double Algorithm::getError()
{
    if (solved == 0)
        constructSolution();
    return error;
}
vector<pair<double, double>> Algorithm::getSegments()
{
    if (solved == 0)
        constructSolution();
    return results;
}
int Algorithm::getNumSegments()
{
    if (solved == 0)
        constructSolution();
    return numSegments;
}
vector<double> Algorithm::getErrors()
{
    if (solved == 0)
        constructSolution();
    return errors;
}
vector<vector<int>> Algorithm::getintervals()
{
    return {startSegment, endSegment};
}
