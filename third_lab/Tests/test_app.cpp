#include <complex>
#include <gtest/gtest.h>
#include "../App/app.h"

class TestApp : public::testing::Test {
public:
    void SetUp() override {
        app.RegistrateUser("@Legend", "fjggutuue673444");
        app.RegistrateUser("@Artemdjdj", "fjls46345jt34534");
    }
    App app = App();
};

TEST_F(TestApp, TestRegistration) {
    ASSERT_EQ(app.GetCountOfUsers(), 2);
    app.RegistrateUser("@Artemdjdj343", "5ijgkjsft3bbbbi2");
    ASSERT_EQ(app.GetCountOfUsers(), 3);
}

TEST_F(TestApp, TestRegistrationSuchUserExist) {
    ASSERT_THROW(
        app.RegistrateUser("@Artemdjdj", "5ijgkjsft3bbbbi2"),
        std::logic_error
    );
}

TEST_F(TestApp, TestLoginAndLogout) {
    app.Logout();
    ASSERT_EQ(app.GetAuthor(), "");
    app.Login("@Artemdjdj", "fjls46345jt34534");
    ASSERT_EQ(app.GetAuthor(), "@Artemdjdj");
}

TEST_F(TestApp, TestLoginAndLogoutIncorrectPassword) {
    ASSERT_EQ(app.GetAuthor(), "@Artemdjdj");
    app.Logout();
    ASSERT_THROW(
        app.Login("@Artemdjdj", "fjl46345jt34534"),
        std::logic_error
    );
    ASSERT_EQ(app.GetAuthor(), "");
}

TEST_F(TestApp, TestLoginAndLogoutIncorrectUsername) {
    ASSERT_EQ(app.GetAuthor(), "@Artemdjdj");
    app.Logout();
    ASSERT_THROW(
        app.Login("@Artemdjdj544", "fjls46345jt34534"),
        std::logic_error
    );
    ASSERT_EQ(app.GetAuthor(), "");
}

TEST_F(TestApp, TestDeleteAccount) {
    ASSERT_EQ(app.GetAuthor(), "@Artemdjdj");
    app.DeleteAccount();
    ASSERT_EQ(app.GetAuthor(), "");
}

TEST_F(TestApp, TestDeleteEmptyAccount) {
    ASSERT_EQ(app.GetAuthor(), "@Artemdjdj");
    app.Logout();
    ASSERT_THROW(
        app.DeleteAccount(),
        std::logic_error
    );
}

TEST_F(TestApp, TestCreateChat) {
    const auto second_user = app.GetUser("@Legend");
    app.CreateNewChat(second_user);
    ASSERT_EQ(app.GetAllChats().size(), 1);
}

TEST_F(TestApp, TestGetAllChatsNotItEmpty) {
    ASSERT_THROW(
        app.GetAllChats(),
        std::logic_error
    );
}

TEST_F(TestApp, TestSendMessageToChat) {
    const auto second_user = app.GetUser("@Legend");
    app.CreateNewChat(second_user);
    const auto message1 = std::make_shared<Message>("Hello world", app.GetCurrentUser());
    app.SendMessageToChat(second_user, message1);
    ASSERT_EQ(app.ViewAllHistoryOfChat(second_user).size(), 1);
}





