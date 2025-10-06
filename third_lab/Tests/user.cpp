#include "../User/user.h"
#include <iostream>
#include <gtest/gtest.h>

class TestUser : public ::testing::Test {
	public:
	void SetUp() override {
		user = User("Artemdjdj", "55434434");
	}
	User user;
};

TEST_F(TestUser, TestSetName) {
	user.SetName("Artem");
	ASSERT_EQ(user.GetName(), "Artem");
}

TEST_F(TestUser, TestSetNameNegative) {
	user.SetName("-Artemflsdhjfglsjlksdkfjsdlgjflsghlshgggsfddfse");
	ASSERT_EQ(user.GetName(), "");
}

TEST_F(TestUser, TestSetUserName) {
	user.SetUserName("@Artem");
	ASSERT_EQ(user.GetUserName(), "@Artem");
}

TEST_F(TestUser, TestSetUserNameNegative) {
	user.SetUserName("Artemflsdhjfglsjlksdkfjsdlgjflsghlshgggsfddfse");
	ASSERT_EQ(user.GetUserName(), "");
}

TEST_F(TestUser, TestSetSurName) {
	user.SetSurname("Legend");
	ASSERT_EQ(user.GetSurName(), "Legend");
}

TEST_F(TestUser, TestSetSurNameNegative) {
	user.SetSurname("Artemflsdhjfglsjlk-");
	ASSERT_EQ(user.GetSurName(), "");
}

TEST_F(TestUser, TestEmail) {
	user.SetEmail("art@gmail.com");
	ASSERT_EQ(user.GetEmail(), "art@gmail.com");
}

TEST_F(TestUser, TestEmailNegative) {
	user.SetEmail("$%%$art@gmail.com");
	ASSERT_EQ(user.GetEmail(), "");
}

TEST_F(TestUser, TestSetPhoneNumber) {
	user.SetPhoneNumber("+375291111111");
	ASSERT_EQ(user.GetPhoneNumber(), "+375291111111");
}

TEST_F(TestUser, TestSetPhoneNumberNegative) {
	user.SetPhoneNumber("+375661111111");
	ASSERT_EQ(user.GetPhoneNumber(), "");
}


