import XCTest

class MegaDataTests: XCTestCase {
    
    func testMegaDataReset() {
        // Arrange
        let data = MegaData()
        
        // Act
        data.reset()
        
        // Assert
        for value in data.smallArray {
            XCTAssertEqual(value, 42.0)
        }
        
        for value in data.bigArray {
            XCTAssertEqual(value, 42.0)
        }
    }
}

#if os(Linux)
extension MegaDataTests {
    static var allTests: [(String, (MegaDataTests) -> () -> ())] = [
        ("testMegaDataReset", testMegaDataReset),
    ]
}
#endif