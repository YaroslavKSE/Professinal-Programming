#ifndef PIZZABUILDER_H
#define PIZZABUILDER_H

#include "Pizza.h"
#include "IngredientsReader.h"
#include <unordered_map>
#include <string>

class PizzaBuilder {
public:
    PizzaBuilder(const IngredientsReader& reader, const std::string& filename);
    void showIngredients() const;
    void addIngredientToPizza(const std::string& ingredientName);
    Pizza* getProduct();
    void reset();

    std::unordered_map<std::string, Ingredient> getAvailableIngredients() const;

private:
    Pizza* pizza;
    std::unordered_map<std::string, Ingredient> availableIngredients;
};

#endif // PIZZABUILDER_H
