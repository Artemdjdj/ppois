#include "../include/include_door.h"
#include <gtest/gtest.h>

TEST(TestDoor, GetSizeOfDoor) {
    FrontDoor front_door = FrontDoor(78, 100, 15, 17, false,"blue");
    int height, width;
    front_door.get_size(height, width);
    EXPECT_EQ(78,height);
    EXPECT_EQ(100,width);
}

TEST(TestDoor, GetColorOfSideMirror) {
    FrontDoor front_door = FrontDoor(78, 100, 15, 17,false, "blue");
    string res_color;
    front_door.get_color_of_mirror(res_color);
    EXPECT_EQ(res_color, "blue");
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}