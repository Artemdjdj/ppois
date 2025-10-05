#include "user_utils.h"
#include <string>
#include <gtest/gtest.h>
#include <../Exceptions/exceptions.h>

std::string error_message;

TEST(TestCheckUserName, TestCorrectUserName) {
	std::string username;
	DataSyntax::CheckUserNameForSyntaxError("@Artemdjdj", error_message, username);
	ASSERT_EQ(username, "@Artemdjdj");
}

TEST(TestCheckUserName, TestCorrectUserNameSpecialSymbols) {
	std::string username;
	DataSyntax::CheckUserNameForSyntaxError("@Artemd_jdj", error_message, username);
	ASSERT_EQ(username, "@Artemd_jdj");
}


TEST(TestCheckUserName, TestIncorrectUserName) {
	std::string username;
	ASSERT_THROW(
	   DataSyntax::CheckUserNameForSyntaxError("@Artemdjdj!", error_message, username),
	   ExceptionUserName
   );
}

TEST(TestCheckUserName, TestIncorrectLengthUserName) {
	std::string username;
	ASSERT_THROW(
	   DataSyntax::CheckUserNameForSyntaxError("@Artemdjdjlglsjldkgjskldjglskljgsfsdf", error_message, username),
	   ExceptionUserName
   );
}

TEST(TestCheckName, TestCorrectName) {
	std::string name;
	DataSyntax::CheckNameOrSurnameForSyntaxError("Artemdjdj", error_message, name);
	ASSERT_EQ(name, "Artemdjdj");
}

TEST(TestCheckName, TestCorrectNameWithHyphen) {
	std::string name;
	DataSyntax::CheckNameOrSurnameForSyntaxError("Artemdjdj-legend", error_message, name);
	ASSERT_EQ(name, "Artemdjdj-legend");
}

TEST(TestCheckName, TestIncorrectNameFirstSymbolHyphen) {
	std::string name;
	ASSERT_THROW(
	   DataSyntax::CheckNameOrSurnameForSyntaxError("-Artemdjdj", error_message, name),
	   ExceptionName
   );
}

TEST(TestCheckName, TestIncorrectNameLastSymbolHyphen) {
	std::string name;
	ASSERT_THROW(
	   DataSyntax::CheckNameOrSurnameForSyntaxError("Artemdjdj-", error_message, name),
	   ExceptionName
   );
}

TEST(TestCheckName, TestIncorrectLengthName) {
	std::string name;
	ASSERT_THROW(
	   DataSyntax::CheckNameOrSurnameForSyntaxError("Artemdjdjhfjkshfkhsdkfkjdhfkjhskfhkhfkjhjkfhjiksdhfjkhsdhjkhkhkjgjdfljgljdflgjldfkjgldjflgjdflgjlkdfjsgflk;fjglkjskljglkjslkgjdklf", error_message, name),
	   ExceptionName
   );
}

TEST(TestCheckEmail, TestCorrectEmailGmail) {
	std::string email;
	DataSyntax::CheckEmailForSyntaxError("vlad2007@gmail.com", error_message, email);
	ASSERT_EQ(email, "vlad2007@gmail.com");
}

TEST(TestCheckEmail, TestCorrectEmailYandex) {
	std::string email;
	DataSyntax::CheckEmailForSyntaxError("vlad2007@yandex.ru", error_message, email);
	ASSERT_EQ(email, "vlad2007@yandex.ru");
}

TEST(TestCheckEmail, TestIncorrectEmail) {
	std::string email;
	ASSERT_THROW(
	   DataSyntax::CheckEmailForSyntaxError("hello world", error_message, email),
	   ExceptionEmail
   );
}

TEST(TestCheckEmail, TestIncorrectEmailEmpty) {
	std::string email;
	ASSERT_THROW(
	   DataSyntax::CheckEmailForSyntaxError("", error_message, email),
	   ExceptionEmail
   );
}

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumberCodeOne) {
	std::string phone_number;
	DataSyntax::CheckPhoneNumberForSyntaxError("+375291111345", error_message, phone_number);
	ASSERT_EQ(phone_number, "+375291111345");
}

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumberCodeTwo) {
	std::string phone_number;
	DataSyntax::CheckPhoneNumberForSyntaxError("+375251111345", error_message, phone_number);
	ASSERT_EQ(phone_number, "+375251111345");
}

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumberCodeThree) {
	std::string phone_number;
	DataSyntax::CheckPhoneNumberForSyntaxError("+375331111345", error_message, phone_number);
	ASSERT_EQ(phone_number, "+375331111345");
}

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumberCodeFour) {
	std::string phone_number;
	DataSyntax::CheckPhoneNumberForSyntaxError("80291111345", error_message, phone_number);
	ASSERT_EQ(phone_number, "80291111345");
}

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumberCodeFive) {
	std::string phone_number;
	DataSyntax::CheckPhoneNumberForSyntaxError("80441111345", error_message, phone_number);
	ASSERT_EQ(phone_number, "80441111345");
}

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumberCodeSix) {
	std::string phone_number;
	DataSyntax::CheckPhoneNumberForSyntaxError("80251111345", error_message, phone_number);
	ASSERT_EQ(phone_number, "80251111345");
}

TEST(TestCheckPhoneNumber, TestIncorrectPhoneNumberLength) {
	std::string phone_number;
	ASSERT_THROW(
	   DataSyntax::CheckPhoneNumberForSyntaxError("+3752911113456", error_message, phone_number),
	   ExceptionPhoneNumber
   );
}

TEST(TestCheckPhoneNumber, TestIncorrectPhoneNumberCode) {
	std::string phone_number;
	ASSERT_THROW(
	   DataSyntax::CheckPhoneNumberForSyntaxError("+3752711113456", error_message, phone_number),
	   ExceptionPhoneNumber
   );
}

TEST(TestCheckPhoneNumber, TestIncorrectPhoneNumber) {
	std::string phone_number;
	ASSERT_THROW(
	   DataSyntax::CheckPhoneNumberForSyntaxError("3752911113456", error_message, phone_number),
	   ExceptionPhoneNumber
   );
}

TEST(TestCheckPassword, TestCorrectPassword) {
	std::string password;
	DataSyntax::CheckPasswordForSyntaxError("hffw5443hs", error_message, password);
	ASSERT_EQ(password, "hffw5443hs");
}

TEST(TestCheckPassword, TestInorrectPasswordShortLength) {
	std::string password;
	ASSERT_THROW(
	   DataSyntax::CheckPasswordForSyntaxError("hf4gd", error_message, password),
	   ExceptionPassword
   );
}

TEST(TestCheckPassword, TestInorrectPasswordLongLength) {
	std::string password;
	ASSERT_THROW(
	   DataSyntax::CheckPasswordForSyntaxError("gdfgljsljlgjldjlgjldfjogi435034503485348590gkjdfhglkdfsj89wutonoy834", error_message, password),
	   ExceptionPassword
   );
}