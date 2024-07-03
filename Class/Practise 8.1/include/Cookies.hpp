#pragma once

class Cookies {
public:
    Cookies(double coefficient, double basePrice)
        : coefficient_(coefficient), basePrice_(basePrice) {}

    double getCoefficient() const { return coefficient_; }
    double getBasePrice() const { return basePrice_; }

private:
    double coefficient_;
    double basePrice_;
};
