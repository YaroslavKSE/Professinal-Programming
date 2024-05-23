#include "Helpers.hpp"
#include <algorithm> // for std::max_element
#include <numeric>   // for std::accumulate

double dummyFunc(double x) {
    return x > 0 ? x : 0;
}

std::string repeatString(const std::vector<int>& vec, const std::string& str) {
    auto repeatCount = vec.empty() ? 0 : std::ranges::max(vec);
    return repeatCount > 0
        ? std::views::repeat(str) | std::views::take(repeatCount) | std::views::join | std::ranges::to<std::string>()
        : "";
}