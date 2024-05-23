import XCTest
@testable import CalculateInverseOrAlternative

class CalculateInverseOrAlternativeTests: XCTestCase {

    func testInverseOfProduct() {
        // Arrange and Act
        let result = calculateInverseOrAlternative(x: 2.0, y: 3.0, z: 4.0)

        // Assert
        XCTAssertEqual(result, 1.0 / 24.0, accuracy: 1e-9)
    }

    func testInverseOfSum() {
        // Arrange and Act
        let result = calculateInverseOrAlternative(x: 0.0, y: 2.0, z: 3.0)

        // Assert
        XCTAssertEqual(result, 1.0 / 5.0, accuracy: 1e-9)
    }

    func testAlternativeCalculation() {
        // Arrange and Act
        let result = calculateInverseOrAlternative(x: 0.0, y: 0.0, z: 0.0)

        // Assert
        XCTAssertEqual(result, 1.0, accuracy: 1e-9)
    }

    func testMixedCase() {
        // Arrange and Act
        let result = calculateInverseOrAlternative(x: 1.0, y: 0.0, z: -1.0)

        // Assert
        XCTAssertEqual(result, 1.0 + (0.0 + 1.0) * (-1.0 - 1.0), accuracy: 1e-9)
    }

        static var allTests = [
        ("testInverseOfProduct", testInverseOfProduct),
        ("testInverseOfSum", testInverseOfSum),
        ("testAlternativeCalculation", testAlternativeCalculation),
        ("testMixedCase", testMixedCase),
    ]
}


