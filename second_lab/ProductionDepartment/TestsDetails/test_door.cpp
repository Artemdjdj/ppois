#include "../CarBody/door.h"
#include "basic_params.h"
#include <gtest/gtest.h>

#include "../../Exceptions/exceptions.h"

class TestDoor : public ::testing::Test {
protected:
	void SetUp() override {
		front_door = FrontDoor(78, 100, 15, 17, false, "blue");
		mirror = SideMirror(2, 3);
	}

	FrontDoor front_door;
	SideMirror mirror;
};

TEST_F(TestDoor, GetSizeOfDoor) {
	int height, width;
	front_door.GetSize(height, width);
	EXPECT_EQ(78, height);
	EXPECT_EQ(100, width);
}

TEST_F(TestDoor, GetColorOfSideMirror) {
	std::string res_color;
	front_door.GetColorOfMirror(res_color);
	EXPECT_EQ(res_color, "blue");
}

TEST_F(TestDoor, SetLockIsFalse) {
	front_door.CloseDoor();
	EXPECT_FALSE(front_door.GetLock());
}

TEST_F(TestDoor, SetLockIsTrue) {
	front_door.OpenDoor();
	EXPECT_TRUE(front_door.GetLock());
}

TEST_F(TestDoor, SetColorMirror) {
	mirror.SetColor("green");
	EXPECT_EQ(mirror.GetColor(), "green");
}

TEST_F(TestDoor, SetColorMirrorNegative) {
	ASSERT_THROW(
		mirror.SetColor("greens"),
		ExceptionIncorrectColor
	);
	EXPECT_EQ(mirror.GetColor(), "black");
}

TEST_F(TestDoor, FrontDoorDescription) {
	EXPECT_EQ(front_door.GetInfoAboutPart(), "This detail name is front door");
}

TEST_F(TestDoor, SideMirrorDescription) {
	EXPECT_EQ(mirror.GetInfoAboutPart(), "This detail name is side mirror");
}
