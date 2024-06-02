#include "Ingredient.h"
#include "UnitTests/UnitTests.hpp"

void Ingredient_DefaultConstructor_InitializesWithDefaultValues() {
    Ingredient ingredient;
    ASSERT_EQ(ingredient.getName(), "");
    ASSERT_EQ(ingredient.getCost(), 0.0);
}

void Ingredient_ParameterizedConstructor_InitializesWithProvidedValues() {
    Ingredient ingredient("Cheese", 1.5);
    ASSERT_EQ(ingredient.getName(), "Cheese");
    ASSERT_EQ(ingredient.getCost(), 1.5);
}

int main() {
    UnitTests testSuite;

    testSuite.addTest("Ingredient_DefaultConstructor_InitializesWithDefaultValues", Ingredient_DefaultConstructor_InitializesWithDefaultValues);
    testSuite.addTest("Ingredient_ParameterizedConstructor_InitializesWithProvidedValues", Ingredient_ParameterizedConstructor_InitializesWithProvidedValues);

    testSuite.run();
    return 0;
}
