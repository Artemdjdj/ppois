#include <gtest/gtest.h>
#include "include_basic_params.h"

class TestingColors:public ::testing::Test {
public:
    void SetUp() override {
        color =Color("green");
    }
    Color color;
};
TEST(Testingtolower, BigLetters) {
    std::string word = "GGGG";
    ToLower(word);
    ASSERT_EQ(word, "gggg");
}

TEST(Testingtolower, SmallLettersWithBigletters) {
    std::string word = "Hello wOrlD";
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

TEST(TestVolume, TestSetCorrectVolume) {
    Volume volume = Volume();
    volume.set_volume(10);
    ASSERT_EQ(volume.get_volume(), 10);
}

TEST(TestVolume, TestSetInCorrectVolume) {
    Volume volume = Volume();
    volume.set_volume(-10);
    ASSERT_EQ(volume.get_volume(), 0);
}