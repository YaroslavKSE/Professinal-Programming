#include "Pizza.h"
#include <print>
#include <iostream>
#include <numeric>

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
    return std::accumulate(ingredients.begin(), ingredients.end(), 0.0, [](double sum, const Ingredient& ingredient) {
        return sum + ingredient.getCost();
    });
}
