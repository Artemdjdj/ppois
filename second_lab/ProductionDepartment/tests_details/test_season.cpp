
#include "include_season.h"
#include <gtest/gtest.h>

class TestSeason : public ::testing::Test {
public:
    void SetUp() override{
        season = Season();
    }
    Season season;
};

TEST_F(TestSeason, TestSeasonSetFunction) {
    season.set_season("winter");
    ASSERT_EQ(season.get_season(), "winter");
}

TEST_F(TestSeason, TestSeasonSetFunctionBigLetters) {
    season.set_season("Winter");
    ASSERT_EQ(season.get_season(), "winter");
}

TEST_F(TestSeason, TestSeasonSetFunctionNegativeResult) {
    season.set_season("Winner");
    ASSERT_EQ(season.get_season(), "");
}

TEST_F(TestSeason, TestSeasonSetFunctionEmptyString) {
    ASSERT_FALSE(season.set_season(""));
}


