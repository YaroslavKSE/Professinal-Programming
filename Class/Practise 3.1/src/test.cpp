#include <iostream>
#include "Helpers.hpp"
#include "UnitTests.hpp"

int main() {
    UnitTests testSuite;

    testSuite.addTest("ZeroInputValueReturnsZero",
    [](){
        // Build:
        double value = 0.0;
    
        // Operate:
        auto result = dummyFunc(value);

        // Check:
        ASSERT_EQ(result, 0.0);
    });

    testSuite.addTest("PositiveValueInputReturnsPositiveValue",
    [](){
        // Build:
        double value = 5.0;
    
        // Operate:
        auto result = dummyFunc(value);

        // Check:
        ASSERT_EQ(result, 5.0);
    });

    testSuite.addTest("NegativeValueInputReturnsZero",
    [](){
        // Build:
        double value = -3.0;
    
        // Operate:
        auto result = dummyFunc(value);

        // Check:
        ASSERT_EQ(result, 0.0);
    });

     // Tests for repeatString
    testSuite.addTest("RepeatStringPrints_home_Twice", []() {
        std::vector<int> vec = {0, 2, 1};
        std::string str = "home";
        auto result = repeatString(vec, str);
        ASSERT_EQ(result, "homehome");
    });

    testSuite.addTest("RepeatStringDoNotPrint_test", []() {
        std::vector<int> vec = {0, 0, 0};
        std::string str = "test";
        auto result = repeatString(vec, str);
        ASSERT_EQ(result, "");
    });

    testSuite.addTest("RepeatStringPrints_a_Once", []() {
        std::vector<int> vec = {1, 1, 1};
        std::string str = "a";
        auto result = repeatString(vec, str);
        ASSERT_EQ(result, "a");
    });

    testSuite.addTest("RepeatStringPrints_xyz_FiveTimes", []() {
        std::vector<int> vec = {5, 3, 4};
        std::string str = "xyz";
        auto result = repeatString(vec, str);
        ASSERT_EQ(result, "xyzxyzxyzxyzxyz");
    });

    testSuite.addTest("RepeatStringPrints_123_ThreeTimes", []() {
        std::vector<int> vec = {-1, 2, 2, 2};
        std::string str = "123";
        auto result = repeatString(vec, str);
        ASSERT_EQ(result, "123123");
    });

    testSuite.run();
}
