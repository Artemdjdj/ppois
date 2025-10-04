#include "user_utils.h"
#include <regex>
#include "../Exceptions/exceptions.h"

void UserDataSyntax::CheckUserNameForSyntaxError(const std::string &username, const std::string &error_message, std::string& result) {
	const std::regex rx(R"(^@[a-zA-Z0-9\_\-]{3,17}$)");
	if (!std::regex_match(username, rx)) {
		throw (ExceptionUserName(error_message.c_str()));
	}
	result = username;
}

void UserDataSyntax::CheckNameOrSurnameForSyntaxError(const std::string &name, const std::string &error_message, std::string& result) {
	const std::regex rx(R"(^[a-zA-Z]{1,}[a-zA-Z\-]{3,50}\w{1,}$)");
	if (!std::regex_match(name, rx)) {
		throw (ExceptionName(error_message.c_str()));
	}
	result = name;
}

void UserDataSyntax::CheckEmailForSyntaxError(const std::string &email, const std::string &error_message, std::string& result) {
	const std::regex rx(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
	if (!std::regex_match(email, rx)) {
		throw (ExceptionEmail(error_message.c_str()));
	}
	result = email;
}

void UserDataSyntax::CheckPhoneNumberForSyntaxError(const std::string &phone_number, const std::string &error_message, std::string& result) {
	const std::regex rx(R"(\+375(?:29|25|33)\d{7}|80(?:29|44|25)\d{7})");
	if (!std::regex_match(phone_number, rx)) {
		throw (ExceptionPhoneNumber(error_message.c_str()));
	}
	result = phone_number;
}

void UserDataSyntax::CheckPasswordForSyntaxError(const std::string &password, const std::string &error_message, std::string& result) {
	const std::regex rx(R"(^[a-zA-Z0-9.-@]{8,25}$)");
	if (!std::regex_match(password, rx)) {
		throw (ExceptionPassword(error_message.c_str()));
	}
	result = password;
}
