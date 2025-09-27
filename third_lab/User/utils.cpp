#include "utils.h"
#include <regex>
bool UserDataSyntax::CheckUserNameForSyntaxError(const std::string &username, std::string &error_message) {
	if (username.empty() || username.size()<5){
		error_message = "Username must be an empty string";
		return false;
	}
	error_message = (username[0]=='@')?"":"Username must starts with symbol @";
	return username[0] == '@';
}

bool UserDataSyntax::CheckNameOrSurnameForSyntaxError(const std::string &name, std::string &error_message) {
	if (name.empty() || name.size()<3 || name.size()>15) {
		error_message = "Your name or surname must has length between 4 and 14 sybmols";
		return false;
	}
	return true;
}

bool UserDataSyntax::CheckPhoneNumberForSyntaxError(const std::string &phone_number, std::string &error_message) {
	const std::regex rx(R"(\+375(?:29|25|33)\d{7}|80(?:29|44|25)\d{7})");
	const bool result = regex_match(phone_number, rx);
	if (!result) {
		error_message = "Your phone number must have a valid number";
	}
	return result;
}