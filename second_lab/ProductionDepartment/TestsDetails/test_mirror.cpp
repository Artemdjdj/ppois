#include "../CarBody/mirror.h"
#include "basic_params.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

class TestMirror : public ::testing::Test {
public:
	void SetUp() override {
		mirror = Mirror();
	}

	Mirror mirror;
};

TEST_F(TestMirror, TestSerialNumberCorrect) {
	mirror.SetSerialNumber("TR898989");
	EXPECT_EQ(mirror.GetSerialNumber(), "TR898989");
}

TEST_F(TestMirror, TestSerialNumberSmallLetters) {
	ASSERT_THROW(
		mirror.SetSerialNumber("tR898989"),
		ExceptionIncorrectSerialNumber
	);
	EXPECT_EQ(mirror.GetSerialNumber(), "");
}

TEST_F(TestMirror, TestSerialNumberIncorrectStructure) {
	ASSERT_THROW(
		mirror.SetSerialNumber("5R898989"),
		ExceptionIncorrectSerialNumber
	);
	EXPECT_EQ(mirror.GetSerialNumber(), "");
}

TEST_F(TestMirror, TestSerialNumberIncorrectLength) {
	ASSERT_THROW(
		mirror.SetSerialNumber("ER89898955"),
		ExceptionIncorrectSerialNumber
	);
	EXPECT_EQ(mirror.GetSerialNumber(), "");
}

TEST_F(TestMirror, TestSerialNumberIncorrectSmallLength) {
	ASSERT_THROW(
		mirror.SetSerialNumber("ER898"),
		ExceptionIncorrectSerialNumber
	);
	EXPECT_EQ(mirror.GetSerialNumber(), "");
}

TEST(TestMirrorConstructor, TestConstructor) {
	Mirror mirror = Mirror(100, 200, 15, false, "TR898989");
	int height, width, thickness;
	bool is_tinting;
	std::string serial_number;
	mirror.GetInformationAboutMirror(height, width, thickness, is_tinting, serial_number);
	EXPECT_EQ(100, height);
	EXPECT_EQ(200, width);
	EXPECT_EQ(15, thickness);
	EXPECT_EQ("TR898989", serial_number);
	ASSERT_FALSE(is_tinting);
}

TEST_F(TestMirror, MakeTinting) {
	mirror.MakeMirrorTinting();
	ASSERT_TRUE(mirror.GetIsTinting());
}

TEST_F(TestMirror, ClearTinting) {
	mirror.ClearTinting();
	ASSERT_FALSE(mirror.GetIsTinting());
}

TEST_F(TestMirror, MirrorDescription) {
	EXPECT_EQ(mirror.GetInfoAboutPart(), "This detail name is mirror");
}
