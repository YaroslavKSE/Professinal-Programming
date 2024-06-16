#include "PizzaBuilder.h"
#include <iostream>
#include <print>

PizzaBuilder::PizzaBuilder(const IngredientsReader& reader, const std::string& filename) {
    availableIngredients = reader.readIngredients(filename);
    this->reset();
}

void PizzaBuilder::showIngredients() const {
    std::println("Available ingredients:");
    for (const auto& pair : availableIngredients) {
        std::println("- {} (${})", pair.first, pair.second.getCost());
    }
}

void PizzaBuilder::addIngredientToPizza(const std::string& ingredientName) {
    if (availableIngredients.find(ingredientName) != availableIngredients.end()) {
        pizza->addIngredient(availableIngredients.at(ingredientName));
    } else {
        std::println("Ingredient not found: {}", ingredientName);
    }
}

std::unique_ptr<Pizza> PizzaBuilder::getProduct() {
    auto result = std::move(pizza);
    this->reset();
    return result;
}

void PizzaBuilder::reset() {
    this->pizza = std::make_unique<Pizza>();
}

std::unordered_map<std::string, Ingredient> PizzaBuilder::getAvailableIngredients() const {
    return availableIngredients;
}
