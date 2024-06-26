#pragma once

#include <array>

class MegaData {
public:
    std::array<float, 1024> smallArray;
    std::array<double, 1024 * 1024> bigArray;

    MegaData();

    void reset();
};