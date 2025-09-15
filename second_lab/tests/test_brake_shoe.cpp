#include "include_basic_params.h"
#include "include_wheel.h"
#include "gtest/gtest.h"

class TestingBrakeShoe: public ::testing::Test {
protected:
    void SetUp() override {
        material = "low-metal";
        brake_shoe = BrakeShoe(12, 25, "ceramic", "green");
        brake_shoe.set_material(material);
        brake_shoe.set_size(56, 70);
    }
    string material;
    BrakeShoe brake_shoe;
};

TEST_F(TestingBrakeShoe, TestMaterialPositive) {
    ASSERT_EQ("low-metal", brake_shoe.get_material());
}
TEST_F(TestingBrakeShoe, TestMaterialNegative) {
    brake_shoe.set_material("low-m");
    ASSERT_EQ("low-metal", brake_shoe.get_material());
}

TEST_F(TestingBrakeShoe, TestHeight) {
    ASSERT_EQ(brake_shoe.get_height(),56);
}

TEST_F(TestingBrakeShoe, TestWidth) {
    ASSERT_EQ(brake_shoe.get_width(),70);
}

TEST(TestBrakeShoe, TestBigMaterial) {
    BrakeShoe brake_shoe = BrakeShoe();
    brake_shoe.set_material("Low-MetAL");
    ASSERT_EQ("low-metal", brake_shoe.get_material());
}
