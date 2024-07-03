// test_InputGetter.cpp
#include "UnitTests.hpp"
#include "InputGetter.hpp"
#include <sstream>
#include <iostream>

void getRectangles_CorrectNumberOfRectangles_Input() {
    // arrange
    // act
    std::vector<Rectangle> rectangles = InputGetter::getRectangles(2);
    
    // assert
    ASSERT_EQ(rectangles.size(), 2);
}
void getRectangles_CorrectDimensions_Input() {
    // arrange
    std::istringstream input("3 3\n");
    std::cin.rdbuf(input.rdbuf());
    
    // act
    std::vector<Rectangle> rectangles = InputGetter::getRectangles(1);
    
    // assert
    ASSERT_EQ(rectangles[0].getArea(), 9);
    ASSERT_EQ(rectangles[0].getBiggerSide(), 3);
}
int main() {
    UnitTests tests;
    tests.addTest("getRectangles_CorrectNumberOfRectangles_Input", getRectangles_CorrectNumberOfRectangles_Input);
    tests.addTest("getRectangles_CorrectDimensions_Input", getRectangles_CorrectDimensions_Input);
    tests.run();
    return 0;
}
