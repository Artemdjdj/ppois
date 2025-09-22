#include "../Engine/piston.h"
#include <gtest/gtest.h>

TEST(TestPiston, TestSetAllParams) {
	Piston piston = Piston();
	ASSERT_TRUE(piston.SetAllParameters(2,3,4,5,6));
}

TEST(TestPiston, TestSetAllParamsNegative) {
	Piston piston = Piston();
	ASSERT_FALSE(piston.SetAllParameters(-2,3,4,5,6));
}

TEST(TestPiston, TestGetWeight) {
	Piston piston = Piston(2, 3, 4, 5, 6);
	ASSERT_EQ(piston.GetWeight(), 6);
}

TEST(TestPiston, TestWorkPiston) {
	Piston piston = Piston(2, 3, 4, 5, 6);
	ASSERT_TRUE(piston.CheckIsPistonInWorkingCondition());
}

TEST(TestPiston,PistonDescription) {
	Piston piston = Piston();
	EXPECT_EQ(piston.GetInfoAboutPart(),"This detail name is piston");
}