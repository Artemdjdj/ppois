#ifndef CHAT_H
#define CHAT_H
#include <string>
#include <utility>
#include <vector>
#include "../User/user.h"


class Message {
public:
	Message();

	Message(const std::string &message, User *user);

	void CreateMessage(const std::string &message, User *user);

	void RefactorMessage(const std::string &message);

	User *GetAuthor() const;

	std::string GetMessage() const;

	std::string GetMessageText() const;

private:
	std::pair<std::string, std::string> message_;
	bool is_refactor_{false};
	User *author_{};
};

class BaseChat {
public:
	BaseChat() = default;

	virtual ~BaseChat() = default;

	BaseChat(const BaseChat &) = delete;

	 void WriteMessage(Message* message);

	void RefactorMessage(const std::string &message, int number_of_message, const User *sender_user);

	void DeleteMessage(int number_of_message, const User *sender_user);

	void CopyMessage(int number_of_message, std::string &copy_message) const;

	void DeleteAllMessages();

	int CountMessages() const;

	void ViewHistory() const;

	virtual std::string GetName() =0;

	virtual std::vector<std::string> ListMembers() =0;

private:
	void ChangeMessage(int number_of_message, const User *sender_user, bool is_delete, const std::string &message);

	std::vector<Message*> messages_;
};

class Chat final : public BaseChat {
public:
	Chat() = default;

	Chat(User *active_user, User *second_user);

	std::string GetName() override;

	std::vector<std::string> ListMembers() override;

private:
	User *active_user_;
	std::pair<User *, User *> users_;
};

class Group final : public BaseChat {
public:
	Group() = default;

	explicit Group(User *main_user);

	void SetName(const std::string &name);

	std::string GetName() override;

	std::vector<std::string> ListMembers() override;

	void AddUser(User *new_user, const User *main_user);

	void DeleteUser(const std::string &delete_username, const User *main_user);

private:
	User *main_user_;
	std::string name_;
	std::vector<User *> users_;

	int CheckUserExist(const std::string &username) const;
};




#endif //CHAT_H
