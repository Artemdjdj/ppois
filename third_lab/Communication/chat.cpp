#include "chat.h"
#include <filesystem>
#include <iostream>
#include <time.h>
#include "exceptions.h"
#include "../Utils/project_utils.h"

Message::Message() = default;

Message::Message(const std::string &message, const std::shared_ptr<User> &user): author_(user) {
	CreateMessage(message, user);
}

void Message::CreateMessage(const std::string &message, const std::shared_ptr<User> &user) {
	if (message.empty()) {
		throw ExceptionIncorrectMessage(message.c_str());
	}
	std::string real_time = DefaultProjectSettings::GetRealTime();
	this->author_ = user;
	this->message_ = std::make_pair(message, real_time);
}

void Message::RefactorMessage(const std::string &message) {
	CreateMessage(message, this->author_.lock());
	this->is_refactor_ = true;
}

std::shared_ptr<User> Message::GetAuthor() const {
	return this->author_.lock();
}

std::string Message::GetMessage() const {
	return message_.first + " " + message_.second;
}

std::string Message::GetMessageText() const {
	return message_.first;
}

void BaseChat::WriteMessage(const std::shared_ptr<Message> &message) {
	this->messages_.push_back(message);
}

void BaseChat::ChangeMessage(int number_of_message, const std::shared_ptr<User> &sender_user,
							bool is_delete, const std::string &message = "") {
	if (number_of_message < 0 or number_of_message > this->messages_.size()) {
		throw ExceptionIncorrectNumber("Incorrect number of messages");
	}
	if (sender_user != this->messages_[number_of_message]->GetAuthor()) {
		throw ExceptionAccess("Such user didn't create this message and he can't to refactor it!!!!!");
	}
	if (!is_delete) {
		messages_[number_of_message]->RefactorMessage(message);
	} else {
		messages_.erase(messages_.begin() + number_of_message);
	}
};

void BaseChat::RefactorMessage(const std::string &message, int number_of_message, const std::shared_ptr<User> &sender_user) {
	ChangeMessage(number_of_message, sender_user, false, message);
}

void BaseChat::DeleteMessage(int number_of_message, const std::shared_ptr<User> &sender_user) {
	ChangeMessage(number_of_message, sender_user, true);
}

void BaseChat::CopyMessage(int number_of_message, std::string &copy_message) const {
	if (number_of_message < 0 and number_of_message > this->messages_.size()) {
		throw ExceptionIncorrectNumber("Incorrect number of messages");
	}
	copy_message = this->messages_[number_of_message]->GetMessageText();
}

void BaseChat::DeleteAllMessages() {
	this->messages_.clear();
}

int BaseChat::CountMessages() const {
	return this->messages_.size();
}

void BaseChat::ViewHistory() const {
	if (this->messages_.size() == 0) {
		throw ExceptionNothingToPrint("There is no view history");
	}
	for (auto &message: this->messages_) {
		std::cout << message->GetMessage() << std::endl;
	}
}

Chat::Chat(std::shared_ptr<User> active_user, std::shared_ptr<User> second_user)
	: active_user_(active_user),
	users_(std::make_pair(active_user, second_user)) {
}

std::string Chat::GetName() {
	return (active_user_.lock() == users_.first.lock()) ? users_.second.lock()->GetName() : users_.first.lock()->GetName();
}

std::vector<std::string> Chat::ListMembers() {
	std::vector<std::string> members;
	members.push_back(users_.first.lock()->GetUserName());
	members.push_back(users_.second.lock()->GetUserName());
	return members;
}

Group::Group(std::shared_ptr<User> main_user): main_user_(main_user) {
	this->users_.push_back(main_user_);
}

void Group::SetName(const std::string &name) {
	this->name_ = name;
}

std::string Group::GetName() {
	return this->name_;
}

std::vector<std::string> Group::ListMembers() {
	std::vector<std::string> members;
	for (const auto &user: this->users_) {
		members.push_back(user.lock()->GetUserName());
	}
	return members;
}

int Group::CheckUserExist(const std::string &username) const {
	for (int i = 0; i < this->users_.size(); i++) {
		if (username == this->users_[i].lock()->GetUserName()) {
			return i;
		}
	}
	return -1;
}

void Group::AddUser(const std::shared_ptr<User> &new_user, const std::shared_ptr<User> &main_user) {
	if (CheckUserExist(new_user->GetUserName()) != -1) {
		DefaultProjectSettings::LogFile("Such user already exist", main_log_file);
		return;
	}
	if (main_user != this->main_user_.lock()) {
		throw ExceptionAccess("You not main user!!!");
	}
	this->users_.push_back(new_user);
}

void Group::DeleteUser(const std::string &delete_username, const std::shared_ptr<User> &main_user) {
	const int del_index = CheckUserExist(delete_username);
	if (del_index == -1 or del_index == 0) {
		DefaultProjectSettings::LogFile("Such user is not in Group", main_log_file);
		return;
	}
	if (this->main_user_.lock() != main_user) {
		DefaultProjectSettings::LogFile("You aren't main user", main_log_file);
		return;
	}
	this->users_.erase(users_.begin() + del_index);
}