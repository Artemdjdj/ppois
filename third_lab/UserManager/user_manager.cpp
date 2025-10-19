#include "user_manager.h"
#include "../Utils/project_utils.h"
#include <utility>

std::shared_ptr<User> UserManager::CreateUser(const std::string &username, const std::string &password,
                                              const std::string &name) {
    if (IsUserExist(username)) {
        return nullptr;
    }
    auto new_user = std::make_shared<User>(username, password, name);
    this->users_[username] = new_user;
    return new_user;
}

std::vector<std::shared_ptr<User> > UserManager::GetAllUsers() const {
    std::vector<std::shared_ptr<User> > result_list;
    for (const auto &pair: this->users_) {
        result_list.push_back(pair.second);
    }
    return result_list;
}

std::shared_ptr<User> UserManager::GetUser(const std::string &username) {
    return IsUserExist(username) ? this->users_[username] : nullptr;
}

std::shared_ptr<User> UserManager::AuthenticateUser(const std::string& username, const std::string&password) {
    if (!IsUserExist(username)) {
        throw std::invalid_argument("Such user is not exist");
    }
    auto user = this->users_[username];
    if (HashPassword::IsPasswordMatch(password, user->GetPassword())) {
        return user;
    }
    return nullptr;
}

void UserManager::DeleteUser(const std::shared_ptr<User> &user) {
    if (!user) {
        throw std::invalid_argument("Empty author");
    }
    if (!IsUserExist(user->GetUsername())) {
        throw std::logic_error("Nothing to delete");
    }
    this->users_.erase(user->GetUsername());
}

bool UserManager::IsUserExist(const std::string &username) const {
    return this->users_.contains(username);
}
