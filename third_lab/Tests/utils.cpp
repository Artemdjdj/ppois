#include "utils.h"
#include <string>
#include <gtest/gtest.h>

TEST(TestCheckPhoneNumber, TestCorrectPhoneNumber) {
	std::string error_message;
	ASSERT_TRUE(UserDataSyntax::CheckPhoneNumberForSyntaxError("+375291111345", error_message));
}

TEST(TestCheckPhoneNumber, TestIncorrectPhoneNumber) {
	std::string error_message;
	ASSERT_FALSE(UserDataSyntax::CheckPhoneNumberForSyntaxError("+3752911113456", error_message));
}

