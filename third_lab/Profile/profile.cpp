#include "profile.h"

Profile::Profile() = default;

Profile::Profile(const User& user, const std::string& location, const std::string& biography) {
	this->user_ = user;
	SetLocation(location);
	SetBiography(biography);
}

void Profile::SetUserUserName(const std::string& username) {
	this->user_.SetUserName(username);
}

void Profile::SetUserName(const std::string& name) {
	this->user_.SetName(name);
}

void Profile::SetUserSurname(const std::string& surname) {
	this->user_.SetSurname(surname);
}

void Profile::SetUserEmail(const std::string& email) {
	this->user_.SetEmail(email);
}

void Profile::SetUserPhoneNumber(const std::string& phone_number) {
	this->user_.SetPhoneNumber(phone_number);
}

void Profile::SetUserPassword(const std::string& password) {
	this->user_.SetPassword(password);
}

void Profile::SetLocation(const std::string& location) {
	this->location_ = location;
}

void Profile::SetBiography(const std::string& biography) {
	this->biography_ = biography;
}

void Profile::SetGender(const std::string& gender) {
	this->gender_ = gender;
}

void Profile::SetAge(int age) {
	this->age_ = age;
}

std::string Profile::GetUserUserName() const{
	return this->user_.GetUserName();
}

std::string Profile::GetUserName() const {
	return this->user_.GetName();
}

std::string Profile::GetUserSurname() const {
	return this->user_.GetSurName();
}

std::string Profile::GetUserEmail() const {
	return this->user_.GetEmail();
}

std::string Profile::GetUserPhoneNumber() const {
	return this->user_.GetPhoneNumber();
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