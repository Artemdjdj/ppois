#include <gtest/gtest.h>
#include "../SocialMedia/reaction.h"

class TestReaction : public testing::Test{
public:
	void SetUp() override {
		reaction  = Reaction();
	}
	Reaction reaction;
};

TEST_F(TestReaction, TestReactionConstructorWithParams) {
	auto new_reaction = Reaction("like");
	ASSERT_EQ("like", new_reaction.GetReaction());
}

TEST_F(TestReaction, TestReactionConstructorWithParamsNegative) {
	auto new_reaction = Reaction("likss");
	ASSERT_EQ("", new_reaction.GetReaction());
}

TEST_F(TestReaction, TestSetReactionSomeLetterInUpperCase) {
	reaction.SetReaction("LiKe");
	ASSERT_EQ("like", reaction.GetReaction());
}

TEST_F(TestReaction, TestSetReactionUpperCase) {
	reaction.SetReaction("LIKE");
	ASSERT_EQ("like", reaction.GetReaction());
}

TEST_F(TestReaction, TestDeleteReaction) {
	auto new_reaction = Reaction("like");
	ASSERT_EQ("like", new_reaction.GetReaction());
	new_reaction.DeleteReaction();
	ASSERT_EQ("", new_reaction.GetReaction());
}

