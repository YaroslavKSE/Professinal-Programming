#include "Cookies.hpp"

Cookies::Cookies(double coefficient, double basePrice)
    : coefficient_(coefficient), basePrice_(basePrice) {}

double Cookies::getCoefficient() const { return coefficient_; }
double Cookies::getBasePrice() const { return basePrice_; }
