#include "include_fuel.h"
#include <gtest/gtest.h>

class TestFuel : public ::testing::Test {
public:
    void SetUp() override{
        fuel = Fuel();
    }
    Fuel fuel;
};

TEST_F(TestFuel, TestSetCorrectFuel) {
    ASSERT_TRUE(fuel.set_type_of_fuel("gas"));
}

TEST_F(TestFuel, TestSetIncorrectFuel) {
    ASSERT_FALSE(fuel.set_type_of_fuel("gass"));
}

TEST_F(TestFuel, TestSetCorrectFuelBigLetters) {
    fuel.set_type_of_fuel("gaS");
    ASSERT_EQ(fuel.get_type_of_fuel(), "gas");
}

TEST_F(TestFuel, TestGetSeason) {
    fuel.set_season("Winter");
    ASSERT_EQ(fuel.get_season(), "winter");
}

