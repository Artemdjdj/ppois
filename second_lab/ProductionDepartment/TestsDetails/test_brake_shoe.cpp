#include "basic_params.h"
#include "../Wheel/wheel.h"
#include "gtest/gtest.h"
#include "../../Exceptions/exceptions.h"

class TestingBrakeShoe : public ::testing::Test {
protected:
	void SetUp() override {
		material = "low-metal";
		brake_shoe = BrakeShoe(12, 25, "ceramic");
		brake_shoe.SetMaterial(material);
	}

	std::string material;
	BrakeShoe brake_shoe;
};

TEST_F(TestingBrakeShoe, TestMaterialPositive) {
	ASSERT_EQ("low-metal", brake_shoe.GetMaterial());
}

TEST_F(TestingBrakeShoe, TestMaterialNegative) {
	ASSERT_THROW(
		brake_shoe.SetMaterial("low-m"),
		ExceptionIncorrectMaterial
	);
	ASSERT_EQ("low-metal", brake_shoe.GetMaterial());
}

TEST_F(TestingBrakeShoe, TestHeight) {
	ASSERT_EQ(brake_shoe.GetHeight(), 12);
}

TEST_F(TestingBrakeShoe, TestWidth) {
	ASSERT_EQ(brake_shoe.GetWidth(), 25);
}

TEST_F(TestingBrakeShoe, TestSetHeight) {
	brake_shoe.SetHeight(56);
	ASSERT_EQ(brake_shoe.GetHeight(), 56);
}

TEST_F(TestingBrakeShoe, TestSetWidth) {
	brake_shoe.SetWidth(100);
	ASSERT_EQ(brake_shoe.GetWidth(), 100);
}

TEST_F(TestingBrakeShoe, TestSetHeightNegative) {
	ASSERT_THROW(
		brake_shoe.SetHeight(-56),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(brake_shoe.GetHeight(), 12);
}

TEST_F(TestingBrakeShoe, TestSetWidthNegative) {
	ASSERT_THROW(
		brake_shoe.SetWidth(-100),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(brake_shoe.GetWidth(), 25);
}

TEST(TestBrakeShoe, TestBigMaterial) {
	BrakeShoe brake_shoe = BrakeShoe();
	brake_shoe.SetMaterial("Low-MetAL");
	ASSERT_EQ("low-metal", brake_shoe.GetMaterial());
}
