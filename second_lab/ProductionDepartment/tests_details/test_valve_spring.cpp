#include "../Engine/valve_spring.h"
#include <gtest/gtest.h>

class TestValveSpring : public ::testing::Test {
public:
    ValveSpring valve_spring = ValveSpring(13,90 ,30, false);
};

TEST_F(TestValveSpring, TestCompress) {
    valve_spring.Compress();
    ASSERT_TRUE(valve_spring.CheckIsCompressed());
}

TEST_F(TestValveSpring, TestDeCompress) {
    valve_spring.DeCompress();
    ASSERT_FALSE(valve_spring.CheckIsCompressed());
}

TEST_F(TestValveSpring, TestDistBetweeNeighbours) {
    ASSERT_EQ(valve_spring.DistBetweenNeighbours(),3);
}

TEST_F(TestValveSpring, TestGetCountOfCoils) {
    ASSERT_EQ(valve_spring.GetCountOfCoils(),30);
}

