#include "user_utils.h"
#include <string>
#include <gtest/gtest.h>

std::string error_message;

TEST(TestCheckUserName, TestCorrectUserName) {
	ASSERT_TRUE(UserDataSyntax::CheckUserNameForSyntaxError("@Artemdjdj", error_message));
}

TEST(TestCheckUserName, TestCorrectUserNameSpecialSymbols) {
	ASSERT_TRUE(UserDataSyntax::CheckUserNameForSyntaxError("@Artemd_jdj", error_message));
}


TEST(TestCheckUserName, TestIncorrectUserName) {
	ASSERT_FALSE(UserDataSyntax::CheckUserNameForSyntaxError("@Artemdjdj!", error_message));
}

TEST(TestCheckUserName, TestIncorrectLengthUserName) {
	ASSERT_FALSE(UserDataSyntax::CheckUserNameForSyntaxError("@Artemdjdjlglsjldkgjskldjglskljgsfsdf", error_message));
}

TEST(TestCheckName, TestCorrectName) {
	ASSERT_TRUE(UserDataSyntax::CheckNameOrSurnameForSyntaxError("Artemdjdj", error_message));
}

TEST(TestCheckName, TestCorrectNameWithHyphen) {
	ASSERT_TRUE(UserDataSyntax::CheckNameOrSurnameForSyntaxError("Artemdjdj-legend", error_message));
}

TEST(TestCheckName, TestIncorrectNameFirstSymbolHyphen) {
	ASSERT_FALSE(UserDataSyntax::CheckNameOrSurnameForSyntaxError("-Artemdjdj", error_message));
}

TEST(TestCheckName, TestIncorrectNameLastSymbolHyphen) {
	ASSERT_FALSE(UserDataSyntax::CheckNameOrSurnameForSyntaxError("Artemdjdj-", error_message));
}

TEST(TestCheckName, TestIncorrectLengthName) {
	ASSERT_FALSE(
		UserDataSyntax::CheckNameOrSurnameForSyntaxError(
			"Artemdjdjhfjkshfkhsdkfkjdhfkjhskfhkhfkjhjkfhjiksdhfjkhsdhjkhkhkjgjdfljgljdflgjldfkjgldjflgjdflgjlkdfjsgflk;fjglkjskljglkjslkgjdklf"
			, error_message));
}

TEST(TestCheckEmail, TestCorrectEmailGmail) {
	ASSERT_TRUE(UserDataSyntax::CheckEmailForSyntaxError("vlad2007@gmail.com", error_message));
}

TEST(TestCheckEmail, TestCorrectEmailYandex) {
	ASSERT_TRUE(UserDataSyntax::CheckEmailForSyntaxError("vlad2007@yandex.ru", error_message));
}

TEST(TestCheckEmail, TestIncorrectEmail) {
	ASSERT_FALSE(UserDataSyntax::CheckEmailForSyntaxError("hello world", error_message));
}

TEST(TestCheckEmail, TestIncorrectEmailEmpty) {
	ASSERT_FALSE(UserDataSyntax::CheckEmailForSyntaxError("", error_message));
}

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumberCodeOne) {
	ASSERT_TRUE(UserDataSyntax::CheckPhoneNumberForSyntaxError("+375291111345", error_message));
}

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumberCodeTwo) {
	ASSERT_TRUE(UserDataSyntax::CheckPhoneNumberForSyntaxError("+375251111345", error_message));
}

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumberCodeThree) {
	ASSERT_TRUE(UserDataSyntax::CheckPhoneNumberForSyntaxError("+375331111345", error_message));
}

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumberCodeFour) {
	ASSERT_TRUE(UserDataSyntax::CheckPhoneNumberForSyntaxError("80291111345", error_message));
}

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumberCodeFive) {
	ASSERT_TRUE(UserDataSyntax::CheckPhoneNumberForSyntaxError("80441111345", error_message));
}

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumberCodeSix) {
	ASSERT_TRUE(UserDataSyntax::CheckPhoneNumberForSyntaxError("80251111345", error_message));
}

TEST(TestCheckPhoneNumber, TestIncorrectPhoneNumberLength) {
	ASSERT_FALSE(UserDataSyntax::CheckPhoneNumberForSyntaxError("+3752911113456", error_message));
}

TEST(TestCheckPhoneNumber, TestIncorrectPhoneNumberCode) {
	ASSERT_FALSE(UserDataSyntax::CheckPhoneNumberForSyntaxError("+3752711113456", error_message));
}

TEST(TestCheckPhoneNumber, TestIncorrectPhoneNumber) {
	ASSERT_FALSE(UserDataSyntax::CheckPhoneNumberForSyntaxError("3752911113456", error_message));
}

TEST(TestCheckPassword, TestCorrectPassword) {
	ASSERT_TRUE(UserDataSyntax::CheckPasswordForSyntaxError("hffw5443hs", error_message));
}

TEST(TestCheckPassword, TestInorrectPasswordShortLength) {
	ASSERT_FALSE(UserDataSyntax::CheckPasswordForSyntaxError("hf4gd", error_message));
}

TEST(TestCheckPassword, TestInorrectPasswordLongLength) {
	ASSERT_FALSE(UserDataSyntax::CheckPasswordForSyntaxError("gdfgljsljlgjldjlgjldfjogi435034503485348590gkjdfhglkdfsj89wutonoy834", error_message));
}