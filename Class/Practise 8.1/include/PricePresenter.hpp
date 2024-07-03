#pragma once

#include "Concept.hpp"
#include <iostream>

template <size_t PRIORITY>
class PricePresenter {
public:
    PricePresenter() = default;

    template <PricedItem T1, PricedItem T2>
    void printTotalPrice(const T1& obj1, const T2& obj2) const;
};

#include "PricePresenter.tpp"
