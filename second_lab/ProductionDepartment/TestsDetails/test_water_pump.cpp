#include "../Engine/water_pump.h"
#include <gtest/gtest.h>

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

TEST_F(TestWaterPump,WaterPumpDescription) {
	EXPECT_EQ(water_pump.GetInfoAboutPart(),"This detail name is water pump");
}