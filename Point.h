//
// Created by Jay Vatti on 9/9/23.
//

#include <cmath>
#include <iostream>
#pragma once

class Point {
public:
    //member variables
    double x_,y_;
    double theta_;

    Point(double x, double y);
    static double distanceBetween(const Point& p1, const Point& p2);

};
