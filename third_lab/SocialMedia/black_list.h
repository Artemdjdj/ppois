#ifndef BLACK_LIST_H
#define BLACK_LIST_H
#include <vector>
#include <memory>
class User;

class BlackList {
public:
    BlackList() = default;

    void AddUser(const std::string& user);

    void DeleteUser(const std::string& user);

    void DeleteAll();

    std::vector<std::string> GetBlockedUsersNames();

private:
    std::vector<std::string> blocked_users_;

    int FindUserIndex(const std::string& user) const;
};
#endif //BLACK_LIST_H
