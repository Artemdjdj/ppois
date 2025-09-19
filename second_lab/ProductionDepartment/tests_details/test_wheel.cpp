
#include "include_wheel.h"
#include <gtest/gtest.h>
class TestWheel: public ::testing::Test {
public:
    void SetUp() override{
        wheel = Wheel(12, 34, 100, "ceramic", "blue", 5);
        wheel2 = Wheel(1, 10, 100, "gsdsd", "Green", 4);
        steering_wheel = SteeringWheel();
    }
    Wheel wheel;
    Wheel wheel2;
    SteeringWheel steering_wheel;
};

TEST_F(TestWheel, TestGetter) {
    ASSERT_EQ(wheel.get_count_of_bolts(), 5);
}

TEST_F(TestWheel, TestSetRadius) {
    wheel2.set_radius(10);
    ASSERT_EQ(wheel2.get_radius(), 10);
}

TEST_F(TestWheel, TestSetRadiusNegative) {
    ASSERT_FALSE(wheel2.set_radius(-10));
}

TEST_F(TestWheel, TestSetMaterial) {
    ASSERT_TRUE(wheel2.set_material("organic"));
}

TEST_F(TestWheel, TestSetMaterialBigLetters) {
    wheel2.set_material("ORGANIC");
    ASSERT_EQ(wheel2.get_type_of_material_to_brake_shoe(), "organic");
}

TEST_F(TestWheel, TestSetMaterialNegative) {
    ASSERT_FALSE(wheel2.set_material("Green"));
}

TEST_F(TestWheel, TestSetSizeNegativeHeight) {
    ASSERT_FALSE(wheel2.set_size(-10,5));
}

TEST_F(TestWheel, TestSetSizeNegativeWidth) {
    ASSERT_FALSE(wheel2.set_size(10,-15));
}

TEST_F(TestWheel, TestSetSizeCorrect) {
    ASSERT_TRUE(wheel2.set_size(10,15));
}

TEST_F(TestWheel, TestSetCountOfBolts) {
    wheel.set_count_of_bolts(3);
    ASSERT_EQ(wheel.get_count_of_bolts(), 3);
}

TEST_F(TestWheel, TestSetCountOfBoltsNegative) {
    wheel.set_count_of_bolts(-3);
    ASSERT_EQ(wheel.get_count_of_bolts(), 5);
}

TEST_F(TestWheel, TestSingalButtonMakeNoise) {
    ASSERT_TRUE(steering_wheel.clicked_button_to_make_noise());
}

TEST(TestSignalButton, TestGetSignal) {
    SignalButton signal_button = SignalButton();
    ASSERT_FALSE(signal_button.get_is_clicked());
}