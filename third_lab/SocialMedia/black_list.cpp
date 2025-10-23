#include "../SocialMedia/black_list.h"
#include "../Utils/project_utils.h"

void BlackList::AddUser(const std::string& user) {
    if (FindUserIndex(user) == -1) {
        DefaultWorkingWithVector::AddElementToVector(this->blocked_users_, user);
    }
}

int BlackList::FindUserIndex(const std::string& user) const {
    int it = 0;
    for (auto &bad_user: this->blocked_users_) {
        if (user == bad_user) {
            return it;
        }
        it += 1;
    }
    return -1;
}

void BlackList::DeleteUser(const std::string& user) {
    DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->blocked_users_, FindUserIndex(user));
}

void BlackList::DeleteAll() {
    DefaultWorkingWithVector::DeleteAll(this->blocked_users_);
}

std::vector<std::string> BlackList::GetBlockedUsersNames(){
    return this->blocked_users_;
}
