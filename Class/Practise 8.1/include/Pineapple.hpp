#pragma once

class Pineapple {
public:
    Pineapple(double coefficient, double basePrice);

    double getCoefficient() const;
    double getBasePrice() const;

private:
    double coefficient_;
    double basePrice_;
};
