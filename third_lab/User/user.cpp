#include "user.h"
#include <string>
#include "utils.h"
#include "../Exceptions/exceptions.h"

User::User(const std::string& username, const  std::string& password) {
	SetUserName(username);
	SetName(password);
}

void User::SetUserName(const std::string &username) {
	std::string error_message;
	if (!UserDataSyntax::CheckUserNameForSyntaxError(username, error_message)) {
		throw ExceptionUserName(error_message.c_str());
	}
	this->username_ = username;
}

void User::SetName(const std::string &name) {
	std::string error_message;
	if (!UserDataSyntax::CheckNameOrSurnameForSyntaxError(name, error_message)) {
		throw ExceptionName(error_message.c_str());
	}
	this->name_ = name;
}

void User::SetSurname(const std::string &surname) {
	std::string error_message;
	if (!UserDataSyntax::CheckNameOrSurnameForSyntaxError(surname, error_message)) {
		throw ExceptionSurName(error_message.c_str());
	}
	this->surname_ = surname;
}

void User::SetEmail(const std::string &email) {
	std::string error_message;
	if (!UserDataSyntax::CheckEmailForSyntaxError(email, error_message)) {
		throw ExceptionEmail(error_message.c_str());
	}
	this->email_ = email;
}

void User::SetPhoneNumber(const std::string &phone_number) {
	std::string error_message;
	if (!UserDataSyntax::CheckPhoneNumberForSyntaxError(phone_number, error_message)) {
		throw ExceptionPhoneNumber(error_message.c_str());
	}
	this->phone_number_ = phone_number;
}

void User::SetPassword(const std::string &password) {
	std::string error_message;
	if (!UserDataSyntax::CheckPasswordForSyntaxError(password, error_message)) {
		throw ExceptionPassword(error_message.c_str());
	}
	this->password_ = password;
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