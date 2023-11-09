#include "circle.h"


std::vector<double> Circle::getPoint(double t)
{
    double x = radius * cos(t);
    double y = radius * sin(t);
    double z = 0.0;
    return {x, y, z};
}

std::vector<double> Circle::getDerivative(double t)
{
    double dx = -radius * sin(t);
    double dy = radius * cos(t);
    double dz = 0.0;
    return {dx, dy, dz};
}


