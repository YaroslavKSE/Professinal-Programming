#include "Rectangle.hpp"
#include "InputGetter.hpp"
#include "RectangleComparer.hpp"
#include <iostream>
#include <print>

int main() {
    const int rectangleCount = 5;
    std::vector<Rectangle> rectangles = InputGetter::getRectangles(rectangleCount);

    Rectangle biggestRectangle = RectangleComparer::getRectangleWithMaxArea(rectangles);
    Rectangle smallestRectangle = RectangleComparer::getRectangleWithMinArea(rectangles);

    std::println("The biggest area: {}", biggestRectangle.getArea());
    std::println("The smallest area: {}", smallestRectangle.getArea());

    RectangleComparer::printPlacementPossibilities(rectangles);
    RectangleComparer::printBiggerSides(rectangles);

    std::println("Total area of rectangles: {}", RectangleComparer::getTotalArea(rectangles));

    return 0;
}
