#include "Pizza.h"
#include <iostream>
#include <print>

void Pizza::addIngredient(const Ingredient& ingredient) {
    ingredients.push_back(ingredient);
}

void Pizza::printPizza() const {
    double totalCost = 0;
    std::println("Your pizza ingredients:");
    for (const auto& ingredient : ingredients) {
        std::println("- {} (${})", ingredient.getName(), ingredient.getCost());
        totalCost += ingredient.getCost();
    }
    std::println("Total cost: ${}", totalCost);
}

std::vector<Ingredient> Pizza::getIngredients() const {
    return ingredients;
}

double Pizza::getTotalCost() const {
    double totalCost = 0;
    for (const auto& ingredient : ingredients) {
        totalCost += ingredient.getCost();
    }
    return totalCost;
}
