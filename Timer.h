//
// Created by Jay Vatti on 8/28/23.
//
#pragma once
#include <chrono>
#include <iostream>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
public:
    Timer() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        auto stopTime = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTime).time_since_epoch().count();
        auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(stopTime).time_since_epoch().count();
        auto duration = stop - start;
        double ms = duration * 0.001;

        std::cout << "Timer took: " << ms << " ms" << std::endl;
    }
};


