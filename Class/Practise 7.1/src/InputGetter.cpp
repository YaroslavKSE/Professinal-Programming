#include "InputGetter.hpp"
#include <iostream>
#include <print> 

std::vector<Rectangle> InputGetter::getRectangles(int count) {
    std::vector<Rectangle> rectangles;
    double width, height;

    for (int i = 0; i < count; ++i) {
        std::println("Enter rectangle {}:", i + 1);
        std::cin >> width >> height;
        rectangles.emplace_back(width, height);
    }

    return rectangles;
}
