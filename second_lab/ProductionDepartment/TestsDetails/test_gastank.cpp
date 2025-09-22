#include "../CarBody/gas_tank.h"
#include <gtest/gtest.h>

class TestGasTank : public ::testing::Test {
public:
	void SetUp() override {
		gas_tank = GasTank();
	}

	GasTank gas_tank;
};

TEST_F(TestGasTank, TestSetFuel) {
	gas_tank.SetFuel("petrol");
	ASSERT_EQ(gas_tank.GetFuel(), "petrol");
}

TEST_F(TestGasTank, TestSetFuelNegativeResult) {
	gas_tank.SetFuel("petrols");
	ASSERT_EQ(gas_tank.GetFuel(), "");
}

TEST_F(TestGasTank, TestSetFuelPositiveResultBigLetters) {
	gas_tank.SetFuel("Petrol");
	ASSERT_EQ(gas_tank.GetFuel(), "petrol");
}

TEST_F(TestGasTank, TestSetVolume) {
	gas_tank.SetVolume(60);
	ASSERT_EQ(gas_tank.GetVolume(), 60);
}

TEST_F(TestGasTank, TestSetVolumeNegativeResult) {
	gas_tank.SetVolume(-60);
	ASSERT_EQ(gas_tank.GetVolume(), 0);
}

TEST_F(TestGasTank, TestSetProcentOccupancy) {
	gas_tank.SetPercentageOfOccupancy(40);
	ASSERT_EQ(gas_tank.GetPercentageOfOccupancy(), 40);
}

TEST_F(TestGasTank, TestSetProcentOccupancyNegativeTooBig) {
	gas_tank.SetPercentageOfOccupancy(400);
	ASSERT_EQ(gas_tank.GetPercentageOfOccupancy(), 0);
}

TEST_F(TestGasTank, TestSetProcentOccupancyNegativeTooSmall) {
	gas_tank.SetPercentageOfOccupancy(-10);
	ASSERT_EQ(gas_tank.GetPercentageOfOccupancy(), 0);
}

TEST_F(TestGasTank, TestSetSeason) {
	gas_tank.SetSeason("summer");
	ASSERT_EQ(gas_tank.GetSeason(), "summer");
}

TEST_F(TestGasTank, TestSetSeasonNegative) {
	gas_tank.SetSeason("summerrs");
	ASSERT_EQ(gas_tank.GetSeason(), "");
}

TEST_F(TestGasTank, GasTankDescription) {
	EXPECT_EQ(gas_tank.GetInfoAboutPart(), "This detail name is gas tank");
}
