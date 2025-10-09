#include "../Engine/piston.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

TEST(TestPiston, TestSetAllParams) {
	Piston piston = Piston();
	piston.SetAllParameters(2, 3, 4, 5, 6);
}

TEST(TestPiston, TestSetAllParamsNegative) {
	Piston piston = Piston();
	ASSERT_THROW(
		piston.SetAllParameters(-2,3,4,5,6),
		ExceptionIncorrectSize
	);
}

TEST(TestPiston, TestGetWeight) {
	Piston piston = Piston(2, 3, 4, 5, 6);
	ASSERT_EQ(piston.GetWeight(), 6);
}

TEST(TestPiston, TestWorkPiston) {
	Piston piston = Piston(2, 3, 4, 5, 6);
	ASSERT_TRUE(piston.CheckIsPistonInWorkingCondition());
}

TEST(TestPiston, PistonDescription) {
	Piston piston = Piston();
	EXPECT_EQ(piston.GetInfoAboutPart(), "This detail name is piston");
}
