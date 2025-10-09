#include "../Wheel/wheel.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

class TestWheel : public ::testing::Test {
public:
	void SetUp() override {
		wheel = Wheel(12, 34, 100, "ceramic", 5);
		wheel2 = Wheel(1, 10, 100, "gsdsd",  4);
		steering_wheel = SteeringWheel();
	}

	Wheel wheel;
	Wheel wheel2;
	SteeringWheel steering_wheel;
};

TEST_F(TestWheel, TestGetter) {
	ASSERT_EQ(wheel.GetCountOfBolts(), 5);
}

TEST_F(TestWheel, TestSetRadius) {
	wheel2.SetRadius(10);
	ASSERT_EQ(wheel2.GetRadius(), 10);
}

TEST_F(TestWheel, TestSetRadiusNegative) {
	ASSERT_THROW(
		wheel2.SetRadius(-10),
		ExceptionIncorrectSize
	);

}

TEST_F(TestWheel, TestSetMaterial) {
	wheel2.SetMaterial("organic");
}

TEST_F(TestWheel, TestSetMaterialBigLetters) {
	wheel2.SetMaterial("ORGANIC");
	ASSERT_EQ(wheel2.GetTypeOfMaterialToBrakeShoe(), "organic");
}

TEST_F(TestWheel, TestSetMaterialNegative) {
	ASSERT_THROW(
		wheel2.SetMaterial("Green"),
		ExceptionIncorrectMaterial
	);
}

TEST_F(TestWheel, TestSetSizeNegativeHeight) {
	ASSERT_THROW(
		wheel2.SetSize(-10,5),
		ExceptionIncorrectSize
	);
}

TEST_F(TestWheel, TestSetSizeNegativeWidth) {
	ASSERT_THROW(
		wheel2.SetSize(10,-15),
		ExceptionIncorrectSize
	);
}

TEST_F(TestWheel, TestSetSizeCorrect) {
	wheel2.SetSize(10,15);
}

TEST_F(TestWheel, TestSetCountOfBolts) {
	wheel.SetCountOfBolts(3);
	ASSERT_EQ(wheel.GetCountOfBolts(), 3);
}

TEST_F(TestWheel, TestSetCountOfBoltsNegative) {
	ASSERT_THROW(
		wheel.SetCountOfBolts(-3),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(wheel.GetCountOfBolts(), 5);
}

TEST_F(TestWheel, TestSingalButtonMakeNoise) {
	ASSERT_TRUE(steering_wheel.ClickedButtonToMakeNoise());
}

TEST(TestSignalButton, TestGetSignal) {
	SignalButton signal_button = SignalButton();
	ASSERT_FALSE(signal_button.GetIsClicked());
}

TEST(TestSignalButton, TestConstructor) {
	SignalButton signal_button = SignalButton(10, 20, false);
	signal_button.SetSizeForButton(11, 12);
	int height, width;
	signal_button.GetSize(height, width);
	ASSERT_EQ(height, 11);
	ASSERT_EQ(width, 12);
}

TEST_F(TestWheel, TestSteeringWheelRadius) {
	steering_wheel.SetRadiusOfSteeringWheel(10);
	ASSERT_EQ(steering_wheel.GetRadiusOfSteeringWheel(), 10);
}

TEST_F(TestWheel, TestSteeringWheelRadiusLogo) {
	steering_wheel.SetRadiusOfCenterLogo(3);
	ASSERT_EQ(steering_wheel.GetRadiusOfCenterLogo(), 3);
}

TEST_F(TestWheel, TestIsClicked) {
	ASSERT_FALSE(steering_wheel.GetIsClicked());
}

TEST_F(TestWheel, SteeringWheelDescription) {
	ASSERT_EQ(steering_wheel.GetInfoAboutPart(),"This detail name is steering wheel");
}

TEST_F(TestWheel, WheelDescription) {
	ASSERT_EQ(wheel.GetInfoAboutPart(),"This detail name is wheel");
}

