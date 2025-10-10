#include "../User/user.h"
#include "../Exceptions/exceptions.h"
#include <iostream>
#include <gtest/gtest.h>

class TestUser : public ::testing::Test {
	public:
	void SetUp() override {
		user = User("@Artemdjdj", "554shflsd34434");
	}
	User user;
};

TEST_F(TestUser, TestSetName) {
	user.SetName("Artem");
	ASSERT_EQ(user.GetName(), "Artem");
}

TEST_F(TestUser, TestSetNameNegative) {
	ASSERT_THROW(
	   user.SetName("-Artemflsdhjfglsjlksdkfjsdlgjflsghlshgggsfddfse"),
	   ExceptionName
   );
}

TEST_F(TestUser, TestSetUserName) {
	user.SetUserName("@Artem");
	ASSERT_EQ(user.GetUserName(), "@Artem");
}

TEST_F(TestUser, TestSetUserNameNegative) {
	ASSERT_THROW(
	   user.SetUserName("Artemflsdhjfglsjlksdkfjsdlgjflsghlshgggsfddfse"),
	   ExceptionUserName
   );
}

TEST_F(TestUser, TestSetSurName) {
	user.SetSurname("Legend");
	ASSERT_EQ(user.GetSurName(), "Legend");
}

TEST_F(TestUser, TestSetSurNameNegative) {
	ASSERT_THROW(
	   user.SetSurname("Artemflsdhjfglsjlk-"),
	   ExceptionName
   );
}

TEST_F(TestUser, TestEmail) {
	user.SetEmail("art@gmail.com");
	ASSERT_EQ(user.GetEmail(), "art@gmail.com");
}

TEST_F(TestUser, TestEmailNegative) {
	ASSERT_THROW(
	   user.SetEmail("$%%$art@gmail.com"),
	   ExceptionEmail
   );
}

TEST_F(TestUser, TestSetPhoneNumber) {
	user.SetPhoneNumber("+375291111111");
	ASSERT_EQ(user.GetPhoneNumber(), "+375291111111");
}

TEST_F(TestUser, TestSetPhoneNumberNegative) {
	ASSERT_THROW(
	   user.SetPhoneNumber("+375661111111"),
	   ExceptionPhoneNumber
   );
}


