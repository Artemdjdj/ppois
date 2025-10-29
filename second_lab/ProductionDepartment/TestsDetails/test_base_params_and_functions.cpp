#include <gtest/gtest.h>
#include "basic_params.h"
#include "settings.h"
#include "../../Exceptions/exceptions.h"

class TestingBasicParams : public ::testing::Test {
public:
	void SetUp() override {
		color = Color("green");
		basic_params = BasicParams();
	}

	Color color;
	BasicParams basic_params;
};

TEST(Testingtolower, BigLetters) {
	std::string word = "GGGG";
	CarStringFormatter::ToLower(word);
	ASSERT_EQ(word, "gggg");
}

TEST(Testingtolower, SmallLettersWithBigletters) {
	std::string word = "Hello wOrlD";
	CarStringFormatter::ToLower(word);
	ASSERT_EQ(word, "hello world");
}

TEST_F(TestingBasicParams, TestCheckFunctionPositive) {
	color.SetColor("blue");
	ASSERT_EQ(color.GetColor(), "blue");
}

TEST_F(TestingBasicParams, TestCheckFunctionNegative) {
	ASSERT_THROW(
		color.SetColor("KJhksfd"),
		ExceptionIncorrectColor
	);
	ASSERT_EQ(color.GetColor(), "green");
}

TEST_F(TestingBasicParams, TestCheckFunctionPositiveAllLettersAreBig) {
	color.SetColor("RED");
	ASSERT_EQ(color.GetColor(), "red");
}

TEST(TestVolume, TestSetCorrectVolume) {
	Volume volume = Volume();
	volume.SetVolume(10);
	ASSERT_EQ(volume.GetVolume(), 10);
}

TEST(TestVolume, TestSetInCorrectVolume) {
	Volume volume = Volume();
	ASSERT_THROW(
		volume.SetVolume(-10),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(volume.GetVolume(), 0);
}


TEST_F(TestingBasicParams, TestSetHeight) {
	basic_params.SetHeight(10);
	ASSERT_EQ(basic_params.GetHeight(), 10);
}

TEST_F(TestingBasicParams, TestSetWidth) {
	basic_params.SetWidth(11);
	ASSERT_EQ(basic_params.GetWidth(), 11);
}

TEST_F(TestingBasicParams, TestSetWidthNegative) {
	ASSERT_THROW(
		basic_params.SetWidth(-11),
		ExceptionIncorrectSize
	);
}

TEST_F(TestingBasicParams, TestSetHeightNegative) {
	ASSERT_THROW(
		basic_params.SetHeight(-1),
		ExceptionIncorrectSize
	);
}

TEST_F(TestingBasicParams, TestSetSize) {
	basic_params.SetSize(10, 10);
}

TEST_F(TestingBasicParams, TestSetSizeCheckValues) {
	int height, width;
	basic_params.SetSize(10, 10);
	basic_params.GetSize(height, width);
	ASSERT_EQ(height, 10);
	ASSERT_EQ(width, 10);
}

TEST(SetSinglePercent, TestCorrectPercent) {
	int value;
	CarSetter::SetSinglePercent(30, value);
	ASSERT_EQ(value, 30);
}

TEST(SetSinglePercent, TestInCorrectPercentNegativeNumber) {
	int value;
	ASSERT_THROW(
		CarSetter::SetSinglePercent(-30,value ),
		ExceptionIncorrectSize
	);
}

TEST(SetSinglePercent, TestInCorrectPercentNumberBiggerThenOneHundred) {
	int value;
	ASSERT_THROW(
		CarSetter::SetSinglePercent(3000,value ),
		ExceptionIncorrectSize
	);
}


TEST(SetSingleValue, TestInCorrectPercentNegativeNumber) {
	int value;
	ASSERT_THROW(
		CarSetter::SetSingleValue(-30,"some information",value ),
		ExceptionIncorrectSize
	);
}

TEST(SetSingleValue, TestCorrectNumber) {
	int value;
	CarSetter::SetSingleValue(30, "Some information", value);
	ASSERT_EQ(value, 30);
}

TEST(CheckIsStatementCorrect, CorrectRes) {
	std::string res = "petrol";
	ASSERT_TRUE(CarValidator::CheckIsStatementCorrect(kTypeOfFuels, res));
}

TEST(CheckIsStatementCorrect, CorrectResBigLetter) {
	std::string res = "Petrol";
	ASSERT_TRUE(CarValidator::CheckIsStatementCorrect(kTypeOfFuels, res));
}

TEST(CheckIsStatementCorrect, InCorrectRes) {
	std::string res = "petrols";
	ASSERT_FALSE(CarValidator::CheckIsStatementCorrect(kTypeOfFuels, res));
}
