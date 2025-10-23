#include <gtest/gtest.h>
#include <../SocialMedia/story.h>
#include <../User/user.h>

#include "../Exceptions/exceptions.h"


class TestStorySettings : public ::testing::Test {
public:
    void SetUp() override {
    }

    StorySettings settings = StorySettings("default", true);
};


class TestStory : public ::testing::Test {
public:
    void SetUp() override {
    }

    std::shared_ptr<User> author= std::make_shared<User>("@Artemdjdj", "252352353");
    std::shared_ptr<User>author2 = std::make_shared<User>("@Artemdjdjs", "252352353ff");
    std::string user = author->GetUsername();
    std::string user2 = author2->GetUsername();
    StorySettings settings = StorySettings("default", true);
    Story story = Story("My day", "Some info", settings, user, "4234fsd");
};

TEST_F(TestStorySettings, TestSetCategory) {
    settings.SetCategory("important");
    ASSERT_EQ(settings.GetCategory(), "important");
}

TEST_F(TestStorySettings, TestSetCategoryBigLetters) {
    settings.SetCategory("Important");
    ASSERT_EQ(settings.GetCategory(), "important");
}

TEST_F(TestStorySettings, TestSetCategoryAllBigLetters) {
    settings.SetCategory("IMPORTANT");
    ASSERT_EQ(settings.GetCategory(), "important");
}

TEST_F(TestStorySettings, TestSetCategoryIncorrect) {
    ASSERT_THROW(
        settings.SetCategory("jflsjdlj"),
        std::invalid_argument
    );
    ASSERT_EQ(settings.GetCategory(), "default");
}

TEST_F(TestStorySettings, TestMakePublicStory) {
    settings.MakeStoryPublic();
    ASSERT_TRUE(settings.GetTypeOfVisibility());
}

TEST_F(TestStorySettings, TestMakePrivateStory) {
    settings.MakeStoryPrivate();
    ASSERT_FALSE(settings.GetTypeOfVisibility());
}

TEST_F(TestStory, TestSetStoryName) {
    story.SetName("Relax", user);
    ASSERT_EQ(story.GetName(), "Relax");
}

TEST_F(TestStory, TestSetStoryNameIncorrectAuthor) {
    ASSERT_THROW(
        story.SetName("Relax", user2),
        ExceptionAccess
    );
}

TEST_F(TestStory, TestSetStoryNameIncorrectArgument) {
    ASSERT_THROW(
        story.SetName("", user),
        std::invalid_argument
    );
}

TEST_F(TestStory, TestSetStoryInfo) {
    story.SetInfo("Relax", user);
    ASSERT_EQ(story.GetInfo(), "Relax");
}

TEST_F(TestStory, TestSetStoryInfoIncorrectAuthor) {
    ASSERT_THROW(
        story.SetInfo("Relax", user2),
        ExceptionAccess
    );
}

TEST_F(TestStory, TestSetStoryInfoIncorrectArgument) {
    ASSERT_THROW(
        story.SetInfo("", user),
        std::invalid_argument
    );
}

TEST_F(TestStory, TestChangeVisibilityPublic) {
    story.MakeVisibilityPublic(true, user);
    ASSERT_TRUE(story.CheckIsPublic());
}

TEST_F(TestStory, TestChangeVisibilitPrivate) {
    story.MakeVisibilityPublic(false, user);
    ASSERT_FALSE(story.CheckIsPublic());
}



