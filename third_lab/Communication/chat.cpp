#include "chat.h"
#include <filesystem>
#include <iostream>
#include <time.h>
#include "exceptions.h"
#include "../Utils/project_utils.h"

Message::Message() = default;

Message::Message(const std::string &message, User *user): author_(user) {
	CreateMessage(message, user);
}

bool Message::CreateMessage(const std::string &message, User *user) {
	try {
		if (message.empty()) {
			throw ExceptionIncorrectMessage(message.c_str());
		}
		std::string real_time = GetRealTime();
		this->author_ = user;
		this->message_ = std::make_pair(message, real_time);
		return true;
	} catch (const ExceptionIncorrectMessage &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
		return false;
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
		return false;
	}
}

bool Message::RefactorMessage(const std::string &message) {
	if (CreateMessage(message, this->author_)) {
		this->is_refactor_ = true;
		return true;
	}
	return false;
}

User* Message::GetAuthor() const {
	return this->author_;
}

std::string Message::GetMessage() const {
	return message_.first + " " + message_.second;
}

std::string Message::GetMessageText() const {
	return message_.first;
}

std::string Message::GetRealTime() {
	const time_t realtime = time(nullptr);
	const struct tm tm = *localtime(&realtime);
	return std::to_string(tm.tm_hour) + ":" + std::to_string(tm.tm_min);
}

bool BaseChat::WriteMessage(const std::string &message, User *sender_user) {
	Message base_chat_message;
	if (bool is_correct_message = base_chat_message.CreateMessage(message, sender_user)) {
		this->messages_.push_back(base_chat_message);
		return true;
	}
	return false;
}

void BaseChat::ChangeMessage(int number_of_message, const User *sender_user,
							bool is_delete, const std::string &message = "") {
	try {
		if (number_of_message < 0 or number_of_message > this->messages_.size()) {
			throw ExceptionIncorrectNumberOfMessage("Incorrect number of messages");
		}
		if (sender_user != this->messages_[number_of_message].GetAuthor()) {
			throw ExceptionAccess("Such user didn't create this message and he can't to refactor it!!!!!");
		}
		if (!is_delete) {
			messages_[number_of_message].RefactorMessage(message);
		} else {
			messages_.erase(messages_.begin() + number_of_message);
		}
	} catch (const ExceptionIncorrectNumberOfMessage &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const ExceptionAccess &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const ExceptionIncorrectMessage &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
};

void BaseChat::RefactorMessage(const std::string &message, int number_of_message, const User *sender_user) {
	ChangeMessage(number_of_message, sender_user, false, message);
}

void BaseChat::DeleteMessage(int number_of_message, const User *sender_user) {
	ChangeMessage(number_of_message, sender_user, true);
}

void BaseChat::CopyMessage(int number_of_message, std::string &copy_message) const {
	try {
		if (number_of_message < 0 and number_of_message > this->messages_.size()) {
			throw ExceptionIncorrectNumberOfMessage("Incorrect number of messages");
		}
		copy_message = this->messages_[number_of_message].GetMessageText();
	} catch (const ExceptionIncorrectNumberOfMessage &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

void BaseChat::DeleteAllMessages() {
	this->messages_.clear();
}

int BaseChat::CountMessages() const {
	return this->messages_.size();
}

void BaseChat::ViewHistory() const {
	try {
		if (this->messages_.size() == 0) {
			throw ExceptionNothingToPrint("There is no view history");
		}
		for (auto &message: this->messages_) {
			std::cout << message.GetMessage() << std::endl;
		}
	} catch (const ExceptionNothingToPrint &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

Chat::Chat(User *active_user, User *second_user)
	: active_user_(active_user),
	users_(std::make_pair(active_user, second_user)) {
}

std::string Chat::GetName() {
	return (active_user_ == users_.first) ? users_.second->GetName() : users_.first->GetName();
}

std::vector<std::string> Chat::ListMembers() {
	std::vector<std::string> members;
	members.push_back(users_.first->GetUserName());
	members.push_back(users_.second->GetUserName());
	return members;
}

Group::Group(User *main_user): main_user_(main_user) {
	this->users_.push_back(main_user_);
}

void Group::SetName(const std::string &name) {
	try {
		this->name_ = name;
	} catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

std::string Group::GetName() {
	return this->name_;
}

std::vector<std::string> Group::ListMembers() {
	std::vector<std::string> members;
	for (const auto &user: this->users_) {
		members.push_back(user->GetUserName());
	}
	return members;
}

int Group::CheckUserExist(const std::string &username) const {
	for (int i = 0; i < this->users_.size(); i++) {
		if (username == this->users_[i]->GetUserName()) {
			return i;
		}
	}
	return -1;
}

void Group::AddUser(User *new_user, const User *main_user) {
	try {
		if (CheckUserExist(new_user->GetUserName()) != -1) {
			DefaultProjectSettings::LogFile("Such user already exist", main_log_file);
			return;
		}
		if (main_user != this->main_user_) {
			throw ExceptionAccess("You not main user!!!");
		}
		this->users_.push_back(new_user);
	} catch (const ExceptionAccess &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

void Group::DeleteUser(const std::string &delete_username, const User *main_user) {
	const int del_index = CheckUserExist(delete_username);
	if (del_index == -1  or del_index == 0) {
		DefaultProjectSettings::LogFile("Such user is not in Group", main_log_file);
		return;
	}
	if (this->main_user_!= main_user) {
		DefaultProjectSettings::LogFile("You aren't main user", main_log_file);
		return;
	}
	this->users_.erase(users_.begin() + del_index);
}
