#pragma once

#include "curve.h"

#include <vector>
#include <cmath>

class Ellipse : public Curve3D
{
private:
    double majorAxis;
    double minorAxis;

public:
    Ellipse(double a, double b) : majorAxis(a), minorAxis(b) {}
    ~Ellipse() {}

    double getParameterRange() override { return 2 * M_PI; }
    double getParameterStep() override { return 0.01; }

    std::vector<double> getPoint(double t) override;
    std::vector<double> getDerivative(double t) override;
};


