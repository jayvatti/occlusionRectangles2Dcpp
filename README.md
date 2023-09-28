# Occlusion Rectangles 2D in C++

This project calculates the occlusion angles for `N` non-overlapping rectangles in 2D space. The purpose is to find the total angle through which rectangles are viewed from the origin without counting the overlapping portions of the rectangles multiple times.

## Overview

- **Point Class:** Represents a point in 2D space.
- **Rectangle Class:** Consists of four points and represents a rectangle.
- **Timer.h:** A utility to measure the performance and speed of the solution.
- **generalUtils.h:** Includes utilities for calculating overlaps.
- **mathUtils.h:** Consists of various math and random functions.
- **sortUtils.h:** Contains the implementation of QuickSort.

## Approach

1. **Creating Non-Overlapping Rectangles:**
   - Generate `N` non-overlapping circles.
   - Use polar math to fit a rectangle inside each circle, ensuring they are non-overlapping.

2. **Calculating Occlusion Angles:**
   - Calculate the polar coordinates for each rectangle.
   - Find the minimum and maximum theta for each rectangle.
   - Sort the rectangles by the nearest distance to the origin using QuickSort.

3. **Handling Overlaps:**
   - After sorting, calculate the overlapping angles between the rectangles to find the total occluded angle accurately.

4. **Visualization:**
   - The result is then visualized using a Python notebook, `occlusionRays.ipynb`, where the rectangles and the sum by column are plotted using data stored in CSV files.

## Files

- `Point.cpp` and `Point.h`: Definition and Implementation of the Point class.
- `Rectangle.cpp` and `Rectangle.h`: Definition and Implementation of the Rectangle class.
- `Timer.h`: Performance and Speed Measurement.
- `generalUtils.h`: Utilities for Calculating Overlap.
- `mathUtils.h`: Math and Random Functions.
- `sortUtils.h`: QuickSort Implementation.
- `occlusionRays.ipynb`: Python Notebook for Visualization.

## Data

- **rectangles.csv:** Contains the data of the rectangles.
- **sum_by_column.csv:** Used to plot the occlusion rays.

## Verification

The solution was verified by printing overlaps using Python to show that it's working as expected and comparing the results against expected outcomes.

![image](https://github.com/jayvatti/occlusionRectangles2Dcpp/assets/97709855/385a5376-aa22-47bf-b20a-3298748d9651)

![image](https://github.com/jayvatti/occlusionRectangles2Dcpp/assets/97709855/7a0432c7-cd41-457d-a514-a2e9e6f5c95a)




## Performance

The performance and speed of the solution were measured using `Timer.h` to ensure efficiency.

## Usage

1. Run the C++ files to generate non-overlapping rectangles and calculate the occlusion angles.
2. The results are stored in the mentioned CSV files.
3. Visualize the results using `occlusionRays.ipynb`.
