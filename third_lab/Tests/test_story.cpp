#include <gtest/gtest.h>
#include <../SocialMedia/story.h>
#include <../User/user.h>


class TestStorySettings : public ::testing::Test {
public:
    void SetUp() override{}
    StorySettings settings  = StorySettings("default", true);
};


class TestStory : public ::testing::Test {
public:
    void SetUp() override{}
    User user = User("@Artemdjdj", "252352353");
    StorySettings settings  = StorySettings("default", true);
    Story story = Story("My day", "Some info", settings,&user);
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
    settings.SetCategory("important");
    ASSERT_EQ(settings.GetCategory(), "important");
}
