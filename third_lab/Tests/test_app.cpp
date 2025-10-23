#include <complex>
#include <gtest/gtest.h>
#include "../App/app.h"

class TestApp : public::testing::Test {
public:
    void SetUp() override {
        app.RegistrateUser("@Legend", "fjggutuue673444");
        app.RegistrateUser("@Genius", "fjls46345jt34534");
        app.RegistrateUser("@Artemdjdj", "fjls46345jt34534");
        app.AddUserToBlackList("@Legend");
        app.AddUserToBlackList("@Genius");
    }
    App app = App();
};

TEST_F(TestApp, TestRegistration) {
    ASSERT_EQ(app.GetCountOfUsers(), 3);
    app.RegistrateUser("@Artemdjdj343", "5ijgkjsft3bbbbi2");
    ASSERT_EQ(app.GetCountOfUsers(), 4);
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
    app.CreateNewChat("@Legend");
    ASSERT_EQ(app.GetAllChats().size(), 1);
}

TEST_F(TestApp, TestGetAllChatsNotItEmpty) {
    ASSERT_THROW(
        app.GetAllChats(),
        std::logic_error
    );
}

TEST_F(TestApp, TestBaseChatFunction) {
    const auto message1 = std::make_shared<Message>("Hello world", "@Artemdjdj");
    app.CreateNewChat("@Legend");
    app.SendMessageToChat("@Legend", message1);
    ASSERT_EQ(app.ViewAllHistoryOfChat("@Legend").size(), 1);
    const auto message2 = std::make_shared<Message>("Some new information", "@Artemdjdj");
    app.RefactorMessageInChat("@Legend", 0,message2);
    const auto chat = app.GetChat("@Legend");
    const auto check_message = chat->GetMessageByNumber(0);
    ASSERT_EQ(check_message->GetMessageDefaultText(), "Some new information");
    app.DeleteMessageFromChat("@Legend", 0);
    ASSERT_EQ(app.ViewAllHistoryOfChat("@Legend").size(), 0);
    ASSERT_EQ(app.GetChat("@Legend"), chat);
    app.DeleteChat("@Legend");
    ASSERT_EQ(app.GetChat("@Legend"),nullptr);
}

TEST_F(TestApp, TestGetChatName) {
    app.CreateNewChat("@Legend");
    ASSERT_EQ(app.GetChatName("@Legend"), "@Legend");
}

TEST_F(TestApp, TestGetChatNameOtherAccount) {
    const auto second_user = app.GetUser("@Legend");
    const auto first_user = app.GetUser("@Artemdjdj");
    app.CreateNewChat("@Legend");
    app.Logout();
    app.Login("@Legend","fjggutuue673444");
    ASSERT_EQ(app.GetChatName("@Artemdjdj"), "@Artemdjdj");
}

TEST_F(TestApp, TestSetLocation) {
    app.SetLocation("Belarus, Minsk");
    ASSERT_EQ(app.GetLocation(), "Belarus, Minsk");
}

TEST_F(TestApp, TestSetBiography) {
    app.SetBiography("Some information");
    ASSERT_EQ(app.GetBiography(), "Some information");
}

TEST_F(TestApp, TestSetGender) {
    app.SetGender(true);
    ASSERT_TRUE(app.GetGender());
}

TEST_F(TestApp, TestSetAge) {
    app.SetAge(18);
    ASSERT_EQ(app.GetAge(), 18);
}

TEST_F(TestApp, TestSetIncorrectAgeSmall) {
    ASSERT_THROW(
        app.SetAge(12),
        ExceptionIncorrectYear
    );
}

TEST_F(TestApp, TestSetIncorrectAgeBig) {
    ASSERT_THROW(
        app.SetAge(3243),
        ExceptionIncorrectYear
    );
}

TEST_F(TestApp, TestAddUser) {
    ASSERT_EQ((std::vector<std::string>{"@Legend","@Genius"}), app.GetBlockedUsersNamesFromBlackList());
}

TEST_F(TestApp, TestAddUserYourself) {
    ASSERT_THROW(
        app.AddUserToBlackList("@Artemdjdj"),
        std::logic_error
    );
}

TEST_F(TestApp, TestAddUserIncorrect) {
    ASSERT_THROW(
        app.AddUserToBlackList("@Artemb"),
        std::logic_error
    );
}

TEST_F(TestApp, TestDeleteUser) {
    app.DeleteUserFromBlackList("@Legend");
    ASSERT_EQ((std::vector<std::string>{"@Genius"}), app.GetBlockedUsersNamesFromBlackList());
}

TEST_F(TestApp, TestDeleteUserIncorrect) {
    ASSERT_THROW(
        app.DeleteUserFromBlackList("gsgsd"),
        ExceptionIncorrectNumber
    );
}

TEST_F(TestApp, TestDeleteAll) {
    app.DeleteAllFromBlackList();
    ASSERT_EQ((std::vector<std::string>{}), app.GetBlockedUsersNamesFromBlackList());
}





