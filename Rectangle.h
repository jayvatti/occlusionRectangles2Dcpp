//
// Created by Jay Vatti on 9/9/23.
//
#include <algorithm>
#include <fstream>

#include "Point.h"
#include "mathUtils.h"
#pragma once

class Rectangle {
public:

//member variables
    Point centroid_;
    double radius_ = 0;
    double distanceFromOrigin_ = 0;

    Point a_, b_, c_, d_; // vertices
    double min_theta_, max_theta_;

    //----
    Rectangle(Point centroid, Point a, Point b, Point c, Point d);
    void calculateThetaBounds();

    //static member functions
    static std::vector<Point> calculateVertices(double h, double k, double half_l, double half_b, double theta);
    static std::vector<Rectangle> generateRectangles(int n, double min_distance = 2);
    static void sortRectanglesByDistance(std::vector<Rectangle>& rectangles);
    static void writeToCSV(const std::vector<Rectangle>& rectangles);
};

