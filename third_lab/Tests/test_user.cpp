#include "../User/user.h"
#include "../Exceptions/exceptions.h"
#include <iostream>
#include <gtest/gtest.h>

class TestUserAndProfile : public ::testing::Test {
public:
    void SetUp() override {
        profile.AddUserToBlackList(user5);
    }
    User user = User("@Artemdjdj", "554shflsd34434");
    User user2 = User("@Genius", "55sgsjglja4");
    const std::string user4 = "@Geniusss";
    const std::string user5 ="@Vladus";
    Role role = Role("user");
    Profile profile = Profile(user.GetUsername());
};

TEST_F(TestUserAndProfile, TestEqUser) {
    const auto user3 = User("@Genius", "55sgsjglja4");
    ASSERT_TRUE(user2 == user3);
}

TEST_F(TestUserAndProfile, TestNoEqUser) {
    const auto user3 = User("@Geniuss", "55sgsjglja4");
    ASSERT_TRUE(user2 != user3);
}

TEST_F(TestUserAndProfile, TestSetName) {
    user.SetName("Artem");
    ASSERT_EQ(user.GetName(), "Artem");
}


TEST_F(TestUserAndProfile, TestSetNameNegative) {
    ASSERT_THROW(
        user.SetName("-Artemflsdhjfglsjlksdkfjsdlgjflsghlshgggsfddfse"),
        ExceptionName
    );
}

TEST_F(TestUserAndProfile, TestSetUserName) {
    user.SetUserName("@Artem");
    ASSERT_EQ(user.GetUsername(), "@Artem");
}

TEST_F(TestUserAndProfile, TestSetUserNameNegative) {
    ASSERT_THROW(
        user.SetUserName("Artemflsdhjfglsjlksdkfjsdlgjflsghlshgggsfddfse"),
        ExceptionUserName
    );
}

TEST_F(TestUserAndProfile, TestSetSurName) {
    user.SetSurname("Legend");
    ASSERT_EQ(user.GetSurName(), "Legend");
}

TEST_F(TestUserAndProfile, TestSetSurNameNegative) {
    ASSERT_THROW(
        user.SetSurname("Artemflsdhjfglsjlk-"),
        ExceptionName
    );
}

TEST_F(TestUserAndProfile, TestEmail) {
    user.SetEmail("art@gmail.com");
    ASSERT_EQ(user.GetEmail(), "art@gmail.com");
}

TEST_F(TestUserAndProfile, TestEmailNegative) {
    ASSERT_THROW(
        user.SetEmail("$%%$art@gmail.com"),
        ExceptionEmail
    );
}

TEST_F(TestUserAndProfile, TestSetPhoneNumber) {
    user.SetPhoneNumber("+375291111111");
    ASSERT_EQ(user.GetPhoneNumber(), "+375291111111");
}

TEST_F(TestUserAndProfile, TestSetPhoneNumberNegative) {
    ASSERT_THROW(
        user.SetPhoneNumber("+375661111111"),
        ExceptionPhoneNumber
    );
}

TEST_F(TestUserAndProfile, TestSetRole) {
    user.SetRole(role);
    ASSERT_EQ(user.GetRole(), "user");
}

TEST_F(TestUserAndProfile, TestSetLocation) {
    profile.SetLocation("BSUIR");
    ASSERT_EQ(profile.GetLocation(), "BSUIR");
}

TEST_F(TestUserAndProfile, TestSetIncorrectLocation) {
    profile.SetLocation("");
    ASSERT_EQ(profile.GetLocation(), "");
}

TEST_F(TestUserAndProfile, TestSetBiography) {
    profile.SetBiography("Student");
    ASSERT_EQ(profile.GetBiography(), "Student");
}

TEST_F(TestUserAndProfile, TestSetIncorrectBiography) {
    profile.SetBiography("");
    ASSERT_EQ(profile.GetBiography(), "");
}

TEST_F(TestUserAndProfile, TestSetMan) {
    profile.SetGender(true);
    ASSERT_TRUE(profile.GetGender());
}

TEST_F(TestUserAndProfile, TestSetWomen) {
    profile.SetGender(false);
    ASSERT_FALSE(profile.GetGender());
}

TEST_F(TestUserAndProfile, TestSetAge) {
    profile.SetAge(18);
    ASSERT_EQ(profile.GetAge(), 18);
}

TEST_F(TestUserAndProfile, TestSetIncorrectAgeSmall) {
    ASSERT_THROW(
        profile.SetAge(12),
        ExceptionIncorrectYear
    );
}

TEST_F(TestUserAndProfile, TestSetIncorrectAgeBig) {
    ASSERT_THROW(
        profile.SetAge(3243),
        ExceptionIncorrectYear
    );
}

TEST_F(TestUserAndProfile, TestAddUser) {
    profile.AddUserToBlackList(user4);
    ASSERT_EQ((std::vector<std::string>{"@Vladus","@Geniusss"}), profile.GetBlockedUsersNamesFromBlackList());
}

TEST_F(TestUserAndProfile, TestDeleteUser) {
    profile.DeleteUserFromBlackList(user5);
    ASSERT_EQ((std::vector<std::string>{}), profile.GetBlockedUsersNamesFromBlackList());
}

TEST_F(TestUserAndProfile, TestDeleteUserIncorrect) {
    ASSERT_THROW(
        profile.DeleteUserFromBlackList(user4),
        ExceptionIncorrectNumber
    );
}

TEST_F(TestUserAndProfile, TestDeleteAll) {
    profile.AddUserToBlackList(user4);
    profile.DeleteAllFromBlackList();
    ASSERT_EQ((std::vector<std::string>{}), profile.GetBlockedUsersNamesFromBlackList());
}