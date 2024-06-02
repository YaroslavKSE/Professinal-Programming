#include "Pizza.h"
#include "Ingredient.h"
#include "UnitTests/UnitTests.hpp"
#include <sstream>
#include <iostream>

void Pizza_AddIngredient_IncreasesIngredientCount() {
    // Arange
    Pizza pizza;
    Ingredient cheese("Cheese", 1.5);

    // Act
    pizza.addIngredient(cheese);

    // Assert
    ASSERT_EQ(pizza.getIngredients().size(), 1);
}

void Pizza_GetTotalCost_CalculatesCorrectCost() {
    // Arange
    Pizza pizza;
    Ingredient cheese("Cheese", 1.5);
    Ingredient bacon("Bacon", 2.5);

    // Act
    pizza.addIngredient(cheese);
    pizza.addIngredient(bacon);
    
    // Assert
    ASSERT_EQ(pizza.getTotalCost(), 4.0);
}

int main() {
    UnitTests testSuite;

    testSuite.addTest("Pizza_AddIngredient_IncreasesIngredientCount", Pizza_AddIngredient_IncreasesIngredientCount);
    testSuite.addTest("Pizza_GetTotalCost_CalculatesCorrectCost", Pizza_GetTotalCost_CalculatesCorrectCost);

    testSuite.run();
    return 0;
}