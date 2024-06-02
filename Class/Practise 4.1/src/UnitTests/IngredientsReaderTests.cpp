#include "IngredientsReader.h"
#include "UnitTests/UnitTests.hpp"
#include <fstream>
#include <sstream>

void createTestFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    file << content;
    file.close();
}

void IngredientsReader_ReadIngredients_FileParsedSuccessfully() {
    // Arrange
    createTestFile("test_ingredients.txt", "Cheese 1.5\nBacon 2.5\nTomatoes 1.0");

    // Act
    IngredientsReader reader;
    auto ingredients = reader.readIngredients("test_ingredients.txt");

    // Assert
    ASSERT_EQ(ingredients.size(), 3);
    ASSERT_EQ(ingredients["Cheese"].getCost(), 1.5);
    ASSERT_EQ(ingredients["Bacon"].getCost(), 2.5);
    ASSERT_EQ(ingredients["Tomatoes"].getCost(), 1.0);
}

void IngredientsReader_ReadIngredients_FileNotFound() {
    // Arrange
    IngredientsReader reader;

    // Act
    auto ingredients = reader.readIngredients("non_existent_file.txt");

    // Assert
    ASSERT_EQ(ingredients.size(), 0);
}

void IngredientsReader_ReadIngredients_EmptyFile() {
    // Arrange
    createTestFile("empty_ingredients.txt", "");

    // Act
    IngredientsReader reader;
    auto ingredients = reader.readIngredients("empty_ingredients.txt");

    // Assert
    ASSERT_EQ(ingredients.size(), 0);
}

void IngredientsReader_ReadIngredients_InvalidData() {
    // Arrange
    createTestFile("invalid_ingredients.txt", "Cheese abc\nBacon 2.5\nInvalidData");

    // Act
    IngredientsReader reader;
    auto ingredients = reader.readIngredients("invalid_ingredients.txt");
    
    // Assert
    ASSERT_EQ(ingredients.size(), 3);
    ASSERT_EQ(ingredients["Bacon"].getCost(), 2.5);
}

int main() {
    UnitTests testSuite;

    testSuite.addTest("IngredientsReader_ReadIngredients_FileParsedSuccessfully", IngredientsReader_ReadIngredients_FileParsedSuccessfully);
    testSuite.addTest("IngredientsReader_ReadIngredients_FileNotFound", IngredientsReader_ReadIngredients_FileNotFound);
    testSuite.addTest("IngredientsReader_ReadIngredients_EmptyFile", IngredientsReader_ReadIngredients_EmptyFile);
    testSuite.addTest("IngredientsReader_ReadIngredients_InvalidData", IngredientsReader_ReadIngredients_InvalidData);

    testSuite.run();
    return 0;
}
