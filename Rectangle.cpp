//
// Created by Jay Vatti on 9/9/23.
//
#include "Rectangle.h"
#include "sortUtils.h"

Rectangle::Rectangle(Point centroid, Point a, Point b, Point c, Point d)
        : centroid_(centroid), a_(a), b_(b), c_(c), d_(d), min_theta_(0), max_theta_(0) {
    calculateThetaBounds();
}

void Rectangle::calculateThetaBounds() {
    min_theta_ = std::min({a_.theta_, b_.theta_, c_.theta_, d_.theta_});
    max_theta_ = std::max({a_.theta_, b_.theta_, c_.theta_, d_.theta_});
}

//static member function
std::vector<Point> Rectangle::calculateVertices(double h, double k, double half_l, double half_b, double theta) {
    std::vector<Point> vertices;

    std::array<std::pair<double, double>, 4> pairs = {
            std::make_pair(half_l, half_b),
            std::make_pair(-half_l, half_b),
            std::make_pair(-half_l, -half_b),
            std::make_pair(half_l, -half_b)
    };

    for (const auto& [dx, dy] : pairs) {
        double x = h + dx * std::cos(theta) - dy * std::sin(theta);
        double y = k + dx * std::sin(theta) + dy * std::cos(theta);
        vertices.emplace_back(Point(x, y));
    }
    return vertices;
}
//static member function
std::vector<Rectangle> Rectangle::generateRectangles(int n, double min_distance) {
    std::vector<Rectangle> rectangles;

    double h, k, r;

    for (int i = 0; i < n; ++i) {
        bool collision = true;
        while (collision) {
            collision = false;
            //randomly generating circle params
            h = randomUniform(-10, 10);
            k = randomUniform(-10, 10);
            r = randomUniform(1, 5);

            //checking if circle touches the x-axis // to reduce occlusion complexity
            if (k - r < 0 && k + r > 0) {
                collision = true;
                continue;
            }

            //checking for collision with other circles in rectangles
            for (const auto& rect : rectangles) {
                if (r + rect.radius_ >= distanceBetweenPoints(h, k, rect.centroid_.x_, rect.centroid_.y_)) {
                    collision = true;
                    break;
                }
            }

            //# checking if the circle is too close/ overlaps with the origin
            if (distanceBetweenPoints(h, k, 0, 0) < r + min_distance) {
                collision = true;
            }
        }

        /*
            picking 2 values that act as width and height for the rect;
            width = 2*half_b ; = 2*half_l
            choosing values for half_b and half_l such that ->

            half_l^2 + half_b^2 = r^2
         */
        double half_l = randomUniform(1, r - 1);
        double half_b = std::sqrt(r * r - half_l * half_l);

        //tilt angle
        double theta = randomUniform(0, 2 * M_PI);

        //creating the rectangle
        auto vertices = Rectangle::calculateVertices(h, k, half_l, half_b, theta);
        Point centroid(h, k);
        Rectangle rect(centroid, vertices[0], vertices[1], vertices[2], vertices[3]);
        rect.radius_ = r;
        rect.distanceFromOrigin_ = std::sqrt(h * h + k * k);
        rect.centroid_ = centroid;

        //adding to the rectangles vector
        rectangles.push_back(rect);
    }
    return rectangles;
}
//static member function
void Rectangle::sortRectanglesByDistance(std::vector<Rectangle>& rectangles) {
    quickSort(rectangles, 0, rectangles.size() - 1);
}
//static member function
void Rectangle::writeToCSV(const std::vector<Rectangle>& rectangles) {
    std::ofstream outfile("rectangles.csv");

    //header
    outfile << "c_x,c_y,x1,y1,x2,y2,x3,y3,x4,y4,radius\n";

    //rectangles info
    for (const auto& rect : rectangles) {
        outfile << rect.centroid_.x_ << ","
                << rect.centroid_.y_ << ","
                << rect.a_.x_ << "," << rect.a_.y_ << ","
                << rect.b_.x_ << "," << rect.b_.y_ << ","
                << rect.c_.x_ << "," << rect.c_.y_ << ","
                << rect.d_.x_ << "," << rect.d_.y_ << ","
                << rect.radius_ << "\n";
    }
    outfile.close();
}

