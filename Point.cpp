//
// Created by Jay Vatti on 9/9/23.
//

#include "Point.h"

Point::Point(double x, double y) : x_(x), y_(y){
    double rad_ = std::atan2(y_, x_); //radians -> [-pi,pi)

    // to ensure the result is within the range [0, 359]
    double degrees_ = rad_ * (180.0 / M_PI); // [-180,180)
    if (degrees_ < 0){
        degrees_ += 360;
    }
    theta_ = degrees_;
}

double Point::distanceBetween(const Point &p1, const Point &p2){
    double dx = p2.x_ - p1.x_;
    double dy = p2.y_ - p1.y_;
    return std::sqrt(dx * dx + dy * dy);
}
