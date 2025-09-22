#include "../Fuel/fuel.h"
#include <gtest/gtest.h>

class TestFuel : public ::testing::Test {
public:
	void SetUp() override {
		fuel = Fuel();
	}

	Fuel fuel;
};

TEST_F(TestFuel, TestSetCorrectFuel) {
	ASSERT_TRUE(fuel.SetTypeOfFuel("gas"));
}

TEST_F(TestFuel, TestSetIncorrectFuel) {
	ASSERT_FALSE(fuel.SetTypeOfFuel("gass"));
}

TEST_F(TestFuel, TestSetCorrectFuelBigLetters) {
	fuel.SetTypeOfFuel("gaS");
	ASSERT_EQ(fuel.GetTypeOfFuel(), "gas");
}

TEST_F(TestFuel, TestGetSeason) {
	fuel.SetSeason("Winter");
	ASSERT_EQ(fuel.GetSeason(), "winter");
}

TEST(TestFuelConstructor, TestConstructor) {
	Fuel fuel = Fuel("petrol","summer");
	ASSERT_EQ(fuel.GetSeason(), "summer");
	ASSERT_EQ(fuel.GetTypeOfFuel(), "petrol");
}
