#include "RectangleComparer.hpp"
#include <algorithm>
#include <numeric>
#include <print>

Rectangle RectangleComparer::getRectangleWithMaxArea(const RectangleList& rectangles) {
    if (rectangles.empty()) {
        throw std::runtime_error("Empty rectangle list");
    }
    return *std::max_element(rectangles.begin(), rectangles.end(), [](const Rectangle& a, const Rectangle& b) {
        return a.getArea() < b.getArea();
    });
}

Rectangle RectangleComparer::getRectangleWithMinArea(const RectangleList& rectangles) {
    if (rectangles.empty()) {
        throw std::runtime_error("Empty rectangle list");
    }
    return *std::min_element(rectangles.begin(), rectangles.end(), [](const Rectangle& a, const Rectangle& b) {
        return a.getArea() < b.getArea();
    });
}

void RectangleComparer::printPlacementPossibilities(const RectangleList& rectangles) {
    for (size_t i = 0; i < rectangles.size(); ++i) {
        for (size_t j = 0; j < rectangles.size(); ++j) {
            if (i != j && rectangles[i].canBePlacedInside(rectangles[j])) {
                std::println("Rectangle {} can be placed inside Rectangle {}", i + 1, j + 1);
            }
        }
    }
}

double RectangleComparer::getTotalArea(const RectangleList& rectangles) {
    return std::accumulate(rectangles.begin(), rectangles.end(), 0.0, 
        [](double sum, const Rectangle& rect) { return sum + rect.getArea(); });
}

void RectangleComparer::printBiggerSides(const RectangleList& rectangles) {
    for (size_t i = 0; i < rectangles.size(); ++i) {
        std::println("The biggest side of rectangle {}: {}", i + 1, rectangles[i].getBiggerSide());
    }
}