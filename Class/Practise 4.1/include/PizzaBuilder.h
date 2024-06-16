#pragma once

#include "Pizza.h"
#include "IngredientsReader.h"
#include <unordered_map>
#include <string>
#include <memory>

class PizzaBuilder {
public:
    PizzaBuilder(const IngredientsReader& reader, const std::string& filename);
    void showIngredients() const;
    void addIngredientToPizza(const std::string& ingredientName);
    [[nodiscard]] std::unique_ptr<Pizza> getProduct();
    void reset();

    [[nodiscard]] std::unordered_map<std::string, Ingredient> getAvailableIngredients() const;

private:
    std::unique_ptr<Pizza> pizza;
    std::unordered_map<std::string, Ingredient> availableIngredients;
};
