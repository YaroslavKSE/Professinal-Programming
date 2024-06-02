#ifndef PIZZA_H
#define PIZZA_H

#include "Ingredient.h"
#include <vector>
#include <string>

class Pizza {
public:
    void addIngredient(const Ingredient& ingredient);
    void printPizza() const;
    std::vector<Ingredient> getIngredients() const;
    double getTotalCost() const;

private:
    std::vector<Ingredient> ingredients;
};

#endif // PIZZA_H
