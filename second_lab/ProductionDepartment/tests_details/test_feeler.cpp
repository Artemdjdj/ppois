#include "include_feeler.h"
#include <gtest/gtest.h>

class TestFeeler : public ::testing::Test {
public:
    void SetUp() override {
        feeler = Feeler(100, 90);
    }
    Feeler feeler;
};

TEST_F(TestFeeler, TestSetLength) {
    feeler.set_length(10);
    ASSERT_EQ(feeler.get_length(), 10);
}

TEST_F(TestFeeler, TestSetLengthNegative) {
    feeler.set_length(-110);
    ASSERT_EQ(feeler.get_length(), 100);
}

TEST_F(TestFeeler, TestSetLevelBiggerThenLengthHalf) {
    feeler.set_level(110);
    ASSERT_EQ(feeler.get_level(), 90);
}

TEST_F(TestFeeler, TestSetLevel) {
    feeler.set_level(50);
    ASSERT_EQ(feeler.get_level(), 50);
}

TEST_F(TestFeeler, TestCheckLevelNormState) {
    feeler.set_level(50);
    ASSERT_TRUE(feeler.check_is_the_level_in_norm_state());
}
TEST_F(TestFeeler, TestCheckLevelNormStateNegativeResult) {
    ASSERT_FALSE(feeler.check_is_the_level_in_norm_state());
}

