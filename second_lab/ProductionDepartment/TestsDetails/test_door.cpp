#include "../CarBody/door.h"
#include "basic_params.h"
#include <gtest/gtest.h>

#include "../../Exceptions/exceptions.h"

class TestDoor : public ::testing::Test {
protected:
	void SetUp() override {
		mirror = SideMirror(2, 3, base_color);
		front_door.SetMirror(mirror);
	}
	Color base_color = Color("blue");
	FrontDoor front_door = FrontDoor(78, 100, mirror, false);
	SideMirror mirror;
};

TEST_F(TestDoor, GetSizeOfDoor) {
	int height, width;
	front_door.GetSize(height, width);
	EXPECT_EQ(78, height);
	EXPECT_EQ(100, width);
}

TEST_F(TestDoor, GetColorOfSideMirror) {
	const std::string res_color = front_door.GetColorOfMirror();
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
	base_color.SetColor("green");
	mirror.SetColor(base_color);
	EXPECT_EQ(mirror.GetColor(), "green");
}

TEST_F(TestDoor, SetColorMirrorNegative) {
	ASSERT_THROW(
		base_color.SetColor("greens");
		mirror.SetColor(base_color),
		ExceptionIncorrectColor
	);
	EXPECT_EQ(mirror.GetColor(), "blue");
}

TEST_F(TestDoor, FrontDoorDescription) {
	EXPECT_EQ(front_door.GetInfoAboutPart(), "This detail name is front door");
}

TEST_F(TestDoor, SideMirrorDescription) {
	EXPECT_EQ(mirror.GetInfoAboutPart(), "This detail name is side mirror");
}
