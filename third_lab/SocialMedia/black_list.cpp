#include "../SocialMedia/black_list.h"
#include "../Utils/project_utils.h"

void BlackList::AddUser(const std::shared_ptr<User> &user) {
    if (FindUserIndex(user) == -1) {
        DefaultWorkingWithVector::AddElementToVector(this->blocked_users_, user);
    }
}

int BlackList::FindUserIndex(const std::shared_ptr<User> &user){
    if (!user) {
        return -1;
    }
    int it = 0;
    DefaultWorkingWithVector::DeleteUnUsedWeakPtrs(this->blocked_users_);
    for (auto &bad_user: this->blocked_users_) {
        if (user == bad_user.lock()) {
            return it;
        }
        it += 1;
    }
    return -1;
}

void BlackList::DeleteUser(const std::shared_ptr<User> &user) {
    DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->blocked_users_, FindUserIndex(user));
}

void BlackList::DeleteAll() {
    DefaultWorkingWithVector::DeleteAll(this->blocked_users_);
}

std::vector<std::string> BlackList::GetBlockedUsersNames(){
    DefaultWorkingWithVector::DeleteUnUsedWeakPtrs(this->blocked_users_);
    std::vector<std::string> list_of_usernames;
    for (const auto& blocked_user:this->blocked_users_) {
        DefaultWorkingWithVector::AddElementToVector(list_of_usernames,blocked_user.lock()->GetUsername());
    }
    return list_of_usernames;
}
