#include "profile.h"

#include "../Utils/project_utils.h"

Profile::Profile() = default;

Profile::Profile(const User &user, const std::string &location, const std::string &biography) {
	this->user_ = user;
	SetLocation(location);
	SetBiography(biography);
}

void Profile::SetUserUserName(const std::string &username) {
	this->user_.SetUserName(username);
}

void Profile::SetUserName(const std::string &name) {
	this->user_.SetName(name);
}

void Profile::SetUserSurname(const std::string &surname) {
	this->user_.SetSurname(surname);
}

void Profile::SetUserEmail(const std::string &email) {
	this->user_.SetEmail(email);
}

void Profile::SetUserPhoneNumber(const std::string &phone_number) {
	this->user_.SetPhoneNumber(phone_number);
}

void Profile::SetUserPassword(const std::string &password) {
	this->user_.SetPassword(password);
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

void Profile::SetAge(int age) {
	this->age_ = age;
}

std::string Profile::GetUserUserName() const {
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

void Profile::CreateNewChat(User *user2) {
	const auto chat = Chat(&this->user_, user2);
	std::string id;
	this->generator_id_for_chats_.GenerateNewId(id);
	this->chats_[id] = chat;
}

void Profile::RemoveChat(const std::string &chat_id) {
	if (const auto it = chats_.erase(chat_id); it == 0) {
		DefaultProjectSettings::LogFile("This chat is not in exist, you can't delete it", main_log_file);
	}
}

void Profile::CreateNewGroup(const std::string &name_of_group) {
	const auto group = Group(&this->user_);
	std::string id;
	this->generator_id_for_groups_.GenerateNewId(id);
	this->groups_[id] = group;
}

void Profile::RemoveGroup(const std::string &group_id) {
	if (const auto it = groups_.erase(group_id); it == 0) {
		DefaultProjectSettings::LogFile("This group is not exist, you can't delete it", main_log_file);
	}
}
