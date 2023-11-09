#include "ellipse.h"

std::vector<double> Ellipse::getPoint(double t)
{
    double x = majorAxis * cos(t);
    double y = minorAxis * sin(t);
    double z = 0.0;
    return {x, y, z};
}

std::vector<double> Ellipse::getDerivative(double t)
{
    double dx = -majorAxis * sin(t);
    double dy = minorAxis * cos(t);
    double dz = 0.0;
    return {dx, dy, dz};
}

