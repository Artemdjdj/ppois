#include "../SocialMedia/black_list.h"
#include "../Utils/project_utils.h"

void BlackList::AddUser(User *user) {
    DefaultWorkingWithVector::AddElementToVector(this->blocked_users_, user);
}

int BlackList::FindUserIndex(const User *user) const {
    int it = 0;
    for (auto &bad_user: this->blocked_users_) {
        if (user == bad_user) {
            return it;
        }
        it += 1;
    }
    return it;
}

void BlackList::DeleteUser(const User *user) {
    DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->blocked_users_, FindUserIndex(user));
}

void BlackList::DeleteAll() {
    DefaultWorkingWithVector::DeleteAll(this->blocked_users_);
}

std::vector<std::string> BlackList::GetBlockedUsersNames() const {
    std::vector<std::string> list_of_usernames;
    for (const auto& blocked_user:this->blocked_users_) {
        DefaultWorkingWithVector::AddElementToVector(list_of_usernames,blocked_user->GetUserName());
    }
    return list_of_usernames;
}
