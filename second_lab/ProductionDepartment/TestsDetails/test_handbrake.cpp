#include "../Movement/handbrake.h"
#include <gtest/gtest.h>


class TestHandbrake : public ::testing::Test {
public:
    void SetUp() override{
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