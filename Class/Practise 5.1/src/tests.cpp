#include "MegaData.hpp"
#include "MegaDataPool.hpp"
#include <iostream>
#include <stdexcept>
#include <print>
#include "UnitTests.hpp"

void testMegaDataReset() {
    // Arrange
    MegaData data;

    // Act
    data.reset();

    // Assert
    for (const auto& val : data.smallArray) {
        ASSERT_EQ(val, 42.0f);
    }
    for (const auto& val : data.bigArray) {
        ASSERT_EQ(val, 42.0);
    }
}

void testMegaDataPoolAcquireRelease() {
    // Arrange
    MegaDataPool pool(3);

    // Act
    auto data1 = pool.acquire();
    auto data2 = pool.acquire();
    auto data3 = pool.acquire();

    // Assert
    ASSERT_EQ(pool.size(), 3);
    ASSERT_EQ(pool.usedSize(), 3);

    data1.reset(); // Release one object
    ASSERT_EQ(pool.usedSize(), 2);

    auto data4 = pool.acquire(); // Acquire again
    ASSERT_EQ(pool.usedSize(), 3);

    data2.reset();
    data3.reset();
    data4.reset();
    ASSERT_EQ(pool.usedSize(), 0);
}

void testMegaDataPoolExceedLimit() {
    // Arrange
    MegaDataPool pool(2);

    // Act & Assert
    auto data1 = pool.acquire();
    auto data2 = pool.acquire();
    ASSERT_EQ(pool.usedSize(), 2);

    try {
        auto data3 = pool.acquire();
        // If we reach this line, the test has failed
        ASSERT_EQ(true, false);
    } catch (const std::runtime_error& e) {
        ASSERT_EQ(std::string(e.what()), "No available objects in the pool");
    }
}

void testMegaDataPoolReleaseInvalidIndex() {
    // Arrange
    MegaDataPool pool(2);

    // Act & Assert
    try {
        pool.release(2); // Invalid index
        // If we reach this line, the test has failed
        ASSERT_EQ(true, false);
    } catch (const std::out_of_range& e) {
        ASSERT_EQ(std::string(e.what()), "Invalid index for release");
    }
}

int main() {
    UnitTests tests;

    tests.addTest("testMegaDataReset", testMegaDataReset);
    tests.addTest("testMegaDataPoolAcquireRelease", testMegaDataPoolAcquireRelease);
    tests.addTest("testMegaDataPoolExceedLimit", testMegaDataPoolExceedLimit);
    tests.addTest("testMegaDataPoolReleaseInvalidIndex", testMegaDataPoolReleaseInvalidIndex);

    tests.run();

    return 0;
}
