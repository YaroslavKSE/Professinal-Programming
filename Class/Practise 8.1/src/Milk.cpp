#include "Milk.hpp"

Milk::Milk(double coefficient, double basePrice)
    : coefficient_(coefficient), basePrice_(basePrice) {}

double Milk::getCoefficient() const { return coefficient_; }
double Milk::getBasePrice() const { return basePrice_; }
