#pragma once

#include <vector>

// Abstract base class for 3D curves
class Curve3D {
public:
    virtual double getParameterRange() = 0;
    virtual double getParameterStep() = 0;
    virtual std::vector<double> getPoint(double t) = 0;
    virtual std::vector<double> getDerivative(double t) = 0;
    virtual ~Curve3D() {};
};


