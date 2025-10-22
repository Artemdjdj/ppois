#include "chat.h"
#include <filesystem>
#include <iostream>
#include <time.h>
#include "exceptions.h"
#include "../Utils/project_utils.h"

Message::Message() = default;

Message::Message(const std::string &message, const std::shared_ptr<User> &user) : author_(user) {
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

std::string Message::GetMessageDefault() const {
    return message_.first + " " + message_.second;
}

std::string Message::GetMessageDefaultText() const {
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

void BaseChat::RefactorMessage(const std::string &message, int number_of_message,
                               const std::shared_ptr<User> &sender_user) {
    ChangeMessage(number_of_message, sender_user, false, message);
}

void BaseChat::DeleteMessage(int number_of_message, const std::shared_ptr<User> &sender_user) {
    ChangeMessage(number_of_message, sender_user, true);
}

void BaseChat::CopyMessage(int number_of_message, std::string &copy_message) const {
    if (number_of_message < 0 and number_of_message > this->messages_.size()) {
        throw ExceptionIncorrectNumber("Incorrect number of messages");
    }
    copy_message = this->messages_[number_of_message]->GetMessageDefaultText();
}

void BaseChat::DeleteAllMessages() {
    this->messages_.clear();
}

int BaseChat::CountMessages() const {
    return this->messages_.size();
}

std::vector<std::shared_ptr<Message>> BaseChat::GetAllMessages() const {
    return this->messages_;
}

// void BaseChat::ViewHistory() const {
// 	if (this->messages_.size() == 0) {
// 		throw ExceptionNothingToPrint("There is no view history");
// 	}
// 	for (auto &message: this->messages_) {
// 		std::cout << message->GetMessageDefault() << std::endl;
// 	}
// }

Chat::Chat(std::shared_ptr<User> first_user, std::shared_ptr<User> second_user, const std::string& name)
    : name_(name),
      users_(std::make_pair(first_user, second_user)) {
}

std::shared_ptr<User> Chat::GetFirstMember() const {
    return this->users_.first.lock();
}

std::shared_ptr<User> Chat::GetSecondMember() const {
    return this->users_.second.lock();
}

std::vector<std::string> Chat::ListMembers() {
    std::vector<std::string> members;
    members.push_back(users_.first.lock()->GetUsername());
    members.push_back(users_.second.lock()->GetUsername());
    return members;
}

