#include <iostream>
#include "Helpers.hpp"
#include "UnitTests.hpp"

int main() {
    UnitTests testSuite;

    // Tests for dummyFunc
    testSuite.addTest("Dummy_test1", []() {
        // Arrange
        double value = 0.0;

        // Act
        auto result = dummyFunc(value);

        // Assert
        ASSERT_EQ(result, 0.0);
    });

    testSuite.addTest("Dummy_test2", []() {
        // Arrange
        double value = 5.0;

        // Act
        auto result = dummyFunc(value);

        // Assert
        ASSERT_EQ(result, 5.0);
    });

    testSuite.addTest("Dummy_test3", []() {
        // Arrange
        double value = -3.0;

        // Act
        auto result = dummyFunc(value);

        // Assert
        ASSERT_EQ(result, 0.0);
    });

    // Tests for repeatString
    testSuite.addTest("RepeatStringPrints_home_Twice", []() {
        // Arrange
        std::vector<int> vec = {0, 2, 1};
        std::string str = "home";

        // Act
        auto result = repeatString(vec, str);

        // Assert
        ASSERT_EQ(result, "homehome");
    });

    testSuite.addTest("RepeatString_EmptyVector", []() {
        // Arrange
        std::vector<int> vec = {};
        std::string str = "test";

        // Act
        auto result = repeatString(vec, str);

        // Assert
        ASSERT_EQ(result, "");
    });

    testSuite.addTest("RepeatString_EmptyString", []() {
        // Arrange
        std::vector<int> vec = {1, 2, 3};
        std::string str = "";

        // Act
        auto result = repeatString(vec, str);

        // Assert
        ASSERT_EQ(result, "");
    });

    testSuite.addTest("RepeatString_PrintOnce", []() {
        // Arrange
        std::vector<int> vec = {1, 1, 1};
        std::string str = "a";

        // Act
        auto result = repeatString(vec, str);

        // Assert
        ASSERT_EQ(result, "a");
    });

    testSuite.addTest("RepeatString_PrintFiveTimes", []() {
        // Arrange
        std::vector<int> vec = {5, 3, 4};
        std::string str = "xyz";

        // Act
        auto result = repeatString(vec, str);

        // Assert
        ASSERT_EQ(result, "xyzxyzxyzxyzxyz");
    });

    testSuite.run();
}
