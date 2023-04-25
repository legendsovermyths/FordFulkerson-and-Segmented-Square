/**

@file Point.hpp
@brief Header file for the Point class.
*/
#ifndef POINT_HPP
#define POINT_HPP

/**

@class Point

@brief A class representing a 2D point with integer coordinates.
*/
class Point
{
private:
public:
    int x, y;

    /**

    @brief Constructor for the Point class.
    @param a The x-coordinate of the point.
    @param b The y-coordinate of the point.
    */
    Point(int a, int b);
};
#endif