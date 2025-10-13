#include "exceptions.h"
#include "../SocialMedia/post.h"
#include "../SocialMedia/reaction.h"
#include "../SocialMedia/hash_tag.h"
#include "gtest/gtest.h"
#include <iostream>

class TestPost : public testing::Test {
public:
    std::string info =
            "Global warming refers to the increase in the planet’s overall average temperature in recent decades. Natural processes have \
                    always affected Earth’s temperature and climate, but more recently, the planet’s temperature and "
            "climate have changed at a higher pace than nature alone can explain";
    User user = User("@Artemdjdj", "252352353");
    User user2 = User("@Eugen2007", "fshdjkfhsk4343");
    Post post = Post("The problem of global warming",
                     info, &user);
    Reaction reaction = Reaction("like", &user2);
    HashTag hash_tag = HashTag("#global", &user);
    HashTag hash_tag2 = HashTag("#global", &user2);
    Poll poll = Poll("The capital of Belarus",
                     (std::vector<std::string>{
                         "Minsk", "Washington", "Moscow"
                     }), &user);
};

TEST_F(TestPost, TestSetName) {
    post.SetName("The name of this post", &user);
    ASSERT_EQ("The name of this post", post.GetName());
}

TEST_F(TestPost, TestSetNameIncorrectAuthor) {
    ASSERT_THROW(
        post.SetName("The name of this post", &user2),
        ExceptionAccess
    );
    ASSERT_EQ("The problem of global warming", post.GetName());
}

TEST_F(TestPost, TestSetNameIncorrect) {
    ASSERT_THROW(
        post.SetName("", &user),
        std::invalid_argument
    );
    ASSERT_EQ("The problem of global warming", post.GetName());
}

TEST_F(TestPost, TestSetInfo) {
    post.SetInfo("Hello world!", &user);
    ASSERT_EQ("Hello world!", post.GetInfo());
}

TEST_F(TestPost, TestSetInfoIncorrectAuthor) {
    ASSERT_THROW(
        post.SetInfo("Hello world!", &user2),
        ExceptionAccess
    );
    ASSERT_EQ(info, post.GetInfo());
}

TEST_F(TestPost, TestSetInfoIncorrect) {
    ASSERT_THROW(
        post.SetInfo("", &user),
        std::invalid_argument
    );
    ASSERT_EQ(info, post.GetInfo());
}

TEST_F(TestPost, TestAddReaction) {
    post.AddReaction(&reaction);
    const std::string username = user2.GetUserName();
    ASSERT_EQ(&reaction, post.SeeReactionByAuthor(username));
}

TEST_F(TestPost, TestSeeReactionIncorrect) {
    post.AddReaction(&reaction);
    const std::string username = user2.GetName();
    ASSERT_THROW(
        post.SeeReactionByAuthor(username),
        std::out_of_range);
}

TEST_F(TestPost, TestRemoveReaction) {
    post.AddReaction(&reaction);
    post.RemoveReaction(user2.GetUserName());
    ASSERT_THROW(
        post.SeeReactionByAuthor(user2.GetUserName()),
        std::out_of_range);
}

TEST_F(TestPost, TestRemoveReactionIncorrect) {
    post.AddReaction(&reaction);
    ASSERT_THROW(
        post.RemoveReaction(user2.GetName()),
        std::logic_error);
    const std::string username = user2.GetUserName();
    ASSERT_EQ(&reaction, post.SeeReactionByAuthor(username));
}

TEST_F(TestPost, TestAddHashTagIncorrectAccess) {
    ASSERT_THROW(
        post.AddHashTag(&hash_tag2),
        ExceptionAccess);
}

TEST_F(TestPost, TestAddHashTagInvalidArgument) {
    post.AddHashTag(&hash_tag);
    ASSERT_THROW(
        post.AddHashTag(&hash_tag),
        std::invalid_argument);
}

TEST_F(TestPost, TestRemoveHashTag) {
    post.AddHashTag(&hash_tag);
    post.RemoveHashTag("#global", &user);
    ASSERT_THROW(
        post.RemoveHashTag("#global",&user),
        std::logic_error);
}

TEST_F(TestPost, TestRemoveHashTagincorrectAccess) {
    post.AddHashTag(&hash_tag);
    ASSERT_THROW(
        post.RemoveHashTag("#global",&user2),
        ExceptionAccess);
}

TEST_F(TestPost, TestRemoveHashTagLogicError) {
    post.AddHashTag(&hash_tag);
    ASSERT_THROW(
        post.RemoveHashTag("#globals",&user),
        std::logic_error);
}


TEST_F(TestPost, TestAddPollIncorrectAccess) {
    ASSERT_THROW(
        post.AddPoll(&poll, &user2),
        ExceptionAccess);
}

TEST_F(TestPost, TestAddPollInvalidArgument) {
    post.AddPoll(&poll, &user);
    ASSERT_THROW(
        post.AddPoll(&poll, &user),
        std::invalid_argument);
}

TEST_F(TestPost, TestRemoveIncorrectUser) {
    ASSERT_THROW(
        post.RemovePoll("The capital of Belarus", &user2),
        ExceptionAccess);
}

TEST_F(TestPost, TestRemoveLogicError) {
    post.AddPoll(&poll, &user);
    post.RemovePoll("The capital of Belarus", &user);
    ASSERT_THROW(
        post.RemovePoll("The capital of Belarus", &user),
        std::logic_error);
}
