#pragma once

#include "Rectangle.hpp"
#include <vector>

class InputGetter {
public:
    static std::vector<Rectangle> getRectangles(int count);
};
