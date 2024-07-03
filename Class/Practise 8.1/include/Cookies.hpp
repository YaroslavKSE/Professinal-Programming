#pragma once

class Cookies {
public:
    Cookies(double coefficient, double basePrice);

    double getCoefficient() const;
    double getBasePrice() const;

private:
    double coefficient_;
    double basePrice_;
};
