#include "../Engine/tube.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"
TEST(TestTube, TestTubeGetHeight) {
	const auto tube = Tube(10, 10);
	ASSERT_EQ(tube.GetHeight(), 10);
}

TEST(TestTube, TestTubeSetHeight) {
	auto tube = Tube();
	tube.SetHeight(120);
	ASSERT_EQ(tube.GetHeight(), 120);
}

TEST(TestTube, TestTubeSetHeightNegative) {
	auto tube = Tube();
	ASSERT_THROW(
		tube.SetHeight(-120),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(tube.GetHeight(), 0);
}

TEST(TestTube, TestTubeSetRadiusNegative) {
	auto tube = Tube();
	ASSERT_THROW(
		tube.SetRadius(-120),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(tube.GetRadius(), 0);
}

TEST(TestTube, TestTubeSetRadius) {
	auto tube = Tube();
	tube.SetRadius(12);
	ASSERT_EQ(tube.GetRadius(), 12);
}

TEST(TestTube, TubeDescription) {
	Tube tube = Tube();
	EXPECT_EQ(tube.GetInfoAboutPart(), "This detail name is tube");
}
