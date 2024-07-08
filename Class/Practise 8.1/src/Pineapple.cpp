#include "Pineapple.hpp"

Pineapple::Pineapple(double coefficient, double basePrice)
    : coefficient_(coefficient), basePrice_(basePrice) {}

double Pineapple::getCoefficient() const { return coefficient_; }
double Pineapple::getBasePrice() const { return basePrice_; }
