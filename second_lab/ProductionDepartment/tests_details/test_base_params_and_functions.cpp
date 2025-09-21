#include <gtest/gtest.h>
#include "basic_params.h"

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
    color.SetColor("blue");
    ASSERT_EQ(color.GetColor(), "blue");
}

TEST_F(TestingColors, TestCheckFunctionNegative) {
    color.SetColor("KJhksfd");
    ASSERT_EQ(color.GetColor(), "green");
}

TEST_F(TestingColors, TestCheckFunctionPositiveAllLettersAreBig) {
    color.SetColor("RED");
    ASSERT_EQ(color.GetColor(), "red");
}

TEST(TestVolume, TestSetCorrectVolume) {
    Volume volume = Volume();
    volume.SetVolume(10);
    ASSERT_EQ(volume.GetVolume(), 10);
}

TEST(TestVolume, TestSetInCorrectVolume) {
    Volume volume = Volume();
    volume.SetVolume(-10);
    ASSERT_EQ(volume.GetVolume(), 0);
}