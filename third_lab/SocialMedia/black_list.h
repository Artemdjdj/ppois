#ifndef BLACK_LIST_H
#define BLACK_LIST_H
#include "../User/user.h"
#include <vector>

class BlackList {
public:
    BlackList() = default;

    void AddUser(User *user);

    void DeleteUser(const User *user);

    void DeleteAll();

private:
    std::vector<User *> bad_users_;

    int FindUserIndex(const User *user) const;
};
#endif //BLACK_LIST_H
