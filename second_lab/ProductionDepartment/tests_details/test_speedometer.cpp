#include "include_speedometer.h"
#include <gtest/gtest.h>

class TestSpeedometer : public ::testing::Test {
public:
    void SetUp() override {
        speedometer_k = SpeedometerInKilometers(77, 255533);
        speedometer_m = SpeedometerInMiles(77, 255533);
    }
    SpeedometerInMiles speedometer_m;
    SpeedometerInKilometers speedometer_k;
};

TEST_F(TestSpeedometer, TestSpeedometerKilometersMileage) {
    ASSERT_EQ(speedometer_k.get_mileage(),255533);
}

TEST_F(TestSpeedometer, TestSpeedometerKilometersSpeed) {
    ASSERT_EQ(speedometer_k.get_speed(),77);
}

TEST_F(TestSpeedometer, TestSpeedometerMilesMileage) {
    ASSERT_EQ(speedometer_m.get_mileage(),153319);
}

TEST_F(TestSpeedometer, TestSpeedometerMilesSpeed) {
    ASSERT_EQ(speedometer_m.get_speed(),46);
}