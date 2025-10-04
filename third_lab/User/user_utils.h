#ifndef USER_UTILS_H
#define USER_UTILS_H
#include <regex>
#include <string>

class UserDataSyntax {
public:
	static void CheckUserNameForSyntaxError(const std::string &username, const std::string &error_message, std::string& result);

	static void CheckNameOrSurnameForSyntaxError(const std::string &name, const std::string &error_message, std::string& result);

	static void CheckEmailForSyntaxError(const std::string &email, const std::string &error_message, std::string& result);

	static void CheckPhoneNumberForSyntaxError(const std::string &phone_number, const std::string &error_message, std::string& result);

	static void CheckPasswordForSyntaxError(const std::string &password, const std::string &error_message, std::string& result);

};
#endif //UTILS_H
