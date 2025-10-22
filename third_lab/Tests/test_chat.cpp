#include "../Communication/chat.h"
#include <gtest/gtest.h>
#include "../Exceptions/exceptions.h"

class TestChatsMessageAndGroups : public ::testing::Test {
public:
	void SetUp() override {
		chat.WriteMessage(test_message1);
		chat.WriteMessage(test_message2);
		chat.WriteMessage(test_message3);
		sh_user1->SetName("Artem");
		sh_user2->SetName("Johnatan");
	}
	User user2 = User("@Vladgjhgj53334", "hfdhh634u233");
	User user3 = User("@Vsdffgjjg34", "hfdhh6357573");
	std::shared_ptr<User> sh_user1 = std::make_shared<User>("@Artemdjdj", "sldfk54353");
	std::shared_ptr<User> sh_user2 = std::make_shared<User>(user2);
	std::shared_ptr<User> sh_user3 = std::make_shared<User>(user3);
	Message  message = Message();
	Message  message2 = Message("Some info", sh_user1);
	Chat chat = Chat(sh_user1, sh_user2);
	Chat chat2 = Chat(sh_user1, sh_user3);
	std::shared_ptr<Message> test_message1 = std::make_shared<Message>("hello",sh_user2);
	std::shared_ptr<Message> test_message2 = std::make_shared<Message>("world",sh_user2);
	std::shared_ptr<Message> test_message3 = std::make_shared<Message>("My name is artem", sh_user2);
};

TEST_F(TestChatsMessageAndGroups, TestMessageCreation) {
	message.CreateMessage("Hello world", sh_user1);
	ASSERT_EQ(message.GetMessageDefaultText(), "Hello world");

}
TEST_F(TestChatsMessageAndGroups, TestMessageNegativeCreation) {
	ASSERT_THROW(
		message.CreateMessage("", sh_user1),
		ExceptionIncorrectMessage
	);
}

TEST_F(TestChatsMessageAndGroups, TestGetAuthor) {
	message.CreateMessage("Hello world", sh_user1);
	ASSERT_EQ(message.GetAuthor(), sh_user1);
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessage) {
	message2.RefactorMessage("new message");
	ASSERT_EQ(message2.GetMessageDefaultText(), "new message");
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessageIncorect) {
	ASSERT_THROW(
		message2.RefactorMessage("");,
		ExceptionIncorrectMessage
	);
	ASSERT_EQ(message2.GetMessageDefaultText(), "Some info");
}

TEST_F(TestChatsMessageAndGroups, TestWriteMessageInChat) {
	const auto new_message = std::make_shared<Message>("Hello world", sh_user1);
	chat2.WriteMessage(new_message);
	std::string copy_text;
	chat2.CopyMessage(0, copy_text);
	ASSERT_EQ(copy_text, "Hello world");
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessageChat) {
	chat.RefactorMessage("New hello", 0, sh_user2);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(copy, "New hello");
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessageIncorrectNumberChat) {
	ASSERT_THROW(
		chat.RefactorMessage("New hello", -1, sh_user1),
		ExceptionIncorrectNumber
	);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(copy, "hello");
}

TEST_F(TestChatsMessageAndGroups, TestRefactorMessageIncorrectAuthorChat) {
	ASSERT_THROW(
		chat.RefactorMessage("New hello", 0, sh_user1),
		ExceptionAccess
	);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(copy, "hello");
}

TEST_F(TestChatsMessageAndGroups, TestDeleteMessageChat) {
	chat.DeleteMessage(0, sh_user2);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(copy, "world");
}

TEST_F(TestChatsMessageAndGroups, TestDeleteMessageIncorrectNumberOfMessage) {
	ASSERT_THROW(
		chat.DeleteMessage(-1, sh_user1),
		ExceptionIncorrectNumber
	);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(copy, "hello");
}

TEST_F(TestChatsMessageAndGroups, TestDeleteMessageIncorrectAuthorOfMessage) {
	ASSERT_THROW(
		chat.DeleteMessage(0, sh_user1),
		ExceptionAccess
	);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(copy, "hello");
}

TEST_F(TestChatsMessageAndGroups, TestCheckCountOfMessagesAfterDeleting) {
	chat.DeleteMessage(0, sh_user2);
	std::string copy;
	chat.CopyMessage(0, copy);
	ASSERT_EQ(chat.CountMessages(), 2);
}

TEST_F(TestChatsMessageAndGroups, TestDeletingAllMessagesChat) {
	chat.DeleteAllMessages();
	ASSERT_EQ(chat.CountMessages(), 0);
}

TEST_F(TestChatsMessageAndGroups, TestGetCountOfChatMembers) {
	ASSERT_EQ(chat.ListMembers(), (std::vector<std::string> {"@Artemdjdj", "@Vladgjhgj53334"}));
}

TEST_F(TestChatsMessageAndGroups, TestGetCountOfAllMessages) {
	ASSERT_EQ(chat.GetAllMessages().size(), 3);
}
TEST_F(TestChatsMessageAndGroups, TestGetZeroCountOfMessages) {
	ASSERT_EQ(chat2.GetAllMessages().size(), 0);
}



