#include "include_mirror.h"
#include "include_basic_params.h"
#include <gtest/gtest.h>

TEST(TestMirror, TestSerialNumberCorrect) {
    EXPECT_EQ(true, Mirror().set_serial_number("TR898989"));
}

TEST(TestMirror, TestSerialNumberSmallLetters) {
    ASSERT_FALSE(Mirror().set_serial_number("tR898989"));
}

TEST(TestMirror, TestSerialNumberIncorrectStructure) {
    ASSERT_FALSE(Mirror().set_serial_number("5R898989"));
}

TEST(TestMirror, TestSerialNumberIncorrectLength) {
    ASSERT_FALSE(Mirror().set_serial_number("ER89898955"));
}

TEST(TestMirror, TestSerialNumberIncorrectLengthSmall) {
    ASSERT_FALSE(Mirror().set_serial_number("ER898"));
}

