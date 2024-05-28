#include "Triangle.hpp"
#include "Color.hpp"
#include "UnitTests.hpp"
#include <cmath>

int main() {
    UnitTests testSuite;

    // Tests for Triangle::calculateArea
    testSuite.addTest("calculateArea_CorrectlyCalculatesArea_RightAngledTriangle", []() {
        // Arrange
        Triangle triangle(3, 4, 5);
        
        // Act
        double result = triangle.calculateArea();
        
        // Assert
        ASSERT_EQ(result, 6.0);
    });

    testSuite.addTest("calculateArea_CorrectlyCalculatesArea_EquilateralTriangle", []() {
        // Arrange
        Triangle triangle(5, 5, 5);
        
        // Act
        double result = triangle.calculateArea();
        
        // Assert
        double expectedArea = (sqrt(3) / 4) * 25; 
        ASSERT_EQ(result, expectedArea);
    });

    testSuite.addTest("calculateArea_CorrectlyCalculatesArea_IsoscelesTriangle", []() {
        // Arrange
        Triangle triangle(5, 5, 8);
        
        // Act
        double result = triangle.calculateArea();
        
        // Assert
        double s = (5 + 5 + 8) / 2.0;
        double expectedArea = sqrt(s * (s - 5) * (s - 5) * (s - 8));
        ASSERT_EQ(result, expectedArea);
    });

    testSuite.addTest("calculateArea_CorrectlyCalculatesArea_ScaleneTriangle", []() {
        // Arrange
        Triangle triangle(7, 10, 5);
        
        // Act
        double result = triangle.calculateArea();
        
        // Assert
        double s = (7 + 10 + 5) / 2.0;
        double expectedArea = sqrt(s * (s - 7) * (s - 10) * (s - 5));
        ASSERT_EQ(result, expectedArea);
    });

    testSuite.addTest("calculateArea_ThrowsException_InvalidSides", []() {
        // Arrange & Act & Assert
        try {
            Triangle triangle(1, 2, 10);
        } catch (const std::invalid_argument& e) {
            ASSERT_EQ(std::string(e.what()), "The given sides do not form a valid triangle.");
        }
    });

        testSuite.addTest("calculateArea_ThrowsException_NegativeNumbers", []() {
        // Arrange & Act & Assert
        try {
            Triangle triangle(-5, 8, 10);
        } catch (const std::invalid_argument& e) {
            ASSERT_EQ(std::string(e.what()), "Sides must be positive numbers.");
        }
    });

    // Tests for Color::generateMagicColor
    testSuite.addTest("generateMagicColor_CorrectlyGeneratesColor_ValidColor", []() {
        // Arrange
        Color color(10, 10, 10);
        
        // Act
        Color magicColor = color.generateMagicColor();
        
        // Assert
        ASSERT_EQ(magicColor.getR(), 4);
        ASSERT_EQ(magicColor.getG(), 18);
        ASSERT_EQ(magicColor.getB(), 10);
    });

    testSuite.addTest("generateMagicColor_CorrectlyGeneratesColor_MaxValues", []() {
        // Arrange
        Color color(255, 255, 255);
        
        // Act
        Color magicColor = color.generateMagicColor();
        
        // Assert
        ASSERT_EQ(magicColor.getR(), 126);
        ASSERT_EQ(magicColor.getG(), 255); // Clamped to 255
        ASSERT_EQ(magicColor.getB(), 255);
    });

    testSuite.addTest("generateMagicColor_CorrectlyGeneratesColor_ZeroValues", []() {
        // Arrange
        Color color(0, 0, 0);
        
        // Act
        Color magicColor = color.generateMagicColor();
        
        // Assert
        ASSERT_EQ(magicColor.getR(), 0); // Clamped to 0
        ASSERT_EQ(magicColor.getG(), 0);
        ASSERT_EQ(magicColor.getB(), 0);
    });

    testSuite.run();
}
