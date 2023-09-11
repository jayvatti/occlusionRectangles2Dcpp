//
// Created by Jay Vatti on 9/9/23.
//
#pragma  once
#include <random>
#include <cmath>

static double distanceBetweenPoints(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

static double randomUniform(double lower, double upper) {
    static std::default_random_engine e(static_cast<unsigned int>(std::time(0)));  // Seed with current time
    std::uniform_real_distribution<> dis(lower, upper);
    return dis(e);
}
