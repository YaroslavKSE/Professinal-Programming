#pragma once

#include <concepts>

template <typename T>
concept PricedItem = requires(T t) {
    { t.getCoefficient() } -> std::same_as<double>;
    { t.getBasePrice() } -> std::same_as<double>;
};
