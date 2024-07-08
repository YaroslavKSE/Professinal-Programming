#pragma once
#include "Rectangle.hpp"
#include <vector>

using RectangleList = std::vector<Rectangle>;

class RectangleComparer {
public:
    static Rectangle getRectangleWithMaxArea(const RectangleList& rectangles);
    static Rectangle getRectangleWithMinArea(const RectangleList& rectangles);
    static void printPlacementPossibilities(const RectangleList& rectangles);
    static double getTotalArea(const RectangleList& rectangles);
    static void printBiggerSides(const RectangleList& rectangles);
};