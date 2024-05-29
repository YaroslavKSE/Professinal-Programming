#include "Triangle.hpp"
#include <cmath>
#include <stdexcept>

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {
    validateSides();
}

void Triangle::validateSides() const {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw std::invalid_argument("Sides must be positive numbers.");
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw std::invalid_argument("The given sides do not form a valid triangle.");
    }
}

double Triangle::calculateArea() const {
    double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}
