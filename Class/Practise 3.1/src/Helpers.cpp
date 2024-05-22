#include "Helpers.hpp"
#include <algorithm> // for std::max_element
#include <numeric>   // for std::accumulate

double dummyFunc(double x) {
    return x > 0 ? x : 0;
}

std::string repeatString(const std::vector<int>& vec, const std::string& str) {
    if (vec.empty()) {
        return "";
    }
    int maxVal = *std::max_element(vec.begin(), vec.end());
    std::string result;
    for (int i = 0; i < maxVal; ++i) {
        result += str;
    }
    return result;
}