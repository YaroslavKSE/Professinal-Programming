#include "PizzaBuilder.h"
#include "IngredientsReader.h"
#include <iostream>
#include <string>
#include <print>

namespace {
    const std::string ingredientsFile = "ingredients.txt";
    const std::string doneCommand = "done";
    const std::string listCommand = "list";
}

int main() {
    IngredientsReader reader;
    PizzaBuilder builder(reader, ingredientsFile);

    std::string input;
    while (true) {
        std::print("Enter an ingredient (or 'done' to finish, 'list' to show ingredients): ");
        std::getline(std::cin, input);

        if (input == doneCommand) {
            break;
        } else if (input == listCommand) {
            builder.showIngredients();
        } else {
            builder.addIngredientToPizza(input);
        }
    }

    Pizza* pizza = builder.getProduct();
    pizza->printPizza();
    delete pizza;

    return 0;
}
