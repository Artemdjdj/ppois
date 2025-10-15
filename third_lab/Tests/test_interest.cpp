#include <gtest/gtest.h>
#include "../SocialMedia/interest.h"

class TestInterest : public ::testing::Test {
public:
    Interest interest = Interest();
};

TEST_F(TestInterest, TestSetDuration) {
    interest.SetDuration("football");
    ASSERT_EQ("football", interest.GetDuration());
}

TEST_F(TestInterest, TestSetDurationEmpty) {
    ASSERT_EQ("", interest.GetDuration());
}

TEST_F(TestInterest, TestSetLevelLeftBoard) {
    interest.SetLevel(1);
    ASSERT_EQ(1, interest.GetLevel());
}

TEST_F(TestInterest, TestSetLevelRightBoard) {
    interest.SetLevel(10);
    ASSERT_EQ(10, interest.GetLevel());
}

TEST_F(TestInterest, TestSetLevelDefaultValue) {
    interest.SetLevel(5);
    ASSERT_EQ(5, interest.GetLevel());
}

TEST_F(TestInterest, TestSetLevelLeftBoardIncorrect) {
    ASSERT_THROW(
        interest.SetLevel(0),
        ExceptionIncorrectLevelOfInterest
    );
}

TEST_F(TestInterest, TestSetLevelRightBoardIncorrect) {
    ASSERT_THROW(
        interest.SetLevel(11),
        ExceptionIncorrectLevelOfInterest
    );
}