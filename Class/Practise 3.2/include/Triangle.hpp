#pragma once

class Triangle {
public:
    Triangle(double a, double b, double c);
    [[nodiscard]] double calculateArea() const;

private:
    double a, b, c;
    void validateSides() const;
};
