//
// Created by Redmi on 20.10.2025.
//

#ifndef THIRD_LAB_APP_H
#define THIRD_LAB_APP_H
#include "../UserManager/user_manager.h"
#include "../DataManager/data_manager.h"

class App {
public:
    void RegistrateUser(const std::string &username, const std::string &password,
                        const std::string &name = "");

    void Login(const std::string &username, const std::string &password);

    void Logout();

    void DeleteAccount();

    void CreateNewChat(const std::string &second_user);

    void SendMessageToChat(const std::string &second_user,
                           const std::shared_ptr<Message> &message);

    std::string GetChatName(const std::string &user);

    void DeleteMessageFromChat(const std::string &second_user, int number_of_message);

    void RefactorMessageInChat(const std::string &second_user, int number_of_message,
                               const std::shared_ptr<Message> &new_message);

    std::vector<std::pair<int, std::pair<std::string, std::string> > > ViewAllHistoryOfChat(
        const std::string &second_user);

    std::vector<std::shared_ptr<Chat> > GetAllChats();

    void DeleteChat(const std::string &user);

    int GetCountOfUsers() const;

    std::string GetAuthor() const;

    Profile *GetProfile() const;

    std::shared_ptr<Chat> GetChat(const std::string &user);

    std::shared_ptr<User> GetCurrentUser();

    std::shared_ptr<User> GetUser(const std::string &username);

    void SetLocation(const std::string &location) const;

    void SetBiography(const std::string &biography) const;

    void SetGender(const bool is_man) const;

    void SetAge(int age) const;

    std::string GetLocation() const;

    std::string GetBiography() const;

    bool GetGender() const;

    int GetAge() const;

    void AddUserToBlackList(const std::string &user);

    void DeleteUserFromBlackList(const std::string &user) const;

    void DeleteAllFromBlackList() const;

    std::vector<std::string> GetBlockedUsersNamesFromBlackList();

private:
    std::shared_ptr<User> user_ = nullptr;
    UserManager user_manager_;
    DataManager data_manager_;
};
#endif //THIRD_LAB_APP_H
