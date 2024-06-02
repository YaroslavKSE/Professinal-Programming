#include "IngredientsReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::unordered_map<std::string, Ingredient> IngredientsReader::readIngredients(const std::string& filename) const {
    return parseFile(filename);
}

std::unordered_map<std::string, Ingredient> IngredientsReader::parseFile(const std::string& filename) const {
    std::unordered_map<std::string, Ingredient> ingredients;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
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
            std::cerr << "Invalid line format: " << line << std::endl;
        }
    }
    return ingredients;
}
