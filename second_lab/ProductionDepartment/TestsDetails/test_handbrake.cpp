#include "../Movement/handbrake.h"
#include <gtest/gtest.h>


class TestHandbrake : public ::testing::Test {
public:
	void SetUp() override {
		handbrake = Handbrake();
	}

	Handbrake handbrake;
};

TEST_F(TestHandbrake, TestBlockCar) {
	handbrake.BlockCar();
	ASSERT_TRUE(handbrake.GetIsBlock());
}

TEST_F(TestHandbrake, TestUnblockCar) {
	handbrake.UnblockCar();
	ASSERT_FALSE(handbrake.GetIsBlock());
}

TEST(TestHandbrakeConstructor, TestConstructor) {
	Handbrake handbrake = Handbrake(70, 50, true);
	ASSERT_EQ(handbrake.GetIsBlock(), true);
	ASSERT_EQ(handbrake.GetHeight(), 70);
	ASSERT_EQ(handbrake.GetWidth(), 50);
}

TEST_F(TestHandbrake, TestSetSize) {
	ASSERT_TRUE(handbrake.SetSize(70, 50));
}

TEST_F(TestHandbrake, TestSetIncorrectSize1) {
	ASSERT_FALSE(handbrake.SetSize(-70, 50));
}

TEST_F(TestHandbrake, TestSetIncorrectSize2) {
	ASSERT_FALSE(handbrake.SetSize(70, -50));
}

TEST_F(TestHandbrake,FeelerDescription) {
	EXPECT_EQ(handbrake.GetInfoAboutPart(),"This detail name is handbrake");
}