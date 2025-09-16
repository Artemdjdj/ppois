#include <gtest/gtest.h>
#include "include_basic_params.h"

class TestingColors:public ::testing::Test {
public:
    void SetUp() {
        color =Color("green");
    }
    Color color;
};
TEST(Testingtolower, BigLetters) {
    string word = "GGGG";
    ToLower(word);
    ASSERT_EQ(word, "gggg");
}

TEST(Testingtolower, SmallLettersWithBigletters) {
    string word = "Hello wOrlD";
    ToLower(word);
    ASSERT_EQ(word, "hello world");
}
TEST_F(TestingColors, TestCheckFunctionPositive) {
    color.set_color("blue");
    ASSERT_EQ(color.get_color(), "blue");
}

TEST_F(TestingColors, TestCheckFunctionNegative) {
    color.set_color("KJhksfd");
    ASSERT_EQ(color.get_color(), "green");
}

TEST_F(TestingColors, TestCheckFunctionPositiveAllLettersAreBig) {
    color.set_color("RED");
    ASSERT_EQ(color.get_color(), "red");
}