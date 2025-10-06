#include "user.h"
#include <string>
#include "user_utils.h"
#include "../Utils/project_utils.h"
#include "exceptions.h"
#include "../Utils/project_utils.h"

User::User(const std::string &username, const std::string &password) {
	SetUserName(username);
	SetPassword(password);
}

User::User(const User &other) {
	this->username_ = other.username_;
	this->name_ = other.name_;
	this->surname_ = other.surname_;
	this->email_ = other.email_;
	this->phone_number_ = other.phone_number_;
	this->password_ = other.password_;
}

bool User::operator==(const User &other) const {
	return username_ == other.username_ &&
			name_ == other.name_ &&
			surname_ == other.surname_ &&
			email_ == other.email_ &&
			phone_number_ == other.phone_number_ &&
			password_ == other.password_;
}

bool User::operator!=(const User &other) const {
	return !(*this == other);
}

void User::SetUserName(const std::string &username) {
	std::string error_message;
	try {
		DataSyntax::CheckUserNameForSyntaxError(username, "Your username is not correct the length should be between 3 and 17 and starts with @", this->username_);
	} catch (const ExceptionUserName &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

void User::SetName(const std::string &name) {
	std::string error_message;
	try {
		DataSyntax::CheckNameOrSurnameForSyntaxError(name, "Your name or surname is not correct the length should be between 3 and 25", this->name_);
	} catch (const ExceptionName &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

void User::SetSurname(const std::string &surname) {
	std::string error_message;
	try {
		DataSyntax::CheckNameOrSurnameForSyntaxError(surname, "Your name or surname is not correct the length should be between 3 and 25", this->surname_);
	} catch (const ExceptionSurName &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

void User::SetEmail(const std::string &email) {
	std::string error_message;
	try {
		DataSyntax::CheckEmailForSyntaxError(email, "Your E-mail address is not valid", this->email_);
	} catch (const ExceptionEmail &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

void User::SetPhoneNumber(const std::string &phone_number) {
	std::string error_message;
	try {
		DataSyntax::CheckPhoneNumberForSyntaxError(phone_number, "Your phone number is not valid", this->phone_number_);
	} catch (const ExceptionPhoneNumber &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

void User::SetPassword(const std::string &password) {
	std::string error_message;
	try {
		DataSyntax::CheckPasswordForSyntaxError(password, "Your password is not valid", this->password_);
	} catch (const ExceptionPassword &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

std::string User::GetUserName() const{
	return this->username_;
}

std::string User::GetName() const{
	return this->name_;
}

std::string User::GetSurName() const{
	return this->surname_;
}

std::string User::GetEmail() const{
	return this->email_;
}

std::string User::GetPhoneNumber() const{
	return this->phone_number_;
}
