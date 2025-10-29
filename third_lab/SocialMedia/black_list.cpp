#include "../SocialMedia/black_list.h"
#include "../Utils/project_utils.h"

void BlackList::AddUser(const std::string& user) {
    if (FindUserIndex(user) == -1) {
        WorkingWithVector::AddElementToVector(this->blocked_users_, user);
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
    WorkingWithVector::DeleteElementFromVectorByPos(this->blocked_users_, FindUserIndex(user));
}

void BlackList::DeleteAll() {
    WorkingWithVector::DeleteAll(this->blocked_users_);
}

std::vector<std::string> BlackList::GetBlockedUsersNames(){
    return this->blocked_users_;
}
