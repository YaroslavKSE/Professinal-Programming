#pragma once

#include "Concept.hpp"
#include <iostream>
#include <print>

template <size_t PRIORITY>
class PricePresenter {
public:
    PricePresenter() = default;

    template <PricedItem T1, PricedItem T2>
    void printTotalPrice(const T1& obj1, const T2& obj2) const {
        double totalPrice = PRIORITY * obj1.getCoefficient() * obj1.getBasePrice()
                          + obj2.getCoefficient() * obj2.getBasePrice();
        std::println("Total Price: {}", totalPrice);
    }
};
