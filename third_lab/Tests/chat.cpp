#include "../Communication/chat.h"
#include <gtest/gtest.h>


class TestChatsMessageAndGroups : public ::testing::Test {
public:
	void SetUp() override {
		chat.WriteMessage("hello",&user1);
		chat.WriteMessage("world",&user2);
		chat.WriteMessage("My name is artem", &user2);
		group.WriteMessage("hello",&user1);
		group.WriteMessage("world",&user2);
		group.WriteMessage("My name is artem", &user2);
		user1.SetName("Artem");
		user2.SetName("Johnatan");
	}
	User user1 = User("@Artemdjdj", "sldfk54353");
	User user2 = User("@Vlad53334", "hfdhh634u233");
	User user3 = User("@Vsdf34", "hfdhh633");
	Message  message = Message();
	Message  message2 = Message("Some info", &user2);
	Chat chat = Chat(&user1, &user2);
	Chat chat2 = Chat(&user1, &user3);
	Group group = Group(&user1);
};

TEST_F(TestChatsMessageAndGroups, TestMessageCreation) {
	ASSERT_TRUE(message.CreateMessage("Hello world", &user1));
}
TEST_F(TestChatsMessageAndGroups, TestMessageNegativeCreation) {
	ASSERT_FALSE(message.CreateMessage("", &user1));
}

TEST_F(TestChatsMessageAndGroups, TestGetAuthor) {
	message.CreateMessage("Hello world", &user1);
	ASSERT_EQ(message.GetAuthor(), &user1);
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessage) {
	message2.RefactorMessage("new message");
	ASSERT_EQ(message2.GetMessageText(), "new message");
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessageIncorect) {
	message2.RefactorMessage("");
	ASSERT_EQ(message2.GetMessageText(), "Some info");
}

TEST_F(TestChatsMessageAndGroups, TestWriteMessageInChat) {
	chat2.WriteMessage("Hello world", &user1);
	std::string copy_text;
	chat2.CopyMessage(0, copy_text);
	ASSERT_EQ(copy_text, "Hello world");
}

TEST_F(TestChatsMessageAndGroups, TestWriteMessageInChatIncorrect) {
	ASSERT_FALSE(chat2.WriteMessage("", &user1));
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessageChat) {
	chat.RefactorMessage("New hello", 0, &user1);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(copy, "New hello");
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessageIncorrectNumberChat) {
	chat.RefactorMessage("New hello", -1, &user1);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(copy, "hello");
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessageIncorrectAuthorChat) {
	chat.RefactorMessage("New hello", 0, &user2);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(copy, "hello");
}

TEST_F(TestChatsMessageAndGroups, TestDeleteMessageChat) {
	chat.DeleteMessage(0, &user1);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(copy, "world");
}

TEST_F(TestChatsMessageAndGroups, TestDeleteMessageIncorrectNumberOfMessage) {
	chat.DeleteMessage(-1, &user1);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(copy, "hello");
}

TEST_F(TestChatsMessageAndGroups, TestDeleteMessageIncorrectAuthorOfMessage) {
	chat.DeleteMessage(0, &user2);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(copy, "hello");
}

TEST_F(TestChatsMessageAndGroups, TestCheckCountOfMessagesAfterDeleting) {
	chat.DeleteMessage(0, &user1);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(chat.CountMessages(), 2);
}

TEST_F(TestChatsMessageAndGroups, TestDeletingAllMessagesChat) {
	chat.DeleteAllMessages();
	ASSERT_EQ(chat.CountMessages(), 0);
}

TEST_F(TestChatsMessageAndGroups, TestGetName) {
	ASSERT_EQ(chat.GetName(), "Johnatan");
}

TEST_F(TestChatsMessageAndGroups, TestGetCountOfChatMembers) {
	ASSERT_EQ(chat.ListMembers(), (std::vector<std::string> {"@Artemdjdj", "@Vlad53334"}));
}

TEST_F(TestChatsMessageAndGroups, TestGroupSetName) {
	group.SetName("Guys");
	ASSERT_EQ(group.GetName(), "Guys");
}

