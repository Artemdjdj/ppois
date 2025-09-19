#include "include_gas_tank.h"
#include <gtest/gtest.h>

class TestGasTank : public ::testing::Test {
public:
    void SetUp() override {
        gas_tank = GasTank();
    }
    GasTank gas_tank;
};

TEST_F(TestGasTank, TestSetFuel) {
    gas_tank.set_fuel("petrol");
    ASSERT_EQ(gas_tank.get_fuel(), "petrol");
}

TEST_F(TestGasTank, TestSetFuelNegativeResult) {
    gas_tank.set_fuel("petrols");
    ASSERT_EQ(gas_tank.get_fuel(), "");
}

TEST_F(TestGasTank, TestSetFuelPositiveResultBigLetters) {
    gas_tank.set_fuel("Petrol");
    ASSERT_EQ(gas_tank.get_fuel(), "petrol");
}

TEST_F(TestGasTank, TestSetVolume) {
    gas_tank.set_volume(60);
    ASSERT_EQ(gas_tank.get_volume(), 60);
}

TEST_F(TestGasTank, TestSetVolumeNegativeResult) {
    gas_tank.set_volume(-60);
    ASSERT_EQ(gas_tank.get_volume(), 0);
}

TEST_F(TestGasTank, TestSetProcentOccupancy) {
    gas_tank.set_percentage_of_occupancy(40);
    ASSERT_EQ(gas_tank.get_percentage_of_occupancy(), 40);
}

TEST_F(TestGasTank, TestSetProcentOccupancyNegativeTooBig) {
    gas_tank.set_percentage_of_occupancy(400);
    ASSERT_EQ(gas_tank.get_percentage_of_occupancy(), 0);
}

TEST_F(TestGasTank, TestSetProcentOccupancyNegativeTooSmall) {
    gas_tank.set_percentage_of_occupancy(-10);
    ASSERT_EQ(gas_tank.get_percentage_of_occupancy(), 0);
}

TEST_F(TestGasTank, TestSetSeason) {
    gas_tank.set_season("summer");
    ASSERT_EQ(gas_tank.get_season(), "summer");
}

TEST_F(TestGasTank, TestSetSeasonNegative) {
    gas_tank.set_season("summerrs");
    ASSERT_EQ(gas_tank.get_season(), "");
}




