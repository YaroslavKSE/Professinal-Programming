#pragma once

class Triangle {
public:
    Triangle(double a, double b, double c);
    double area() const;

private:
    double a, b, c;
};
