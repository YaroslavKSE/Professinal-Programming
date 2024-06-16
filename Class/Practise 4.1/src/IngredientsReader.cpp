#include "IngredientsReader.h"
#include <print>
#include <fstream>
#include <sstream>
#include <iostream>

std::unordered_map<std::string, Ingredient> IngredientsReader::readIngredients(const std::string& filename) {
    std::unordered_map<std::string, Ingredient> ingredients;
    std::ifstream file(filename);
    if (!file) {
        std::println(stderr, "Unable to open file: {}", filename);
        return ingredients;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        double cost;
        if (iss >> name >> cost) {
            ingredients[name] = Ingredient(name, cost);
        } else {
            std::println(stderr, "Invalid line format: {}", line);
        }
    }
    return ingredients;
}
