#include "RectangleComparer.hpp"
#include <algorithm>
#include <print>

Rectangle RectangleComparer::getRectangleWithMaxArea(const std::vector<Rectangle>& rectangles) {
    return *std::max_element(rectangles.begin(), rectangles.end(), [](const Rectangle& a, const Rectangle& b) {
        return a.getArea() < b.getArea();
    });
}

Rectangle RectangleComparer::getRectangleWithMinArea(const std::vector<Rectangle>& rectangles) {
    return *std::min_element(rectangles.begin(), rectangles.end(), [](const Rectangle& a, const Rectangle& b) {
        return a.getArea() < b.getArea();
    });
}

void RectangleComparer::printPlacementPossibilities(const std::vector<Rectangle>& rectangles) {
    for (size_t i = 0; i < rectangles.size(); ++i) {
        for (size_t j = 0; j < rectangles.size(); ++j) {
            if (i != j && rectangles[i].canBePlacedInside(rectangles[j])) {
                std::println("Rectangle {} can be placed inside Rectangle {}", i + 1, j + 1);
            }
        }
    }
}

double RectangleComparer::getTotalArea(const std::vector<Rectangle>& rectangles) {
    double totalArea = 0;
    for (const auto& rect : rectangles) {
        totalArea += rect.getArea();
    }
    return totalArea;
}

void RectangleComparer::printBiggerSides(const std::vector<Rectangle>& rectangles) {
    for (size_t i = 0; i < rectangles.size(); ++i) {
        std::println("The biggest side of rectangle {}: {}", i + 1, rectangles[i].getBiggerSide());
    }
}
