#include "helix.h"
#include "circle.h"
#include "ellipse.h"

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>

double getRandomParameter(double min, double max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(min, max);
    return dis(gen);
}

int main() {
    std::vector<Curve3D*> curves;
    std::vector<Circle*> circles;

    // Populate the container with random curves
    for (int i = 0; i < 10; i++) {
        double radius = getRandomParameter(1.0, 10.0);
        double majorAxis = getRandomParameter(1.0, 10.0);
        double minorAxis = getRandomParameter(1.0, 10.0);
        double height = getRandomParameter(1.0, 10.0);

        // Randomly choose a curve type
        int curveType = rand() % 3;
        Curve3D* curve;

        switch (curveType) {
            case 0:
                curve = new Circle(radius);
                if (Circle* circle = dynamic_cast <Circle*> (curve)) {
                    circles.push_back(circle);
                }
                break;
            case 1:
                curve = new Ellipse(majorAxis, minorAxis);
                break;
            case 2:
                curve = new Helix(radius, height);
                break;
            default:
                curve = new Circle(radius);
        }

        curves.push_back(curve);
    }

    double t = M_PI / 4;

    std::cout << "Coordinates of points and derivatives at t = PI/4:" << std::endl;
    for (Curve3D* curve : curves) {
        std::vector<double> point = curve->getPoint(t);
        std::vector<double> derivative = curve->getDerivative(t);

        std::cout << "Curve Type: ";
        if (dynamic_cast <Circle*> (curve)) {
            std::cout << "Circle" << std::endl;
        } else if (dynamic_cast <Ellipse*> (curve)) {
            std::cout << "Ellipse" << std::endl;
        } else if (dynamic_cast <Helix*> (curve)) {
            std::cout << "Helix" << std::endl;
        }

        std::cout
            << "Point: ("
            << point[0] << ", "
            << point[1] << ", "
            << point[2] << ")"
            << std::endl;

        std::cout
            << "Derivative: ("
            << derivative[0] << ", "
            << derivative[1] << ", "
            << derivative[2] << ")"
            << std::endl;

        std::cout << std::endl;
    }

    std::sort(circles.begin(), circles.end(), [](Circle* a, Circle* b) {
        return a->getRadius() < b->getRadius();
    });

    double sumOfRadii = 0.0;
    for (Circle* circle : circles) {
        sumOfRadii += circle->getRadius();
    }

    std::cout << "Total sum of radii in the second container: " << sumOfRadii << std::endl;

    for (Curve3D* curve : curves) {
        delete curve;
    }

    return 0;
}
