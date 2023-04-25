/**

@file Algorithm.hpp
@brief This file contains the declaration of the Algorithm class, which implements the segmented least squares algorithm.
*/
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

/**

@class Algorithm

@brief Class that implements the segmented least squares algorithm for a set of points
*/
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

    /**

    @brief Compares two points based on their x-coordinate.
    @param p1 Pointer to the first point
    @param p2 Pointer to the second point
    @return True if the x-coordinate of p1 is smaller than the x-coordinate of p2, false otherwise.
    */
    static bool compare(Point *p1, Point *p2);
    /**

    @brief Implements the segmented least squares algorithm
    */
    void leastSegmentedSquare();
    /**

    @brief Constructs the set of segments
    */
    void constructSegments();
    /**

    @brief Constructs the solution from the set of segments
    */
    void constructSolution();

public:
    /**
     * @brief Constructor for the Algorithm class
     * @param p Vector containing the points
     * @param n Number of points
     * @param ct Cost for making segments
     */
    Algorithm(vector<Point *> p, int n, double ct);
    /**
     * @brief Returns the set of segments
     * @return Vector containing pairs of slope and intercept for each segment
     */
    vector<pair<double, double>> getSegments();

    /**
     * @brief Returns the total error for the set of segments
     * @return Total error for the set of segments
     */
    double getError();

    /**
     * @brief Returns the vector of errors for each segment
     * @return Vector of errors for each segment
     */
    vector<double> getErrors();

    /**
     * @brief Returns the number of segments
     * @return Number of segments
     */
    int getNumSegments();

    /**
     * @brief Returns the intervals of the points that belong to each segment
     * @return Vector of intervals for each segment
     */
    vector<vector<int>> getintervals();

    /**
     * @brief Prints the solution to standard output
     */
    void printSolution();
};

#endif // ALGORITHM_HPP