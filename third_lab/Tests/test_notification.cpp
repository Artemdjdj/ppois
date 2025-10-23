#include <gtest/gtest.h>
#include "../SocialMedia/notification.h"

class TestNotification : public::testing::Test {
public:
    User author = User("@Artemdjdj", "gsgg5093495");
    User author2 = User("@Artemdjdj35", "5093445hdskfhsk");;
    std::string user1 = author.GetUsername();
    std::string user2 = author2.GetUsername();
    Notification notification = Notification("notificaion", "some info", user1, user2);
};

TEST_F(TestNotification, TestShowNotification) {
    notification.ShowNotification();
    ASSERT_TRUE(notification.IsShow());
}

TEST_F(TestNotification, TestDoNotShowNotification) {
    notification.DoNotShowNotification();
    ASSERT_FALSE(notification.IsShow());
}

TEST_F(TestNotification, TestGetSender) {
    ASSERT_EQ(user1,notification.GetSender());
}

TEST_F(TestNotification, TestGetReceiver) {
    ASSERT_EQ(user2,notification.GetReceiver());
}
