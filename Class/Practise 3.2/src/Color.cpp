#include "Color.hpp"
#include <algorithm>

Color::Color(int r, int g, int b) 
    : r(std::clamp(r, 0, 255)), 
      g(std::clamp(g, 0, 255)), 
      b(std::clamp(b, 0, 255)) {}

Color Color::generateMagicColor() const {
    int newR = std::clamp((r / 2) - 1, 0, 255);
    int newG = std::clamp((g * 2) - 2, 0, 255);
    int newB = b;

    return Color(newR, newG, newB);
}

int Color::getR() const { return r; }
int Color::getG() const { return g; }
int Color::getB() const { return b; }
