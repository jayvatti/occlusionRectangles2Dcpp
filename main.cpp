#include <iostream>
#include "generalUtils.h"
#include "Timer.h"
int main(){

    int N;
    std::cout << "Enter the no.of rectangles 'N': ";
    std::cin >> N;
    std::vector<Rectangle> rectangles = Rectangle::generateRectangles(N);
    Rectangle::sortRectanglesByDistance(rectangles);
    Rectangle::writeToCSV(rectangles);

    /*
    //DEBUGGING
     for (const auto& rect : rectangles) {
        std::cout << "Rectangle distance:" << rect.distanceFromOrigin_ << std::endl;
        std::cout << "Min angle in radians: " << rect.min_theta_ << std::endl;
        std::cout << "Max angle in radians: " << rect.max_theta_ << std::endl;
        std::cout<<std::endl<<std::endl;
    }
     */

    const int num_angle_bins = 360;
    std::vector<std::vector<int>> coverage_table(rectangles.size(), std::vector<int>(num_angle_bins, 0));

    {
        Timer t;
        fillCoverageTable(rectangles, coverage_table);
    }

    std::vector<int> sum_by_column = sumCoverageTableColumns(coverage_table);
    saveToCSV(sum_by_column, "sum_by_column.csv");

    int occluded_angles_count = calculateOccludedAngles(sum_by_column);
    std::cout << "Occluded angle in Degrees: " << occluded_angles_count << std::endl;


}

