#include "../Fuel/fuel.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

class TestFuel : public ::testing::Test {
public:
	void SetUp() override {
		fuel = Fuel();
	}

	Fuel fuel;
};

TEST_F(TestFuel, TestSetCorrectFuel) {
	fuel.SetTypeOfFuel("gas");
}

TEST_F(TestFuel, TestSetIncorrectFuel) {
	ASSERT_THROW(
		fuel.SetTypeOfFuel("gass"),
		ExceptionIncorrectFuel
	);
}

TEST_F(TestFuel, TestSetCorrectFuelBigLetters) {
	fuel.SetTypeOfFuel("gaS");
	ASSERT_EQ(fuel.GetTypeOfFuel(), "gas");
}

TEST_F(TestFuel, TestGetSeason) {
	const auto season  = Season("Winter");
	fuel.SetSeason(season);
	ASSERT_EQ(fuel.GetSeason(), "winter");
}

TEST(TestFuelConstructor, TestConstructor) {
	const auto fuel = Fuel("petrol", "summer");
	ASSERT_EQ(fuel.GetSeason(), "summer");
	ASSERT_EQ(fuel.GetTypeOfFuel(), "petrol");
}
