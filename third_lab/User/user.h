#ifndef USER_H
#define USER_H
#include <string>

class User {
public:
	User(const std::string &username, const std::string &password);

	User(const User &other);

	User() = default;

	bool operator==(const User &other) const;

	bool operator!=(const User &other) const;

	void SetUserName(const std::string &username);

	void SetName(const std::string &name);

	void SetSurname(const std::string &surname);

	void SetEmail(const std::string &email);

	void SetPhoneNumber(const std::string &phone_number);

	void SetPassword(const std::string &password);

	std::string GetUserName() const;

	std::string GetName() const;

	std::string GetSurName() const;

	std::string GetEmail() const;

	std::string GetPhoneNumber() const;

private:
	std::string username_;
	std::string name_;
	std::string surname_;
	std::string email_;
	std::string phone_number_;
	std::string password_;
};


#endif //USER_H
