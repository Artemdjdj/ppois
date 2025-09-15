#include <gtest/gtest.h>
#include "include_basic_params.h"

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
TEST(Testing_colors, TestCheckFunctionPositive) {
    Color color = Color("green");
    color.set_color("blue");
    ASSERT_EQ(color.get_color(), "blue");
}

TEST(Testing_colors, TestCheckFunctionNegative) {
    Color color = Color("green");
    color.set_color("KJhksfd");
    ASSERT_EQ(color.get_color(), "green");
}

TEST(Testing_colors, TestCheckFunctionPositiveAllLettersAreBig) {
    Color color = Color("green");
    color.set_color("RED");
    ASSERT_EQ(color.get_color(), "red");
}