TEST_F(TestChatsMessageAndGroups, TestGetCountOfGroupMembers) {
	ASSERT_EQ(group.ListMembers(), (std::vector<std::string> {"@Artemdjdj"}));
}

TEST_F(TestChatsMessageAndGroups, TestCheckUserIsNotExistInGroup) {
	group.AddUser(&user3, &user1);
	ASSERT_EQ(group.ListMembers(), (std::vector<std::string> {"@Artemdjdj", "@Vsdf34"}));
}

TEST_F(TestChatsMessageAndGroups, TestCheckUserIsExistInGroup) {
	group.AddUser(&user3, &user1);
	group.AddUser(&user3, &user1);
	ASSERT_EQ(group.ListMembers(), (std::vector<std::string> {"@Artemdjdj", "@Vsdf34"}));
}

TEST_F(TestChatsMessageAndGroups, TestDeleteUser) {
	group.AddUser(&user3, &user1);
	group.DeleteUser("@Vsdf34", &user1);
	ASSERT_EQ(group.ListMembers(), (std::vector<std::string> {"@Artemdjdj"}));
}

TEST_F(TestChatsMessageAndGroups, TestDeleteAdmin) {
	group.AddUser(&user3, &user1);
	group.DeleteUser("@Artemdjdj", &user1);
	ASSERT_EQ(group.ListMembers(), (std::vector<std::string> {"@Artemdjdj","@Vsdf34"}));
}

TEST_F(TestChatsMessageAndGroups, TestDeleteIncorrectUserName) {
	group.AddUser(&user3, &user1);
	group.DeleteUser("jsdlfjlsdjlfjs", &user1);
	ASSERT_EQ(group.ListMembers(), (std::vector<std::string> {"@Artemdjdj","@Vsdf34"}));
}

TEST_F(TestChatsMessageAndGroups, TestDeleteIncorrectAdmin) {
	group.AddUser(&user3, &user1);
	group.DeleteUser("@Vsdf34", &user2);
	ASSERT_EQ(group.ListMembers(), (std::vector<std::string> {"@Artemdjdj","@Vsdf34"}));
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessageGroup) {
	group.RefactorMessage("New hello", 0, &user1);
	std::string copy;
	group.CopyMessage(0, copy);
	ASSERT_EQ(copy, "New hello");
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessageIncorrectNumberGroup) {
	group.RefactorMessage("New hello", -1, &user1);
	std::string copy;
	group.CopyMessage(0, copy);
	ASSERT_EQ(copy, "hello");
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessageIncorrectAuthorGroup) {
	group.RefactorMessage("New hello", 0, &user2);
	std::string copy;
	group.CopyMessage(0, copy);
	ASSERT_EQ(copy, "hello");
}

TEST_F(TestChatsMessageAndGroups, TestDeleteMessageGroup) {
	group.DeleteMessage(0, &user1);
	std::string copy;
	group.CopyMessage(0, copy);
	ASSERT_EQ(copy, "world");
}

TEST_F(TestChatsMessageAndGroups, TestDeleteMessageIncorrectNumberOfMessageGroup) {
	group.DeleteMessage(-1, &user1);
	std::string copy;
	group.CopyMessage(0, copy);
	ASSERT_EQ(copy, "hello");
}

TEST_F(TestChatsMessageAndGroups, TestDeleteMessageIncorrectAuthorOfMessageGroup) {
	group.DeleteMessage(0, &user2);
	std::string copy;
	group.CopyMessage(0, copy);
	ASSERT_EQ(copy, "hello");
}

TEST_F(TestChatsMessageAndGroups, TestCheckCountOfMessagesAfterDeletingGroup) {
	group.DeleteMessage(0, &user1);
	std::string copy;
	group.CopyMessage(0, copy);
	ASSERT_EQ(group.CountMessages(), 2);
}

TEST_F(TestChatsMessageAndGroups, TestDeletingAllMessagesGroup) {
	group.DeleteAllMessages();
	ASSERT_EQ(group.CountMessages(), 0);
}




