#pragma once

#include "Ingredient.h"
#include <vector>
#include <string>

class Pizza {
public:
    void addIngredient(const Ingredient& ingredient);
    void printPizza() const;
    [[nodiscard]] std::vector<Ingredient> getIngredients() const;
    [[nodiscard]] double getTotalCost() const;

private:
    std::vector<Ingredient> ingredients;
};
