#include "helix.h"

 std::vector<double> Helix::getPoint(double t)
{
    double x = radius * cos(t);
    double y = radius * sin(t);
    double z = height * t / (2 * M_PI);
    return {x, y, z};
}

std::vector<double> Helix::getDerivative(double t)
{
    double dx = -radius * sin(t);
    double dy = radius * cos(t);
    double dz = height / (2 * M_PI);
    return {dx, dy, dz};
}

