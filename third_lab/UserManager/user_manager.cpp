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

std::vector<std::shared_ptr<User> > UserManager::GetAllUsers(const std::string &username) const {
    std::vector<std::shared_ptr<User> > result_list;
    for (const auto &pair: this->users_) {
        result_list.push_back(pair.second);
    }
    return result_list;
}

std::shared_ptr<User> UserManager::GetUser(const std::string &username) {
    return IsUserExist(username) ? this->users_[username] : nullptr;
}

void UserManager::DeleteUser(const std::shared_ptr<User> &user) {
    if (!user) {
        throw std::invalid_argument("Empty author");
    }
    if (!IsUserExist(user->GetUserName())) {
        throw std::logic_error("Nothing to delete");
    }
    this->users_.erase(user->GetUserName());
}

bool UserManager::IsUserExist(const std::string &username) const {
    return this->users_.contains(username);
}
