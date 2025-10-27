#include "../Engine/water_pump.h"
#include <gtest/gtest.h>

#include "../../Exceptions/exceptions.h"

class TestWaterPump : public ::testing::Test {
public:
    WaterPump water_pump = WaterPump(34, 200);
};

TEST_F(TestWaterPump, TestStartPump) {
    ASSERT_TRUE(water_pump.StartPump());
}

TEST_F(TestWaterPump, TestStopPump) {
    water_pump.StopPump();
    ASSERT_FALSE(water_pump.GetWorkingState());
}

TEST_F(TestWaterPump, TestCalculateFlow) {
    water_pump.StartPump();
    ASSERT_EQ(water_pump.CalculateFlow(67), 11);
}

TEST_F(TestWaterPump, TestCalculatePower) {
    ASSERT_EQ(water_pump.CalculatePower(67), 0);
}

TEST_F(TestWaterPump, TestGetResource) {
    ASSERT_EQ(water_pump.GetResource(), 100);
}

TEST_F(TestWaterPump, TestGetCurrentPressure) {
    ASSERT_EQ(water_pump.GetCurrentPressure(), 0);
}

TEST_F(TestWaterPump, TestGetMaxPressure) {
    ASSERT_EQ(water_pump.GetMaxPressure(), 200);
}

TEST_F(TestWaterPump, TestGetFlowRate) {
    ASSERT_EQ(water_pump.GetFlowRate(), 34);
}

TEST_F(TestWaterPump, WaterPumpDescription) {
    EXPECT_EQ(water_pump.GetInfoAboutPart(), "This detail name is water pump");
}

TEST_F(TestWaterPump, TestSetAndGetOperatingTemperature) {
    water_pump.SetOperatingTemperature(85);
    ASSERT_EQ(water_pump.GetOperatingTemperature(), 85);
}

TEST_F(TestWaterPump, TestSetNegativeOperatingTemperature) {
    ASSERT_THROW(
        water_pump.SetOperatingTemperature(-10),
        ExceptionRuntimeError
    );
    ASSERT_EQ(water_pump.GetOperatingTemperature(), 0);
}

TEST_F(TestWaterPump, TestSetAndGetThermostat) {
    water_pump.SetThermostat(true);
    ASSERT_TRUE(water_pump.IsThermostat());
}

TEST_F(TestWaterPump, TestSetAndGetLifeSpan) {
    water_pump.SetLifeSpan(5);
    ASSERT_EQ(water_pump.GetLifeSpan(), 5);
}

TEST_F(TestWaterPump, TestSetNegativeLifeSpan) {
    ASSERT_THROW(
        water_pump.SetLifeSpan(-100),
        ExceptionRuntimeError
    );
}

TEST_F(TestWaterPump, TestSetAndGetPowerConsumption) {
    water_pump.SetPowerConsumption(150);
    ASSERT_EQ(water_pump.GetPowerConsumption(), 150);
}

TEST_F(TestWaterPump, TestSetNegativePowerConsumption) {
    ASSERT_THROW(
       water_pump.SetPowerConsumption(-50),
       ExceptionRuntimeError
    );
    ASSERT_EQ(water_pump.GetPowerConsumption(), 0);
}

TEST_F(TestWaterPump, TestSetAndGetManufacturer) {
    water_pump.SetManufacturer("Bosch");
    ASSERT_EQ(water_pump.GetManufacturer(), "Bosch");
}

TEST_F(TestWaterPump, TestSetEmptyManufacturer) {
    water_pump.SetManufacturer("");
    ASSERT_TRUE(water_pump.GetManufacturer().empty());
}

TEST_F(TestWaterPump, TestSetAndGetWeight) {
    water_pump.SetWeight(2500);
    ASSERT_EQ(water_pump.GetWeight(), 2500);
}

TEST_F(TestWaterPump, TestSetNegativeWeight) {
    ASSERT_THROW(
        water_pump.SetWeight(-100),
        ExceptionRuntimeError
    );
    ASSERT_EQ(water_pump.GetWeight(), 0);
}

TEST_F(TestWaterPump, TestCalculateFlowWithWorkingState) {
    water_pump.StopPump();
    ASSERT_EQ(water_pump.CalculateFlow(100), 0);
    water_pump.StartPump();
    ASSERT_GT(water_pump.CalculateFlow(100), 0);
}

TEST_F(TestWaterPump, TestCalculateFlowWithPressureExceedingMax) {
    water_pump.StartPump();
    ASSERT_EQ(water_pump.CalculateFlow(250), 0);
}

TEST_F(TestWaterPump, TestStartPumpWithZeroResource) {
    ASSERT_TRUE(water_pump.StartPump());
}
