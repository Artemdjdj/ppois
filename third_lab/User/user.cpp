#include "user.h"
#include <string>
#include "user_utils.h"
#include "../Utils/project_utils.h"
#include "exceptions.h"


User::User(const std::string &username, const std::string &password, const std::string& name):name_(name) {
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
	DataSyntax::CheckUserNameForSyntaxError(username, "Your username is not correct the length should be between 3 and 17 and starts with @", this->username_);
}

void User::SetName(const std::string &name) {
	std::string error_message;
	DataSyntax::CheckNameOrSurnameForSyntaxError(name, "Your name or surname is not correct the length should be between 3 and 25", this->name_);
}

void User::SetSurname(const std::string &surname) {
	std::string error_message;
	DataSyntax::CheckNameOrSurnameForSyntaxError(surname, "Your name or surname is not correct the length should be between 3 and 25", this->surname_);
}

void User::SetEmail(const std::string &email) {
	std::string error_message;
	DataSyntax::CheckEmailForSyntaxError(email, "Your E-mail address is not valid", this->email_);

}

void User::SetPhoneNumber(const std::string &phone_number) {
	std::string error_message;
	DataSyntax::CheckPhoneNumberForSyntaxError(phone_number, "Your phone number is not valid", this->phone_number_);
}

void User::SetPassword(const std::string &password) {
	std::string error_message;
	DataSyntax::CheckPasswordForSyntaxError(password, "Your password is not valid", this->password_);
}

void User::CreateProfile() {
	if (!this->profile_) {
		this->profile_ = std::make_unique<Profile>(*this);
	}
}

void User::SetRole(const Role &role) {
	this->role_ = role;
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

Role User::GetRole() const {
	return this->role_;
}

Profile* User::GetProfile() const {
	return this->profile_.get();
}

Profile::Profile(User &user, const std::string &location, const std::string &biography):user_(user) {
	SetLocation(location);
	SetBiography(biography);
}

void Profile::SetLocation(const std::string &location) {
	this->location_ = location;
}

void Profile::SetBiography(const std::string &biography) {
	this->biography_ = biography;
}

void Profile::SetGender(const std::string &gender) {
	this->gender_ = gender;
}

void Profile::SetAge(const int age) {
	this->age_ = age;
}

std::string Profile::GetGender() const {
	return this->gender_;
}

std::string Profile::GetLocation() const {
	return this->location_;
}

std::string Profile::GetBiography() const {
	return this->biography_;
}

int Profile::GetAge() const {
	return this->age_;
}

