import XCTest

class TriangleTests: XCTestCase {
    
    private let doubleAccuracy = 1e-9
    
    func testCalculateArea_CorrectlyCalculatesArea_RightAngledTriangle() {
        // Arrange
        let triangle = try! Triangle(a: 3, b: 4, c: 5)
        
        // Act
        let result = triangle.calculateArea()
        
        // Assert
        XCTAssertEqual(result, 6.0, accuracy: doubleAccuracy)
    }
    
    func testCalculateArea_CorrectlyCalculatesArea_EquilateralTriangle() {
        // Arrange
        let triangle = try! Triangle(a: 5, b: 5, c: 5)
        
        // Act
        let result = triangle.calculateArea()
        
        // Assert
        let expectedArea = 10.8253175473
        XCTAssertEqual(result, expectedArea, accuracy: doubleAccuracy)
    }
    
    func testCalculateArea_CorrectlyCalculatesArea_IsoscelesTriangle() {
        // Arrange
        let triangle = try! Triangle(a: 5, b: 5, c: 8)
        
        // Act
        let result = triangle.calculateArea()
        
        // Assert
        let expectedArea = 12.0
        XCTAssertEqual(result, expectedArea, accuracy: doubleAccuracy)
    }
    
    func testCalculateArea_CorrectlyCalculatesArea_ScaleneTriangle() {
        // Arrange
        let triangle = try! Triangle(a: 7, b: 10, c: 5)
        
        // Act
        let result = triangle.calculateArea()
        
        // Assert
        let expectedArea = 16.2480768093
        XCTAssertEqual(result, expectedArea, accuracy: doubleAccuracy)
    }
    
    func testCalculateArea_ThrowsError_InvalidSides() {
        // Arrange & Act & Assert
        XCTAssertThrowsError(try Triangle(a: -5, b: 8, c: 10)) { error in
            XCTAssertEqual(error as? TriangleError, TriangleError.invalidSides("Sides must be positive numbers."))
        }
        
        XCTAssertThrowsError(try Triangle(a: 1, b: 2, c: 10)) { error in
            XCTAssertEqual(error as? TriangleError, TriangleError.invalidSides("The given sides do not form a valid triangle."))
        }
    }
    
    func testHeightForSide_CorrectlyCalculatesHeight_ValidSideA() {
        // Arrange
        let triangle = try! Triangle(a: 3, b: 4, c: 5)
        
        // Act
        let result = triangle.height(for: .a)
        
        // Assert
        XCTAssertEqual(result, 4.0, accuracy: doubleAccuracy)
    }

    func testHeightForSide_CorrectlyCalculatesHeight_ValidSideB() {
        // Arrange
        let triangle = try! Triangle(a: 6, b: 8, c: 10)
        
        // Act
        let result = triangle.height(for: .b)
        
        // Assert
        XCTAssertEqual(result, 6.0, accuracy: doubleAccuracy)
    }
    
    func testHeightForSide_CorrectlyCalculatesHeight_ValidSideC() {
        // Arrange
        let triangle = try! Triangle(a: 5, b: 12, c: 13)
        
        // Act
        let result = triangle.height(for: .c)
        
        // Assert
        XCTAssertEqual(result, 4.615384615384615, accuracy: doubleAccuracy) 
    }   
}

#if os(Linux)
extension TriangleTests {
    static var allTests = [
        ("testCalculateArea_CorrectlyCalculatesArea_RightAngledTriangle", testCalculateArea_CorrectlyCalculatesArea_RightAngledTriangle),
        ("testCalculateArea_CorrectlyCalculatesArea_EquilateralTriangle", testCalculateArea_CorrectlyCalculatesArea_EquilateralTriangle),
        ("testCalculateArea_CorrectlyCalculatesArea_IsoscelesTriangle", testCalculateArea_CorrectlyCalculatesArea_IsoscelesTriangle),
        ("testCalculateArea_CorrectlyCalculatesArea_ScaleneTriangle", testCalculateArea_CorrectlyCalculatesArea_ScaleneTriangle),
        ("testCalculateArea_ThrowsError_InvalidSides", testCalculateArea_ThrowsError_InvalidSides),
        ("testHeightForSide_CorrectlyCalculatesHeight_ValidSideA", testHeightForSide_CorrectlyCalculatesHeight_ValidSideA),
        ("testHeightForSide_CorrectlyCalculatesHeight_ValidSideB", testHeightForSide_CorrectlyCalculatesHeight_ValidSideB),
        ("testHeightForSide_CorrectlyCalculatesHeight_ValidSideC", testHeightForSide_CorrectlyCalculatesHeight_ValidSideC),
    ]
}
#endif
