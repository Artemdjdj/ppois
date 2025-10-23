#include <gtest/gtest.h>
#include "../DataManager/data_manager.h"
#include "../User/user.h"

class TestDataManager : public::testing::Test {
public:
    void SetUp() override {
        data_manager.CreateNewChat(user, user2);
        data_manager.CreateNewStory("Name", "Some interesting", story_settings, user);
    }
    StorySettings story_settings = StorySettings("default",true);
    DataManager data_manager;
    User author = User("@Artemdjdj", "fdjglsj43y54", "Artem");
    User author2 = User("@artemdjdj", "fdjglsf54", "Artem");
    std::string user = author.GetUsername();
    std::string user2 = author2.GetUsername();
};

TEST_F(TestDataManager, CreateNewChat) {
    ASSERT_EQ(data_manager.GetAllChats(user).size(), 1);
    ASSERT_EQ(data_manager.GetAllChats(user2).size(), 1);
}

TEST_F(TestDataManager, CreateNewChatExist) {
    ASSERT_THROW(
        data_manager.CreateNewChat(user, user2),
        std::logic_error
    );
}

TEST_F(TestDataManager, GetChat) {
    ASSERT_EQ(data_manager.GetChat(user, user2), data_manager.GetAllChats(user)[0]);
}

TEST_F(TestDataManager, DeleteChat) {
    data_manager.DeleteChat(user, user2);
    ASSERT_EQ(data_manager.GetAllChats(user).size(), 0);
    ASSERT_EQ(data_manager.GetAllChats(user2).size(), 0);
}

TEST_F(TestDataManager, DeleteChatIsNotExist) {
    data_manager.DeleteChat(user, user2);
    ASSERT_THROW(
        data_manager.DeleteChat(user, user2),
        std::logic_error
    );
    ASSERT_EQ(data_manager.GetAllChats(user).size(), 0);
}

TEST_F(TestDataManager, CreateNewStory) {
    ASSERT_EQ(data_manager.GetAllStories(user).size(), 1);
}

TEST_F(TestDataManager, GetStory) {
    const std::string id = data_manager.GetAllStories(user)[0]->GetId();
    ASSERT_EQ(data_manager.GetStory(user,id), data_manager.GetAllStories(user)[0]);
}

TEST_F(TestDataManager, DeleteStory) {
    const std::string id = data_manager.GetAllStories(user)[0]->GetId();
    data_manager.DeleteStory(user, id);
    ASSERT_EQ(data_manager.GetAllStories(user).size(), 0);
}

TEST_F(TestDataManager, DeleteStoryIsNotExist) {
    const std::string id = data_manager.GetAllStories(user)[0]->GetId();
    data_manager.DeleteStory(user, id);
    ASSERT_THROW(
        data_manager.DeleteStory(user, id),
        ExceptionIncorrectNumber
    );
    ASSERT_EQ(data_manager.GetAllStories(user).size(), 0);
}





