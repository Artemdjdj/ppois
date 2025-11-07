#include "../CarBody/gas_tank.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

class TestGasTank : public ::testing::Test {
public:
	void SetUp() override {
		gas_tank = GasTank();
	}

	GasTank gas_tank;
};

TEST_F(TestGasTank, TestSetFuel) {
	const auto fuel = Fuel("petrol", "summer");
	gas_tank.SetFuel(fuel);
	ASSERT_EQ(gas_tank.GetFuel(), "petrol");
}


TEST_F(TestGasTank, TestSetFuelPositiveResultBigLetters) {
	const auto fuel = Fuel("Petrol", "summer");
	gas_tank.SetFuel(fuel);
	ASSERT_EQ(gas_tank.GetFuel(), "petrol");
}

TEST_F(TestGasTank, TestSetVolume) {
	gas_tank.SetVolume(60);
	ASSERT_EQ(gas_tank.GetVolume(), 60);
}

TEST_F(TestGasTank, TestSetVolumeNegativeResult) {
	ASSERT_THROW(
		gas_tank.SetVolume(-60),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(gas_tank.GetVolume(), 0);
}

TEST_F(TestGasTank, TestSetProcentOccupancy) {
	gas_tank.SetPercentageOfOccupancy(40);
	ASSERT_EQ(gas_tank.GetPercentageOfOccupancy(), 40);
}

TEST_F(TestGasTank, TestSetProcentOccupancyNegativeTooBig) {
	ASSERT_THROW(
		gas_tank.SetPercentageOfOccupancy(400),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(gas_tank.GetPercentageOfOccupancy(), 0);
}

TEST_F(TestGasTank, TestSetProcentOccupancyNegativeTooSmall) {
	ASSERT_THROW(
		gas_tank.SetPercentageOfOccupancy(-10),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(gas_tank.GetPercentageOfOccupancy(), 0);
}

TEST_F(TestGasTank, TestSetSeason) {
	gas_tank.SetSeason("summer");
	ASSERT_EQ(gas_tank.GetSeason(), "summer");
}

TEST_F(TestGasTank, TestSetSeasonNegative) {
	ASSERT_THROW(
		gas_tank.SetSeason("summerrs"),
		ExceptionIncorrectSeason
	);
	ASSERT_EQ(gas_tank.GetSeason(), "");
}

TEST_F(TestGasTank, TestGasTankDescription) {
	ASSERT_EQ(gas_tank.GetInfoAboutPart(), "This detail name is gas tank");
}

TEST_F(TestGasTank, TestIsMechanicalIndicator) {
    gas_tank.SetMechanicalIndicator(true);
	ASSERT_TRUE(gas_tank.CheckIsMechanicalIndicator());
}


TEST_F(TestGasTank, TestIsBigGasTankSmall) {
    gas_tank.SetVolume(20);
	ASSERT_EQ(gas_tank.CheckIsGasTankBig(), "small");
}

TEST_F(TestGasTank, TestIsBigGasTankNormal) {
	gas_tank.SetVolume(50);
	ASSERT_EQ(gas_tank.CheckIsGasTankBig(), "normal");
}

TEST_F(TestGasTank, TestIsBigGasTankBig) {
	gas_tank.SetVolume(80);
	ASSERT_EQ(gas_tank.CheckIsGasTankBig(), "big");
}

