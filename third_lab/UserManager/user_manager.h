#ifndef THIRD_LAB_USER_MANAGER_H
#define THIRD_LAB_USER_MANAGER_H
#include <memory>
#include <unordered_map>
#include <vector>
#include "../User/user.h"
#include "../WorkingWithUser/working_with_password.h"

class UserManager {
public:
    std::shared_ptr<User> CreateUser(const std::string &username, const std::string &password,
                                     const std::string &name = "");

    std::vector<std::shared_ptr<User> > GetAllUsers() const;

    std::shared_ptr<User> GetUser(const std::string &username);

    std::shared_ptr<User> AuthenticateUser(const std::string& username, const std::string&password);

    void DeleteUser(const std::shared_ptr<User> &user);

    bool IsUserExist(const std::string &username) const;

private:
    std::unordered_map<std::string, std::shared_ptr<User> > users_;
};
#endif //THIRD_LAB_USER_MANAGER_H
