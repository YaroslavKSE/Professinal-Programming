import XCTest

class MegaDataPoolTests: XCTestCase {

    func testAcquire_Successful_WhenPoolHasAvailableObjects() {
        // Arrange
        let pool = MegaDataPool(poolSize: 3)

        // Act
        _ = try! pool.acquire()
        _ = try! pool.acquire()
        _ = try! pool.acquire()

        // Assert
        XCTAssertEqual(pool.size(), 3)
        XCTAssertEqual(pool.usedSize(), 3)
    }

    func testAcquire_Unsuccessful_WhenPoolIsExhausted() {
        // Arrange
        let pool = MegaDataPool(poolSize: 2)

        // Act
        _ = try! pool.acquire()
        _ = try! pool.acquire()

        // Assert
        XCTAssertEqual(pool.usedSize(), 2)

        // Act & Assert for exceeding limit
        XCTAssertThrowsError(try pool.acquire()) { error in
            XCTAssertEqual(error as? MegaDataPoolError, MegaDataPoolError.noAvailableObjects)
        }
    }

    func testRelease_Successful_WhenReleasingValidObject() {
        // Arrange
        let pool = MegaDataPool(poolSize: 3)
        let data1 = try! pool.acquire()
        _ = try! pool.acquire()

        // Act
        try! pool.release(data1)

        // Assert
        XCTAssertEqual(pool.usedSize(), 1)

        _ = try! pool.acquire()
        XCTAssertEqual(pool.usedSize(), 2)
    }

    func testRelease_Unsuccessful_WhenReleasingInvalidObject() {
        // Arrange
        let pool = MegaDataPool(poolSize: 3)
        _ = try! pool.acquire()
        _ = try! pool.acquire()
        let invalidData = MegaData()

        // Act & Assert for invalid release
        XCTAssertThrowsError(try pool.release(invalidData)) { error in
            XCTAssertEqual(error as? MegaDataPoolError, MegaDataPoolError.invalidObject)
        }
    }
}

#if os(Linux)
extension MegaDataPoolTests {
    static var allTests = [
        ("testAcquire_Successful_WhenPoolHasAvailableObjects", testAcquire_Successful_WhenPoolHasAvailableObjects),
        ("testAcquire_Unsuccessful_WhenPoolIsExhausted", testAcquire_Unsuccessful_WhenPoolIsExhausted),
        ("testRelease_Successful_WhenReleasingValidObject", testRelease_Successful_WhenReleasingValidObject),
        ("testRelease_Unsuccessful_WhenReleasingInvalidObject", testRelease_Unsuccessful_WhenReleasingInvalidObject),
    ]
}
#endif