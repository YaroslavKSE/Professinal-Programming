import XCTest
@testable import CalculateInverseOrAlternative

class CalculateInverseOrAlternativeTests: XCTestCase {

    // Constant for accuracy
    private let doubleAccuracy = 1e-9

    func testInverseOfProduct() {
        // Arrange
        let result = calculateInverseOrAlternative(x: 2.0, y: 3.0, z: 4.0)
        
        // Assert
        XCTAssertEqual(result, 1.0 / 24.0, accuracy: doubleAccuracy)
    }

    func testInverseOfSum() {
        // Arrange
        let result = calculateInverseOrAlternative(x: 0.0, y: 2.0, z: 3.0)
        
        // Assert
        XCTAssertEqual(result, 1.0 / 5.0, accuracy: doubleAccuracy)
    }

    func testAlternativeCalculation() {
        // Arrange
        let result = calculateInverseOrAlternative(x: 0.0, y: 0.0, z: 0.0)
        
        // Assert
        XCTAssertEqual(result, 1.0, accuracy: doubleAccuracy)
    }

    func testMixedCase() {
        // Arrange
        let result = calculateInverseOrAlternative(x: 1.0, y: 0.0, z: -1.0)
        
        // Assert
        XCTAssertEqual(result, -2.0, accuracy: doubleAccuracy) // Calculated result directly
    }
}

extension CalculateInverseOrAlternativeTests {
    static var allTests = [
        ("testInverseOfProduct", testInverseOfProduct),
        ("testInverseOfSum", testInverseOfSum),
        ("testAlternativeCalculation", testAlternativeCalculation),
        ("testMixedCase", testMixedCase)
    ]
}
