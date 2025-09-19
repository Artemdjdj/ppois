#include "include_mirror.h"
#include "include_basic_params.h"
#include <gtest/gtest.h>

class TestMirror :public ::testing::Test {
public:
    void SetUp() override{
        mirror = Mirror();
    }
    Mirror mirror;
};

TEST_F(TestMirror, TestSerialNumberCorrect) {
    mirror.set_serial_number("TR898989");
    EXPECT_EQ(mirror.get_serial_number(), "TR898989");
}

TEST_F(TestMirror, TestSerialNumberSmallLetters) {
    mirror.set_serial_number("tR898989");
    EXPECT_EQ(mirror.get_serial_number(), "");
}

TEST_F(TestMirror, TestSerialNumberIncorrectStructure) {
    mirror.set_serial_number("5R898989");
    EXPECT_EQ(mirror.get_serial_number(), "");
}

TEST_F(TestMirror, TestSerialNumberIncorrectLength) {
    mirror.set_serial_number("ER89898955");
    EXPECT_EQ(mirror.get_serial_number(), "");
}

TEST_F(TestMirror, TestSerialNumberIncorrectSmallLength) {
    mirror.set_serial_number("ER898");
    EXPECT_EQ(mirror.get_serial_number(), "");
}



