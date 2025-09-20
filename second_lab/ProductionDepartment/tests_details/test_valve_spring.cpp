#include "include_valve_spring.h"
#include <gtest/gtest.h>

class TestValveSpring : public ::testing::Test {
public:
    ValveSpring valve_spring = ValveSpring(13,90 ,30, false);
};

TEST_F(TestValveSpring, TestCompress) {
    valve_spring.compress();
    ASSERT_TRUE(valve_spring.check_is_compressed());
}

TEST_F(TestValveSpring, TestDeCompress) {
    valve_spring.decompress();
    ASSERT_FALSE(valve_spring.check_is_compressed());
}

TEST_F(TestValveSpring, TestDistBetweeNeighbours) {
    ASSERT_EQ(valve_spring.dist_between_neighbours(),3);
}

TEST_F(TestValveSpring, TestGetCountOfCoils) {
    ASSERT_EQ(valve_spring.get_count_of_coils(),30);
}

