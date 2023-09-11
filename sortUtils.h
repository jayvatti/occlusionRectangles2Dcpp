//
// Created by Jay Vatti on 9/11/23.
//

#pragma once
#include "Rectangle.h"

int partition(std::vector<Rectangle>& rectangles, int low, int high) {
    double pivotValue = rectangles[low].distanceFromOrigin_;
    int left = low;
    int right = high;

    while (true) {
        while (rectangles[left].distanceFromOrigin_ < pivotValue) {
            left++;
        }

        while (rectangles[right].distanceFromOrigin_ > pivotValue) {
            right--;
        }

        if (left < right) {
            std::swap(rectangles[left], rectangles[right]);
        } else {
            return right;
        }
    }
}

void quickSort(std::vector<Rectangle>& rectangles, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(rectangles, low, high);
        quickSort(rectangles, low, pivotIndex);
        quickSort(rectangles, pivotIndex + 1, high);
    }
}
