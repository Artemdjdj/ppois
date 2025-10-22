#ifndef CHAT_H
#define CHAT_H
#include <string>
#include <utility>
#include <vector>
#include "../User/user.h"


class Message {
public:
    Message();

    Message(const std::string &message, const std::shared_ptr<User> &user);

    void CreateMessage(const std::string &message, const std::shared_ptr<User> &user);

    void RefactorMessage(const std::string &message);

    std::shared_ptr<User> GetAuthor() const;

    std::string GetMessageDefault() const;

    std::string GetMessageDefaultText() const;

private:
    std::pair<std::string, std::string> message_;
    bool is_refactor_{false};
    std::weak_ptr<User> author_;
};

class BaseChat {
public:
    BaseChat() = default;

    virtual ~BaseChat() = default;

    BaseChat(const BaseChat &) = delete;

    void WriteMessage(const std::shared_ptr<Message> &message);

    void RefactorMessage(const std::string &message, int number_of_message, const std::shared_ptr<User> &user);

    void DeleteMessage(int number_of_message, const std::shared_ptr<User> &user);

    void CopyMessage(int number_of_message, std::string &copy_message) const;

    void DeleteAllMessages();

    int CountMessages() const;

    std::vector<std::shared_ptr<Message>> GetAllMessages() const;

    // void ViewHistory() const;

    virtual std::vector<std::string> ListMembers() =0;

protected:
    void ChangeMessage(int number_of_message, const std::shared_ptr<User> &sender_user, bool is_delete,
                       const std::string &message);

    std::vector<std::shared_ptr<Message> > messages_;
};

class Chat final : public BaseChat {
public:
    Chat() = default;

    Chat(std::shared_ptr<User> first_user, std::shared_ptr<User> second_user, const std::string &name = "");

    std::shared_ptr<User> GetFirstMember() const;

    std::shared_ptr<User> GetSecondMember() const;

    std::vector<std::string> ListMembers() override;


private:
    std::string name_;
    std::pair<std::weak_ptr<User>, std::weak_ptr<User> > users_;
};


#endif //CHAT_H
