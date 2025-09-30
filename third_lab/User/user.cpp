#include "user.h"
#include <string>
#include "user_utils.h"
#include "../Utils/project_utils.h"
#include "exceptions.h"
#include "../Utils/project_utils.h"

User::User(const std::string &username, const std::string &password) {
	SetUserName(username);
	SetName(password);
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
		if (!UserDataSyntax::CheckUserNameForSyntaxError(username, error_message)) {
			throw ExceptionUserName(error_message.c_str());
		}
		this->username_ = username;
	} catch (const ExceptionUserName &e) {
		LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		LogFile(e.what(), main_log_file);
	}
}

void User::SetName(const std::string &name) {
	std::string error_message;
	try {
		if (!UserDataSyntax::CheckNameOrSurnameForSyntaxError(name, error_message)) {
			throw ExceptionName(error_message.c_str());
		}
		this->name_ = name;
	} catch (const ExceptionName &e) {
		LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		LogFile(e.what(), main_log_file);
	}
}

void User::SetSurname(const std::string &surname) {
	std::string error_message;
	try {
		if (!UserDataSyntax::CheckNameOrSurnameForSyntaxError(surname, error_message)) {
			throw ExceptionSurName(error_message.c_str());
		}
		this->surname_ = surname;
	} catch (const ExceptionSurName &e) {
		LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		LogFile(e.what(), main_log_file);
	}
}

void User::SetEmail(const std::string &email) {
	std::string error_message;
	try {
		if (!UserDataSyntax::CheckEmailForSyntaxError(email, error_message)) {
			throw ExceptionEmail(error_message.c_str());
		}
		this->email_ = email;
	} catch (const ExceptionEmail &e) {
		LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		LogFile(e.what(), main_log_file);
	}
}

void User::SetPhoneNumber(const std::string &phone_number) {
	std::string error_message;
	try {
		if (!UserDataSyntax::CheckPhoneNumberForSyntaxError(phone_number, error_message)) {
			throw ExceptionPhoneNumber(error_message.c_str());
		}
		this->phone_number_ = phone_number;
	} catch (const ExceptionPhoneNumber &e) {
		LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		LogFile(e.what(), main_log_file);
	}
}

void User::SetPassword(const std::string &password) {
	std::string error_message;
	try {
		if (!UserDataSyntax::CheckPasswordForSyntaxError(password, error_message)) {
			throw ExceptionPassword(error_message.c_str());
		}
		this->password_ = password;
	} catch (const ExceptionPassword &e) {
		LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		LogFile(e.what(), main_log_file);
	}
}

std::string User::GetUserName() {
	return this->username_;
}

std::string User::GetName() {
	return this->name_;
}

std::string User::GetSurName() {
	return this->surname_;
}

std::string User::GetEmail() {
	return this->email_;
}

std::string User::GetPhoneNumber() {
	return this->phone_number_;
}
