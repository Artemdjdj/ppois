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
TEST_F(TestApp, TestLoginAndLogoutIncorrectSituationWithLogout) {
    ASSERT_EQ(app.GetAuthor(), "@Artemdjdj");
    app.Logout();
    ASSERT_THROW(
        app.Logout(),
        std::logic_error
    );
}

TEST_F(TestApp, TestLoginTwice) {
    ASSERT_EQ(app.GetAuthor(), "@Artemdjdj");
    ASSERT_THROW(
        app.Login("@Legend", "fjggutuue673444"),
        std::logic_error
    );
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

TEST_F(TestApp, TestBaseChatFunction) {
    const auto second_user = app.GetUser("@Legend");
    const auto message1 = std::make_shared<Message>("Hello world", app.GetCurrentUser());
    app.CreateNewChat(second_user);
    app.SendMessageToChat(second_user, message1);
    ASSERT_EQ(app.ViewAllHistoryOfChat(second_user).size(), 1);
    const auto message2 = std::make_shared<Message>("Some new information", app.GetCurrentUser());
    app.RefactorMessageInChat(second_user, 0,message2);
    const auto chat = app.GetChat(second_user);
    const auto check_message = chat->GetMessageByNumber(0);
    ASSERT_EQ(check_message->GetMessageDefaultText(), "Some new information");
    app.DeleteMessageFromChat(second_user, 0);
    ASSERT_EQ(app.ViewAllHistoryOfChat(second_user).size(), 0);
    ASSERT_EQ(app.GetChat(second_user), chat);
    app.DeleteChat(second_user);
    ASSERT_EQ(app.GetChat(second_user),nullptr);
}

TEST_F(TestApp, TestGetChatName) {
    const auto second_user = app.GetUser("@Legend");
    app.CreateNewChat(second_user);
    ASSERT_EQ(app.GetChatName(second_user), "@Legend");
}

TEST_F(TestApp, TestGetChatNameOtherAccount) {
    const auto second_user = app.GetUser("@Legend");
    const auto first_user = app.GetUser("@Artemdjdj");
    app.CreateNewChat(second_user);
    app.Logout();
    app.Login("@Legend","fjggutuue673444");
    ASSERT_EQ(app.GetChatName(first_user), "@Artemdjdj");
}







