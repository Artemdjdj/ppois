#include "../SocialMedia/black_list.h"
#include "../Utils/project_utils.h"

void BlackList::AddUser(User *user) {
    DefaultWorkingWithVector::AddElementToVector(this->bad_users_, user);
}

int BlackList::FindUserIndex(const User *user) const {
    int it = 0;
    for (auto &bad_user: this->bad_users_) {
        if (user == bad_user) {
            return it;
        }
        it += 1;
    }
    return it;
}

void BlackList::DeleteUser(const User *user) {
    DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->bad_users_, FindUserIndex(user));
}

void BlackList::DeleteAll() {
    DefaultWorkingWithVector::DeleteAll(this->bad_users_);
}
