//
// Created by Jay Vatti on 9/9/23.
//
#pragma once
#include "Rectangle.h"
#include <execution>
#include <omp.h>


//convergeTable
void fillCoverageTable(std::vector<Rectangle>& rectangles, std::vector<std::vector<int>>& coverage_table) {

    for (size_t i = 0; i < rectangles.size(); ++i) {
        int min_theta_deg = std::round(rectangles[i].min_theta_);
        int max_theta_deg = std::round(rectangles[i].max_theta_);

       // #pragma omp parallel for
        for (int angle_bin = min_theta_deg; angle_bin <= max_theta_deg; ++angle_bin) {
            coverage_table[i][angle_bin] = 1;
        }
    }
}

//sum each column of the coverage table
std::vector<int> sumCoverageTableColumns(const std::vector<std::vector<int>>& coverage_table) {
    const int num_angle_bins = 360;
    std::vector<int> sum_by_column(num_angle_bins, 0);
    for (int col = 0; col < num_angle_bins; ++col) {
        for(size_t row = 0; row < coverage_table.size(); ++row) {
            sum_by_column[col] += coverage_table[row][col];
        }
    }
    return sum_by_column;
}

//save sum_by_column to a CSV file
void saveToCSV(const std::vector<int>& sum_by_column, const std::string& filename) {
    std::ofstream outfile(filename);
    for (int val : sum_by_column) {
        outfile << val << "\n";
    }
    outfile.close();
}

//calculate the number of occluded angles
int calculateOccludedAngles(const std::vector<int>& sum_by_column) {
    int occluded_angles_count = 0;
    for (int val : sum_by_column) {
        if (val > 1) {
            ++occluded_angles_count;
        }
    }
    return occluded_angles_count;
}

