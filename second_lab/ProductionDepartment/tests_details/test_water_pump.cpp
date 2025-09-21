#include "../Engine/water_pump.h"
#include <gtest/gtest.h>

class TestWaterPump : public ::testing::Test {
public:
    WaterPump water_pump = WaterPump(34, 200);
};

TEST_F(TestWaterPump, TestStartPump) {
    ASSERT_TRUE(water_pump.start_pump());
}

TEST_F(TestWaterPump, TestStopPump) {
    water_pump.stop_pump();
    ASSERT_FALSE(water_pump.get_working_state());
}

TEST_F(TestWaterPump, TestCalculateFlow) {
    water_pump.start_pump();
    ASSERT_EQ(water_pump.calculate_flow(67),11);
}

TEST_F(TestWaterPump, TestCalculatePower) {
    ASSERT_EQ(water_pump.calculate_power(67),0);
}

TEST_F(TestWaterPump, TestGetResource) {
    ASSERT_EQ(water_pump.get_resource(),100);
}

TEST_F(TestWaterPump, TestGetCurrentPressure) {
    ASSERT_EQ(water_pump.get_current_pressure(),0);
}

TEST_F(TestWaterPump, TestGetMaxPressure) {
    ASSERT_EQ(water_pump.get_max_pressure(),200);
}

TEST_F(TestWaterPump, TestGetFlowRate) {
    ASSERT_EQ(water_pump.get_flow_rate(),34);
}

