#include "../Seasons/season.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

class TestSeason : public ::testing::Test {
public:
	void SetUp() override {
		season = Season();
	}

	Season season;
};

TEST_F(TestSeason, TestSeasonSetFunction) {
	season.SetSeason("winter");
	ASSERT_EQ(season.GetSeason(), "winter");
}

TEST_F(TestSeason, TestSeasonSetFunctionBigLetters) {
	season.SetSeason("Winter");
	ASSERT_EQ(season.GetSeason(), "winter");
}

TEST_F(TestSeason, TestSeasonSetFunctionNegativeResult) {
	ASSERT_THROW(
		season.SetSeason("Winner");,
		ExceptionIncorrectSeason
	);
	ASSERT_EQ(season.GetSeason(), "");
}

TEST_F(TestSeason, TestSeasonSetFunctionEmptyString) {
	ASSERT_THROW(
		season.SetSeason("");,
		ExceptionIncorrectSeason
	);
}

TEST(TestSeasonConstructor, TestSeasonConstructor) {
	Season season = Season("summer");
	ASSERT_EQ(season.GetSeason(), "summer");
}
