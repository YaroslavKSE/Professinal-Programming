// test_Rectangle.cpp
#include "UnitTests.hpp"
#include "Rectangle.hpp"

void getArea_CorrectArea_Rectangle() {
    // arrange
    Rectangle rect(4, 5);
    
    // act
    double area = rect.getArea();
    
    // assert
    ASSERT_EQ(area, 20);
}

void getBiggerSide_CorrectBiggerSide_Rectangle() {
    // arrange
    Rectangle rect(4, 5);
    
    // act
    double biggerSide = rect.getBiggerSide();
    
    // assert
    ASSERT_EQ(biggerSide, 5);
}

void canBePlacedInside_True_SmallerRectangle() {
    // arrange
    Rectangle small(3, 4);
    Rectangle big(5, 6);
    
    // act
    bool canBePlaced = small.canBePlacedInside(big);
    
    // assert
    ASSERT_EQ(canBePlaced, true);
}

void canBePlacedInside_False_LargerRectangle() {
    // arrange
    Rectangle small(5, 6);
    Rectangle big(3, 4);
    
    // act
    bool canBePlaced = small.canBePlacedInside(big);
    
    // assert
    ASSERT_EQ(canBePlaced, false);
}

int main() {
    UnitTests tests;
    tests.addTest("getArea_CorrectArea_Rectangle", getArea_CorrectArea_Rectangle);
    tests.addTest("getBiggerSide_CorrectBiggerSide_Rectangle", getBiggerSide_CorrectBiggerSide_Rectangle);
    tests.addTest("canBePlacedInside_True_SmallerRectangle", canBePlacedInside_True_SmallerRectangle);
    tests.addTest("canBePlacedInside_False_LargerRectangle", canBePlacedInside_False_LargerRectangle);
    tests.run();
    return 0;
}
