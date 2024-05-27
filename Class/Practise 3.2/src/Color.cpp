#include "Color.hpp"
#include <cmath>

Color::Color(int r, int g, int b) : r(r), g(g), b(b) {}

Color Color::magicColor() const {
    int newR = (r / 2) - 1;
    int newG = (g * 2) - 2;
    int newB = b;

    // Ensure the values are within the range [0, 255]
    newR = std::max(0, std::min(255, newR));
    newG = std::max(0, std::min(255, newG));

    return Color(newR, newG, newB);
}

int Color::getR() const { return r; }
int Color::getG() const { return g; }
int Color::getB() const { return b; }
