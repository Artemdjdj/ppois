#include "../UserManager/user_manager.h"
#include <gtest/gtest.h>

class TestUserManager : public::testing::Test {
public:
    void SetUp() override {
        user = user_manager.CreateUser("@Artemdjdj", "fdjglsj43y54", "Artem");
        user2 = user_manager.CreateUser("@artemdjdj", "fdjglsf54", "Artem");
    }

    UserManager user_manager;
    std::shared_ptr<User> user;
    std::shared_ptr<User> user2;
};

TEST_F(TestUserManager, TestCreateUser) {
    std::shared_ptr<User> user3 = user_manager.CreateUser("@Artemdjdj2", "fdjglsj43y54", "Artem");
    ASSERT_EQ(user_manager.GetAllUsers().size(), 3);
}

TEST_F(TestUserManager, TestCreateUserResultNullptr) {
    std::shared_ptr<User> user3 = user_manager.CreateUser("@Artemdjdj2", "fdjglsj43y54", "Artem");
    ASSERT_EQ(nullptr, user_manager.CreateUser("@Artemdjdj", "fdjglsj43y54", "Artem"));
    ASSERT_EQ(user_manager.GetAllUsers().size(), 3);
}

TEST_F(TestUserManager, TestGetUser) {
    ASSERT_EQ(user, user_manager.GetUser("@Artemdjdj"));
}

TEST_F(TestUserManager, TestDeleteUser) {
    user_manager.DeleteUser(user);
    ASSERT_EQ(nullptr, user_manager.GetUser("@Artemdjdj"));
    ASSERT_EQ(user_manager.GetAllUsers().size(), 1);
}

TEST_F(TestUserManager, TestDeleteUserEmptyAuthor) {
    ASSERT_THROW(
        user_manager.DeleteUser(nullptr),
        std::invalid_argument
    );
}

TEST_F(TestUserManager, TestDeleteUserIncorrectUser) {
    user_manager.DeleteUser(user);
    ASSERT_THROW(
        user_manager.DeleteUser(user),
        std::logic_error
    );
}

TEST_F(TestUserManager, TestAuthenticateUser) {
    ASSERT_EQ(user, user_manager.AuthenticateUser("@Artemdjdj", "fdjglsj43y54"));
}

TEST_F(TestUserManager, TestAuthenticateUserIncorrectPassword) {
    ASSERT_EQ(nullptr, user_manager.AuthenticateUser("@Artemdjdj", "fdjglsj43y5"));
}

TEST_F(TestUserManager, TestAuthenticateUserIncorrectUserName) {
    ASSERT_EQ(nullptr, user_manager.AuthenticateUser("@Artemdjdj", "fdjglsj43y5"));
}


