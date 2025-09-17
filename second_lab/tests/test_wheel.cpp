
#include "include_wheel.h"
#include <gtest/gtest.h>
class WheelTest: public ::testing::Test {
public:
    void SetUp() {
        wheel = Wheel(12, 34, 100, "ceramic", "blue", 5);
        wheel2 = Wheel(1, 10, 100, "gsdsd", "Green", 4);
    }
    Wheel wheel;
    Wheel wheel2;
};

TEST_F(WheelTest, TestGetter) {
    ASSERT_EQ(wheel.get_count_of_bolts(), 5);
}

TEST_F(WheelTest, TestSetRadius) {
   wheel2.set_radius(10);
    ASSERT_EQ(wheel2.get_radius(), 10);
}

TEST_F(WheelTest, TestSetRadiusNegative) {
    ASSERT_FALSE(wheel2.set_radius(-10));
}

TEST_F(WheelTest, TestSetMaterial) {
    ASSERT_TRUE(wheel2.set_material("organic"));
}

TEST_F(WheelTest, TestSetMaterialBigLetters) {
    wheel2.set_material("ORGANIC");
    ASSERT_EQ(wheel2.get_type_of_material_to_brake_shoe(), "organic");
}

TEST_F(WheelTest, TestSetMaterialNegative) {
    ASSERT_FALSE(wheel2.set_material("Green"));
}

TEST_F(WheelTest, TestSetSizeNegativeHeight) {
    ASSERT_FALSE(wheel2.set_size(-10,5));
}

TEST_F(WheelTest, TestSetSizeNegativeWidth) {
    ASSERT_FALSE(wheel2.set_size(10,-15));
}

TEST_F(WheelTest, TestSetSizeCorrect) {
    ASSERT_TRUE(wheel2.set_size(10,15));
}

TEST_F(WheelTest, TestSetCountOfBolts) {
    wheel.set_count_of_bolts(3);
    ASSERT_EQ(wheel.get_count_of_bolts(), 3);
}

TEST_F(WheelTest, TestSetCountOfBoltsNegative) {
    wheel.set_count_of_bolts(-3);
    ASSERT_EQ(wheel.get_count_of_bolts(), 5);
}

