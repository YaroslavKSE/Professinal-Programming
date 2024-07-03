// test_RectangleComparer.cpp
#include "UnitTests.hpp"
#include "RectangleComparer.hpp"

void getRectangleWithMaxArea_CorrectRectangle_Rectangles() {
    // arrange
    std::vector<Rectangle> rectangles = {Rectangle(1, 2), Rectangle(2, 3), Rectangle(3, 4)};
    
    // act
    Rectangle maxAreaRectangle = RectangleComparer::getRectangleWithMaxArea(rectangles);
    
    // assert
    ASSERT_EQ(maxAreaRectangle.getArea(), 12);
}

void getRectangleWithMinArea_CorrectRectangle_Rectangles() {
    // arrange
    std::vector<Rectangle> rectangles = {Rectangle(1, 2), Rectangle(2, 3), Rectangle(3, 4)};
    
    // act
    Rectangle minAreaRectangle = RectangleComparer::getRectangleWithMinArea(rectangles);
    
    // assert
    ASSERT_EQ(minAreaRectangle.getArea(), 2);
}

void printPlacementPossibilities_CorrectOutput_Rectangles() {
    // arrange
    std::vector<Rectangle> rectangles = {Rectangle(1, 2), Rectangle(2, 3)};
    
    // act
    RectangleComparer::printPlacementPossibilities(rectangles);
    // assert
    // Manual verification or redirection of std::println to a test log
}

void getTotalArea_CorrectTotalArea_Rectangles() {
    // arrange
    std::vector<Rectangle> rectangles = {Rectangle(1, 2), Rectangle(2, 3)};
    
    // act
    double totalArea = RectangleComparer::getTotalArea(rectangles);
    
    // assert
    ASSERT_EQ(totalArea, 8);
}

int main() {
    UnitTests tests;
    tests.addTest("getRectangleWithMaxArea_CorrectRectangle_Rectangles", getRectangleWithMaxArea_CorrectRectangle_Rectangles);
    tests.addTest("getRectangleWithMinArea_CorrectRectangle_Rectangles", getRectangleWithMinArea_CorrectRectangle_Rectangles);
    tests.addTest("printPlacementPossibilities_CorrectOutput_Rectangles", printPlacementPossibilities_CorrectOutput_Rectangles);
    tests.addTest("getTotalArea_CorrectTotalArea_Rectangles", getTotalArea_CorrectTotalArea_Rectangles);
    tests.run();
    return 0;
}
