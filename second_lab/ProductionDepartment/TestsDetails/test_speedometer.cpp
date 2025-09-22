#include "../Speedometer/speedometer.h"
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
	ASSERT_EQ(speedometer_k.GetMileage(), 255533);
}

TEST_F(TestSpeedometer, TestSpeedometerKilometersSpeed) {
	ASSERT_EQ(speedometer_k.GetSpeed(), 77);
}

TEST_F(TestSpeedometer, TestSpeedometerMilesMileage) {
	ASSERT_EQ(speedometer_m.GetMileage(), 153319);
}

TEST_F(TestSpeedometer, TestSpeedometerMilesSpeed) {
	ASSERT_EQ(speedometer_m.GetSpeed(), 46);
}

TEST(TestSpeedometerSet, TestSetKilometersSpeed) {
	SpeedometerInKilometers speedometer_k = SpeedometerInKilometers();
	speedometer_k.SetSpeed(200);
	ASSERT_EQ(speedometer_k.GetSpeed(), 200);
}

TEST(TestSpeedometerSet, TestSetKilometersSpeedNegative) {
	SpeedometerInKilometers speedometer_k = SpeedometerInKilometers();
	ASSERT_FALSE(speedometer_k.SetSpeed(-200));
}

TEST(TestSpeedometerSet, TestSetKilometersMileage) {
	SpeedometerInKilometers speedometer_k = SpeedometerInKilometers();
	speedometer_k.SetMileage(20);
	ASSERT_EQ(speedometer_k.GetMileage(), 20);
}

TEST(TestSpeedometerSet, TestSetKilometersMileageNegative) {
	SpeedometerInKilometers speedometer_k = SpeedometerInKilometers();
	ASSERT_FALSE(speedometer_k.SetMileage(-200));
}

TEST(TestSpeedometerSet, TestSetMilesSpeed) {
	SpeedometerInMiles speedometer_m = SpeedometerInMiles();
	speedometer_m.SetSpeed(200);
	ASSERT_EQ(speedometer_m.GetSpeed(), 120);
}

TEST(TestSpeedometerSet, TestSetMilesSpeedNegative) {
	SpeedometerInMiles speedometer_m = SpeedometerInMiles();
	ASSERT_FALSE(speedometer_m.SetSpeed(-200));
}

TEST(TestSpeedometerSet, TestSetMilesMileage) {
	SpeedometerInMiles speedometer_m = SpeedometerInMiles();
	speedometer_m.SetMileage(20);
	ASSERT_EQ(speedometer_m.GetMileage(), 12);
}

TEST(TestSpeedometerSet, TestSetMilesMileageNegative) {
	SpeedometerInMiles speedometer_m = SpeedometerInMiles();
	ASSERT_FALSE(speedometer_m.SetMileage(-200));
}

TEST(TestSpeedometerK,SpeedometerKDescription) {
	SpeedometerInKilometers speedometer_k = SpeedometerInKilometers();
	EXPECT_EQ(speedometer_k.GetInfoAboutPart(),"This detail name is speedometer in kilometers");
}

TEST(TestSpeedometerM,SpeedometerMDescription) {
	SpeedometerInMiles speedometer_m = SpeedometerInMiles();
	EXPECT_EQ(speedometer_m.GetInfoAboutPart(),"This detail name is speedometer in miles");
}