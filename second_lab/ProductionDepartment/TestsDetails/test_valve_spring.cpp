#include "../Engine/valve_spring.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

class TestValveSpring : public ::testing::Test {
public:
	ValveSpring valve_spring = ValveSpring(13, 90, 30, false);
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
	ASSERT_EQ(valve_spring.DistBetweenNeighbours(), 3);
}

TEST_F(TestValveSpring, TestGetCountOfCoils) {
	ASSERT_EQ(valve_spring.GetCountOfCoils(), 30);
}

TEST_F(TestValveSpring, TestSetAllParameters) {
	valve_spring.SetAllParameters(10, 9, 9);
}

TEST_F(TestValveSpring, TestSetAllParametersNegative1) {
	ASSERT_THROW(
		valve_spring.SetAllParameters(-10, 9,9);,
		ExceptionIncorrectSize
	);
}

TEST_F(TestValveSpring, TestSetAllParametersNegative2) {
	ASSERT_THROW(
		valve_spring.SetAllParameters(10, -9,9),
		ExceptionIncorrectSize
	);
}

TEST_F(TestValveSpring, TestSetAllParametersNegative3) {
	ASSERT_THROW(
		valve_spring.SetAllParameters(10, 9,-9),
		ExceptionIncorrectSize
	);
}

TEST_F(TestValveSpring, TestGetLength) {
	ASSERT_EQ(valve_spring.GetLength(), 90);
}

TEST_F(TestValveSpring, TestGetCoils) {
	ASSERT_EQ(valve_spring.GetCountOfCoils(), 30);
}


TEST_F(TestValveSpring, TestDistNeighbours) {
	ASSERT_EQ(valve_spring.DistBetweenNeighbours(), 3);
}

TEST_F(TestValveSpring, TestDevisionByZero) {
	valve_spring.SetAllParameters(1, 2, 0);
	ASSERT_EQ(valve_spring.DistBetweenNeighbours(), 0);
}

TEST_F(TestValveSpring, ValveSpringDescription) {
	EXPECT_EQ(valve_spring.GetInfoAboutPart(), "This detail name is valve spring");
}
