#ifndef BLACK_LIST_H
#define BLACK_LIST_H
#include "../User/user.h"
#include <vector>

class BlackList {
public:
    BlackList() = default;

    void AddUser(const std::shared_ptr<User> &user);

    void DeleteUser(const std::shared_ptr<User> &user);

    void DeleteAll();

    std::vector<std::string> GetBlockedUsersNames();

private:
    std::vector<std::weak_ptr<User>> blocked_users_;

    int FindUserIndex(const std::shared_ptr<User> &user);
};
#endif //BLACK_LIST_H
