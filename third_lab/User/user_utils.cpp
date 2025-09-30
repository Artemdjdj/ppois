#include "user_utils.h"
#include <regex>

bool UserDataSyntax::CheckUserNameForSyntaxError(const std::string &username, std::string &error_message) {
	const std::regex rx(R"(^@[a-zA-Z0-9\_\-]{3,17}$)");
	return CheckRegex(rx, username, error_message,
					"Your username is not correct the length should be between 3 and 17 and starts with @");
}

bool UserDataSyntax::CheckNameOrSurnameForSyntaxError(const std::string &name, std::string &error_message) {
	const std::regex rx(R"(^[a-zA-Z]{1,}[a-zA-Z\-]{3,50}\w{1,}$)");
	return CheckRegex(rx, name, error_message,
					"Your name or surname is not correct the length should be between 3 and 25");
}

bool UserDataSyntax::CheckEmailForSyntaxError(const std::string &email, std::string &error_message) {
	const std::regex rx(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
	return CheckRegex(rx, email, error_message, "Your E-mail address is not valid");
}

bool UserDataSyntax::CheckPhoneNumberForSyntaxError(const std::string &phone_number, std::string &error_message) {
	const std::regex rx(R"(\+375(?:29|25|33)\d{7}|80(?:29|44|25)\d{7})");
	return CheckRegex(rx, phone_number, error_message, "Your phone number must have a valid number");
}

bool UserDataSyntax::CheckPasswordForSyntaxError(const std::string &password, std::string &error_message) {
	const std::regex rx(R"(^[a-zA-Z0-9.-@]{8,25}$)");
	return CheckRegex(rx, password, error_message,
					"Your password is not valid the length should be between 8 and 25! Don't use special symbols!");
}

bool UserDataSyntax::CheckRegex(const std::regex &regex, const std::string &check_string, std::string &error,
								const std::string &error_message) {
	const bool result = std::regex_match(check_string, regex);
	if (!result) {
		error = error_message;
	}
	return result;
}
