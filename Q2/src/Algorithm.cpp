#include "../include/Algorithm.hpp"

Algorithm::Algorithm(vector<Point *> p, int n, long long ct)
{
    points = p, numPoints = n, cost = ct;
    preX[0] = preY[0] = preXY[0] = preXsqr[0] = 0;
    sort(points.begin(), points.end(), compare);
}

void Algorithm::solve()
{
    for (int j = 1; j <= numPoints; j++)
    {
        preX[j] = preX[j - 1] + points[j]->x;
        preY[j] = preY[j - 1] + points[j]->y;
        preXY[j] = preXY[j - 1] + points[j]->x * points[j]->y;
        preXsqr[j] = preXsqr[j - 1] + points[j]->x * points[j]->x;

        for (int i = 1; i <= j; i++)
        {
            long long interval = j - i + 1;
            sumX = preX[j] - preX[i - 1];
            sumY = preY[j] - preY[i - 1];
            sumXY = preXY[j] - preXY[i - 1];
            sumXsqr = preXsqr[j] - preXsqr[i - 1];

            long long num = interval * sumXY - sumX * sumY;
            if (num == 0)
                m[i][j] = 0.0;
            else
            {
                long long denom = interval * sumXsqr - sumX * sumX;
                m[i][j] = (denom == 0) ? MAX : (num / double(denom));
            }
            c[i][j] = (sumY - m[i][j] * sumX) / double(interval);
            E[i][j] = 0.0;
            for (int k = i; k <= j; k++)
            {
                long long tmp = points[k]->y - m[i][j] * points[k]->x - c[i][j];
                E[i][j] += tmp * tmp;
            }
        }
    }
}
