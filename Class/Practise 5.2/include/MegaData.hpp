#pragma once

#include <array>
#include <algorithm>

class MegaData {
public:
    MegaData() {
        reset();
    }

    void reset() {
        std::fill(smallArray.begin(), smallArray.end(), 42.0f);
        std::fill(bigArray.begin(), bigArray.end(), 42.0);
    }

    const std::array<float, 1024>& getSmallArray() const {
        return smallArray;
    }

    const std::array<double, 1024 * 1024>& getBigArray() const {
        return bigArray;
    }

private:
    std::array<float, 1024> smallArray;
    std::array<double, 1024 * 1024> bigArray;
};
