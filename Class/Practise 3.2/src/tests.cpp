#include "Triangle.hpp"
#include "Color.hpp"
#include "UnitTests.hpp"

int main() {
    UnitTests testSuite;

    // Tests for Triangle::area
    testSuite.addTest("Triangle_AreaWithSidesThreeFourFive_ReturnsSix", []() {
        // Arrange
        Triangle triangle(3, 4, 5);
        
        // Act
        double result = triangle.area();
        
        // Assert
        ASSERT_EQ(result, 6.0);
    });

    testSuite.addTest("Triangle_AreaWithSidesSixEightTen_ReturnsTwentyFour", []() {
        // Arrange
        Triangle triangle(6, 8, 10);
        
        // Act
        double result = triangle.area();
        
        // Assert
        ASSERT_EQ(result, 24.0);
    });

    testSuite.addTest("Triangle_AreaWithSidesFiveTwelveThirteen_ReturnsThirty", []() {
        // Arrange
        Triangle triangle(5, 12, 13);
        
        // Act
        double result = triangle.area();
        
        // Assert
        ASSERT_EQ(result, 30.0);
    });

    // Tests for Color::magicColor
    testSuite.addTest("Color_MagicColorWithTenTenTen_ReturnsFourEighteenTen", []() {
        // Arrange
        Color color(10, 10, 10);
        
        // Act
        Color magic = color.magicColor();
        
        // Assert
        ASSERT_EQ(magic.getR(), 4);
        ASSERT_EQ(magic.getG(), 18);
        ASSERT_EQ(magic.getB(), 10);
    });

    testSuite.addTest("Color_MagicColorWithMaxValues_ReturnsClampedValues", []() {
        // Arrange
        Color color(255, 255, 255);
        
        // Act
        Color magic = color.magicColor();
        
        // Assert
        ASSERT_EQ(magic.getR(), 126);
        ASSERT_EQ(magic.getG(), 255); // Clamped to 255
        ASSERT_EQ(magic.getB(), 255);
    });

    testSuite.addTest("Color_MagicColorWithZeroValues_ReturnsClampedToZero", []() {
        // Arrange
        Color color(0, 0, 0);
        
        // Act
        Color magic = color.magicColor();
        
        // Assert
        ASSERT_EQ(magic.getR(), 0); // Clamped to 0
        ASSERT_EQ(magic.getG(), 0);
        ASSERT_EQ(magic.getB(), 0);
    });

    testSuite.run();
}
