
#include "curve.h"
#include <cmath>

class Circle : public Curve3D {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    ~Circle() {}

    double getParameterRange() override { return 2 * M_PI; }
    double getParameterStep() override { return 0.01; }
    double getRadius() { return radius; }

    std::vector<double> getPoint(double t) override;
    std::vector<double> getDerivative(double t) override;

};


