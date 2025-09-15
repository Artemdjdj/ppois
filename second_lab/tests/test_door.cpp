#include "include_door.h"
#include "include_basic_params.h"
#include <gtest/gtest.h>
class TestDoor: public ::testing::Test {
protected:
    void SetUp() override {
        front_door = FrontDoor(78, 100, 15, 17, false,"blue");
    }
    FrontDoor front_door;
};

TEST_F(TestDoor, GetSizeOfDoor) {
    int height, width;
    front_door.get_size(height, width);
    EXPECT_EQ(78,height);
    EXPECT_EQ(100,width);
}

TEST_F(TestDoor, GetColorOfSideMirror) {
    string res_color;
    front_door.get_color_of_mirror(res_color);
    EXPECT_EQ(res_color, "blue");
}

TEST_F(TestDoor, SetLockIsFalse) {
    front_door.close_door();
    EXPECT_FALSE(front_door.get_lock());
}
TEST_F(TestDoor, SetLockIsTrue) {
    front_door.open_door();
    EXPECT_TRUE(front_door.get_lock());
}

