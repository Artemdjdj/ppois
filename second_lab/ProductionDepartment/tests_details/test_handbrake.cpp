#include "include_handbrake.h"
#include <gtest/gtest.h>


class TestHandbrake : public ::testing::Test {
public:
    void SetUp() {
        handbrake = Handbrake();
    }
    Handbrake handbrake;
};

TEST_F(TestHandbrake, TestBlockCar) {
    handbrake.block_car();
    ASSERT_TRUE(handbrake.get_is_block());
}

TEST_F(TestHandbrake, TestUnBlockCar) {
    handbrake.unblock_car();
    ASSERT_FALSE(handbrake.get_is_block());
}