#include "../Fuel/feeler.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

class TestFeeler : public ::testing::Test {
public:
	void SetUp() override {
		feeler = Feeler(100, 90);
	}

	Feeler feeler;
};

TEST_F(TestFeeler, TestSetLength) {
	feeler.SetLength(10);
	ASSERT_EQ(feeler.GetLength(), 10);
}

TEST_F(TestFeeler, TestSetLengthNegative) {
	ASSERT_THROW(
		feeler.SetLength(-110),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(feeler.GetLength(), 100);
}

TEST_F(TestFeeler, TestSetLevelBiggerThenLengthHalf) {
	feeler.SetLevel(110);
	ASSERT_EQ(feeler.GetLevel(), 90);
}

TEST_F(TestFeeler, TestSetLevel) {
	feeler.SetLevel(50);
	ASSERT_EQ(feeler.GetLevel(), 50);
}

TEST_F(TestFeeler, TestCheckLevelNormState) {
	feeler.SetLevel(50);
	feeler.CheckIsTheLevelInNormState();
}

TEST_F(TestFeeler, TestCheckLevelNormStateNegativeResult) {
	ASSERT_THROW(
		feeler.CheckIsTheLevelInNormState(),
		ExceptionIncorrectLevelOil
	);
}

TEST_F(TestFeeler, FeelerDescription) {
	EXPECT_EQ(feeler.GetInfoAboutPart(), "This detail name is feeler");
}
