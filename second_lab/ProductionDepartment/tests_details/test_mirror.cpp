#include "../CarBody/mirror.h"
#include "basic_params.h"
#include <gtest/gtest.h>

class TestMirror :public ::testing::Test {
public:
    void SetUp() override{
        mirror = Mirror();
    }
    Mirror mirror;
};

TEST_F(TestMirror, TestSerialNumberCorrect) {
    mirror.SetSerialNumber("TR898989");
    EXPECT_EQ(mirror.GetSerialNumber(), "TR898989");
}

TEST_F(TestMirror, TestSerialNumberSmallLetters) {
    mirror.SetSerialNumber("tR898989");
    EXPECT_EQ(mirror.GetSerialNumber(), "");
}

TEST_F(TestMirror, TestSerialNumberIncorrectStructure) {
    mirror.SetSerialNumber("5R898989");
    EXPECT_EQ(mirror.GetSerialNumber(), "");
}

TEST_F(TestMirror, TestSerialNumberIncorrectLength) {
    mirror.SetSerialNumber("ER89898955");
    EXPECT_EQ(mirror.GetSerialNumber(), "");
}

TEST_F(TestMirror, TestSerialNumberIncorrectSmallLength) {
    mirror.SetSerialNumber("ER898");
    EXPECT_EQ(mirror.GetSerialNumber(), "");
}



