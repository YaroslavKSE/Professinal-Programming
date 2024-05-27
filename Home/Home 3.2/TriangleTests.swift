import XCTest

class TriangleTests: XCTestCase {
    
    private let doubleAccuracy = 1e-9
    
    func testArea_WithSidesThreeFourFive_ReturnsSix() {
        // Arrange
        let triangle = Triangle(a: 3, b: 4, c: 5)
        
        // Act
        let result = triangle.area()
        
        // Assert
        XCTAssertEqual(result, 6.0, accuracy: doubleAccuracy)
    }
    
    func testArea_WithSidesSixEightTen_ReturnsTwentyFour() {
        // Arrange
        let triangle = Triangle(a: 6, b: 8, c: 10)
        
        // Act
        let result = triangle.area()
        
        // Assert
        XCTAssertEqual(result, 24.0, accuracy: doubleAccuracy)
    }
    
    func testArea_WithSidesFiveTwelveThirteen_ReturnsThirty() {
        // Arrange
        let triangle = Triangle(a: 5, b: 12, c: 13)
        
        // Act
        let result = triangle.area()
        
        // Assert
        XCTAssertEqual(result, 30.0, accuracy: doubleAccuracy)
    }
    
    func testHeight_ForSideA_ReturnsCorrectHeight() {
        // Arrange
        let triangle = Triangle(a: 3, b: 4, c: 5)
        
        // Act
        let result = triangle.height(for: "a")
        
        // Assert
        XCTAssertNotNil(result)
        XCTAssertEqual(result!, 4.0, accuracy: doubleAccuracy)
    }
    
    func testHeight_ForSideB_ReturnsCorrectHeight() {
        // Arrange
        let triangle = Triangle(a: 6, b: 8, c: 10)
        
        // Act
        let result = triangle.height(for: "b")
        
        // Assert
        XCTAssertNotNil(result)
        XCTAssertEqual(result!, 6.0, accuracy: doubleAccuracy)
    }
    
    func testHeight_ForSideC_ReturnsCorrectHeight() {
        // Arrange
        let triangle = Triangle(a: 5, b: 12, c: 13)
        
        // Act
        let result = triangle.height(for: "c")
        
        // Assert
        XCTAssertNotNil(result)
        XCTAssertEqual(result!, 4.615384615384615, accuracy: doubleAccuracy) 
    }
}

#if os(Linux)
extension TriangleTests {
    static var allTests = [
        ("testArea_WithSidesThreeFourFive_ReturnsSix", testArea_WithSidesThreeFourFive_ReturnsSix),
        ("testArea_WithSidesSixEightTen_ReturnsTwentyFour", testArea_WithSidesSixEightTen_ReturnsTwentyFour),
        ("testArea_WithSidesFiveTwelveThirteen_ReturnsThirty", testArea_WithSidesFiveTwelveThirteen_ReturnsThirty),
        ("testHeight_ForSideA_ReturnsCorrectHeight", testHeight_ForSideA_ReturnsCorrectHeight),
        ("testHeight_ForSideB_ReturnsCorrectHeight", testHeight_ForSideB_ReturnsCorrectHeight),
        ("testHeight_ForSideC_ReturnsCorrectHeight", testHeight_ForSideC_ReturnsCorrectHeight),
    ]
}
#endif
