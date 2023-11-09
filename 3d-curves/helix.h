#pragma once

#include "curve.h"

#include <vector>
#include <cmath>

class Helix : public Curve3D
{
private:
    double radius;
    double height;

public:
    Helix(double r, double h) : radius(r), height(h) {}
    ~Helix() {}

    double getParameterRange() override { return 2 * M_PI; }
    double getParameterStep() override { return 0.01; }

    std::vector<double> getPoint(double t) override;
    std::vector<double> getDerivative(double t) override;
};

