#ifndef USER_H
#define USER_H
#include <string>
#include <memory>
#include "role.h"
#include "../WorkingWithUser/working_with_password.h"
class Profile;

class User {
public:

	User() = default;

	User(const std::string &username, const std::string &password, const std::string & name="");

	User(const User &other);

	bool operator==(const User &other) const;

	bool operator!=(const User &other) const;

	void SetUserName(const std::string &username);

	void SetName(const std::string &name);

	void SetSurname(const std::string &surname);

	void SetEmail(const std::string &email);

	void SetPhoneNumber(const std::string &phone_number);

	void SetPassword(const std::string &password);

	void SetRole(const Role &role);

	void CreateProfile();

	std::string GetUsername() const;

	std::string GetName() const;

	std::string GetSurName() const;

	std::string GetEmail() const;

	std::string GetPhoneNumber() const;

	Profile* GetProfile() const;

	Role GetRole() const;

	Hash GetPassword() const;


private:
	std::string username_;
	std::string name_;
	std::string surname_;
	std::string email_;
	std::string phone_number_;
	Hash password_;
	Role role_;
	std::unique_ptr<Profile> profile_;
};

class Profile {
public:

	explicit Profile(User &user, const std::string &location="", const std::string &biography="");

	void SetLocation(const std::string &location);

	void SetBiography(const std::string &biography);

	void SetGender(const std::string &gender);

	void SetAge(int age);

	std::string GetGender() const;

	std::string GetLocation() const;

	std::string GetBiography() const;

	int GetAge() const;

private:
	User &user_;
	std::string location_;
	std::string biography_;
	std::string gender_;
	std::string birthday_;
	std::string marital_status_;
	int age_;
};


#endif //USER_H
