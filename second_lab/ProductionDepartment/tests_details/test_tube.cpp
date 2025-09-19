#include "include_tube.h"
#include <gtest/gtest.h>

TEST(TestTube, TestTubeGetHeight) {
    const auto tube = Tube(10, 10);
    ASSERT_EQ(tube.get_height(), 10);
}

TEST(TestTube, TestTubeSetHeight) {
    auto tube = Tube();
    tube.set_height(120);
    ASSERT_EQ(tube.get_height(), 120);
}

TEST(TestTube, TestTubeSetHeightNegative) {
    auto tube = Tube();
    tube.set_height(-120);
    ASSERT_EQ(tube.get_height(), 0);
}

TEST(TestTube, TestTubeSetRadiusNegative) {
    auto tube = Tube();
    tube.set_radius(-120);
    ASSERT_EQ(tube.get_radius(), 0);
}

TEST(TestTube, TestTubeSetRadius) {
    auto tube = Tube();
    tube.set_radius(12);
    ASSERT_EQ(tube.get_radius(), 12);
}