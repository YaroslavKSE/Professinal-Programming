#include "Rectangle.hpp"
#include <algorithm>

Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

double Rectangle::getArea() const {
    return width * height;
}

double Rectangle::getBiggerSide() const {
    return std::max(width, height);
}

bool Rectangle::canBePlacedInside(const Rectangle& other) const {
    return width <= other.width && height <= other.height;
}
