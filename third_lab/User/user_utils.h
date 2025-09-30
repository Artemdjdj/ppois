#ifndef USER_UTILS_H
#define USER_UTILS_H
#include <regex>
#include <string>

class UserDataSyntax {
public:
	static bool CheckUserNameForSyntaxError(const std::string &username, std::string &error_message);

	static bool CheckNameOrSurnameForSyntaxError(const std::string &name, std::string &error_message);

	static bool CheckEmailForSyntaxError(const std::string &email, std::string &error_message);

	static bool CheckPhoneNumberForSyntaxError(const std::string &phone_number, std::string &error_message);

	static bool CheckPasswordForSyntaxError(const std::string &password, std::string &error_message);

private:
	static bool CheckRegex(const std::regex &regex, const std::string &check_string, std::string &error,
							const std::string &error_message);
};
#endif //UTILS_H
