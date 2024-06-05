#pragma once

#include "Ingredient.h"
#include <unordered_map>
#include <string>

class IngredientsReader {
public:
    static std::unordered_map<std::string, Ingredient> readIngredients(const std::string& filename);
};
