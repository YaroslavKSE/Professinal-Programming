#include "PizzaBuilder.h"
#include "IngredientsReader.h"
#include "UnitTests/UnitTests.hpp"

void PizzaBuilder_AddIngredientToPizza_IngredientAddedSuccessfully() {
    // Arange
    IngredientsReader reader;
    PizzaBuilder builder(reader, "ingredients.txt");

    // Act
    builder.addIngredientToPizza("Cheese");
    Pizza* pizza = builder.getProduct();
    auto ingredients = pizza->getIngredients();

    // Assert
    ASSERT_EQ(ingredients.size(), 1);
    ASSERT_EQ(ingredients[0].getName(), "Cheese");
    delete pizza;
}

void PizzaBuilder_GetAvailableIngredients_ReturnsCorrectIngredients() {
    // Arange
    IngredientsReader reader;
    PizzaBuilder builder(reader, "ingredients.txt");

    // Act
    auto ingredients = builder.getAvailableIngredients();

    // Assert
    ASSERT_NEQ(ingredients.size(), 0);
    ASSERT_EQ(ingredients["Cheese"].getCost(), 1.5);
}

int main() {
    UnitTests testSuite;

    testSuite.addTest("PizzaBuilder_AddIngredientToPizza_IngredientAddedSuccessfully", PizzaBuilder_AddIngredientToPizza_IngredientAddedSuccessfully);
    testSuite.addTest("PizzaBuilder_GetAvailableIngredients_ReturnsCorrectIngredients", PizzaBuilder_GetAvailableIngredients_ReturnsCorrectIngredients);

    testSuite.run();
    return 0;
}
