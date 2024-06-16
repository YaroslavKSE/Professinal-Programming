#include "Ingredient.h"

Ingredient::Ingredient() : name(""), cost(0.0) {}

Ingredient::Ingredient(const std::string& name, double cost)
    : name(name), cost(cost) {}

std::string Ingredient::getName() const {
    return name;
}

double Ingredient::getCost() const {
    return cost;
}
