#include "../UserManager/user_manager.h"
#include <gtest/gtest.h>

class TestUserAndProfileManager : public::testing::Test {
public:
    void SetUp() override {
        user = user_manager.CreateUser("@Artemdjdj", "fdjglsj43y54", "Artem");
        user2 = user_manager.CreateUser("@artemdjdj", "fdjglsf54", "Artem");
    }
    UserManager user_manager;
    std::shared_ptr<User> user;
    std::shared_ptr<User> user2;
};

TEST_F(TestUserAndProfileManager, TestCreateUser) {
    std::shared_ptr<User> user3 = user_manager.CreateUser("@Artemdjdj2", "fdjglsj43y54", "Artem");
    ASSERT_EQ(user_manager.GetAllUsers().size(), 3);
}

TEST_F(TestUserAndProfileManager, TestCreateUserResultNullptr) {
    std::shared_ptr<User> user3 = user_manager.CreateUser("@Artemdjdj2", "fdjglsj43y54", "Artem");
    ASSERT_THROW(
        user_manager.CreateUser("@Artemdjdj2", "fdjglsj43y54", "Artem"),
        std::logic_error
    );
    ASSERT_EQ(user_manager.GetAllUsers().size(), 3);
}

TEST_F(TestUserAndProfileManager, TestGetUser) {
    ASSERT_EQ(user, user_manager.GetUser("@Artemdjdj"));
}

TEST_F(TestUserAndProfileManager, TestDeleteUser) {
    user_manager.DeleteUser(user);
    ASSERT_EQ(nullptr, user_manager.GetUser("@Artemdjdj"));
    ASSERT_EQ(user_manager.GetAllUsers().size(), 1);
}

TEST_F(TestUserAndProfileManager, TestDeleteUserEmptyAuthor) {
    ASSERT_THROW(
        user_manager.DeleteUser(nullptr),
        std::invalid_argument
    );
}

TEST_F(TestUserAndProfileManager, TestDeleteUserIncorrectUser) {
    user_manager.DeleteUser(user);
    ASSERT_THROW(
        user_manager.DeleteUser(user),
        std::logic_error
    );
}

TEST_F(TestUserAndProfileManager, TestAuthenticateUser) {
    ASSERT_EQ(user, user_manager.AuthenticateUser("@Artemdjdj", "fdjglsj43y54"));
}

TEST_F(TestUserAndProfileManager, TestAuthenticateUserIncorrectPassword) {
    ASSERT_THROW(
        user_manager.AuthenticateUser("@Artemdjdj", "fdjglsj43y5"),
        std::logic_error
    );
}

TEST_F(TestUserAndProfileManager, TestAuthenticateUserIncorrectUserName) {
    ASSERT_THROW(
        user_manager.AuthenticateUser("@Artemdjdj", "fdjglsj43y5"),
        std::logic_error
    );
}
