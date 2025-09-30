#ifndef CHAT_H
#define CHAT_H
#include <string>
#include <utility>
#include <vector>
#include "../User/user.h"

class Message {
public:
	Message();

	Message(const std::string &message, const User &user);

	bool CreateMessage(const std::string &message, const User &user);

	bool RefactorMessage(const std::string &message);

	const User& GetUser();

	std::string GetMessage() const;

	static std::string GetRealTime();

private:
	std::pair<std::string, std::string> message_;
	bool is_refactor_{false};
	User author_;
};

class BaseChat {
public:
	virtual ~BaseChat() = default;

	bool WriteMessage(const std::string &message, const User &sender_user);

	void ChangeMessage(const std::string &message, int number_of_message, const User &sender_user, bool is_delete);

	void RefactorMessage(const std::string &message, int number_of_message, const User &sender_user);

	void DeleteMessage(const std::string &message, int number_of_message, const User &sender_user);

	void ViewHistory() const;

	virtual std::string GetName() =0;

	virtual std::vector<std::string> ListMembers() =0;

private:
	std::vector<Message> messages_;
};

class Chat final : public BaseChat {
public:
	Chat(const User &active_user, const User &second_user);

	std::string GetName() override;

	std::vector<std::string> ListMembers() override;

private:
	User active_user_;
	std::pair<User, User> users_;
};

class Group final : public BaseChat {
public:
	explicit Group(const User &main_user);

	void SetName(const std::string& name);

	std::string GetName() override;

	std::vector<std::string> ListMembers() override;

	


private:
	User main_user_;
	std::string name_;
	std::vector<User> users_;
};




#endif //CHAT_H
