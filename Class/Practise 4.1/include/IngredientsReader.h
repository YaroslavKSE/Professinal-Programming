#ifndef INGREDIENTSREADER_H
#define INGREDIENTSREADER_H

#include "Ingredient.h"
#include <unordered_map>
#include <string>

class IngredientsReader {
public:
    std::unordered_map<std::string, Ingredient> readIngredients(const std::string& filename) const;

private:
    std::unordered_map<std::string, Ingredient> parseFile(const std::string& filename) const;
};

#endif // INGREDIENTSREADER_H
