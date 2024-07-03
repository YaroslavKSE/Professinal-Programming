#pragma once

#include "Rectangle.hpp"
#include <vector>

class RectangleComparer {
public:
    static Rectangle getRectangleWithMaxArea(const std::vector<Rectangle>& rectangles);
    static Rectangle getRectangleWithMinArea(const std::vector<Rectangle>& rectangles);
    static void printPlacementPossibilities(const std::vector<Rectangle>& rectangles);
    static double getTotalArea(const std::vector<Rectangle>& rectangles);
    static void printBiggerSides(const std::vector<Rectangle>& rectangles);
};
