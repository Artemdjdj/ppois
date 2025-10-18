#include <gtest/gtest.h>
#include "exceptions.h"
#include <memory>
#include "../SocialMedia/black_list.h"

class TestBlackList : public ::testing::Test {
public:
    void SetUp() override {
        blacklist.AddUser(user1);
    }

    std::shared_ptr<User> user1 = std::make_shared<User>("@Artemdjdj", "gsgg5093495");
    std::shared_ptr<User> user2 = std::make_shared<User>("@Artemdjdj35", "5093445hdskfhsk");
    BlackList blacklist = BlackList();
};

TEST_F(TestBlackList, TestAddUser) {
    blacklist.AddUser(user2);
    ASSERT_EQ((std::vector<std::string>{"@Artemdjdj","@Artemdjdj35"}), blacklist.GetBlockedUsersNames());
}

TEST_F(TestBlackList, TestDeleteUser) {
    blacklist.DeleteUser(user1);
    ASSERT_EQ((std::vector<std::string>{}), blacklist.GetBlockedUsersNames());
}

TEST_F(TestBlackList, TestDeleteUserIncorrect) {
    ASSERT_THROW(
        blacklist.DeleteUser(user2),
        ExceptionIncorrectNumber
    );
}

TEST_F(TestBlackList, TestDeleteAll) {
    blacklist.AddUser(user2);
    blacklist.DeleteAll();
    ASSERT_EQ((std::vector<std::string>{}), blacklist.GetBlockedUsersNames());
}
