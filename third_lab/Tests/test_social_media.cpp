#include <gtest/gtest.h>
#include "../SocialMedia/reaction.h"
#include "../SocialMedia/hash_tag.h"

class TestReaction : public testing::Test {
public:
	void SetUp() override {
		reaction = Reaction();
		hash_tag = HashTag();
	}

	User user = User("@Artemdjdj", "hello world");
	HashTag hash_tag;
	Reaction reaction;
};

TEST_F(TestReaction, TestReactionConstructorWithParams) {
	auto new_reaction = Reaction("like", &user);
	ASSERT_EQ("like", new_reaction.GetReaction());
}

TEST_F(TestReaction, TestReactionConstructorWithParamsNegative) {
	auto new_reaction = Reaction("likss", &user);
	ASSERT_EQ("", new_reaction.GetReaction());
}

TEST_F(TestReaction, TestSetReactionSomeLetterInUpperCase) {
	reaction.SetReaction("LiKe", &user);
	ASSERT_EQ("like", reaction.GetReaction());
}

TEST_F(TestReaction, TestSetReactionUpperCase) {
	reaction.SetReaction("LIKE", &user);
	ASSERT_EQ("like", reaction.GetReaction());
}

TEST_F(TestReaction, TestSeeReactionAuthor) {
	reaction.SetReaction("LIKE", &user);
	ASSERT_EQ("@Artemdjdj", reaction.SeeAuthor());
}

TEST_F(TestReaction, TestHashTagConstructorWithParams) {
	const auto new_hash_tag = HashTag("#legend", &user);
	ASSERT_EQ("#legend", new_hash_tag.GetHashTag());
}

TEST_F(TestReaction, TestHashTagConstructorWithParamsNegative) {
	const auto new_hash_tag = HashTag("likss", &user);
	ASSERT_EQ("", new_hash_tag.GetHashTag());
}

TEST_F(TestReaction, TestSetHashTag) {
	hash_tag.SetHashTag("#Like", &user);
	ASSERT_EQ("#Like", hash_tag.GetHashTag());
}

TEST_F(TestReaction, TestSetCorrectHashTag) {
	hash_tag.SetHashTag("#Tik-Tok", &user);
	ASSERT_EQ("#Tik-Tok", hash_tag.GetHashTag());
}

TEST_F(TestReaction, TestSetIncorrectHashTagLength) {
	hash_tag.SetHashTag(
		"#sjgljsljglsdjglkjslkgjlsjdlkjslkjglksjglkjslkgjlksdjgljsdklgjlkdsjgl"
		"kjdskgjlsdjglfjsfljsdlfjs", &user);
	ASSERT_EQ("", hash_tag.GetHashTag());
}

TEST_F(TestReaction, TestSetHashTagIncorrectSymbols) {
	hash_tag.SetHashTag("#Like_-", &user);
	ASSERT_EQ("", hash_tag.GetHashTag());
}

TEST_F(TestReaction, TestSetHashTagIncorrect) {
	hash_tag.SetHashTag("LIKE", &user);
	ASSERT_EQ("", hash_tag.GetHashTag());
}

TEST_F(TestReaction, TestSetHashTagIncorrectSymbol1) {
	hash_tag.SetHashTag("#like!", &user);
	ASSERT_EQ("", hash_tag.GetHashTag());
}

TEST_F(TestReaction, TestSetHashTagIncorrectSymbol2) {
	hash_tag.SetHashTag("#like$", &user);
	ASSERT_EQ("", hash_tag.GetHashTag());
}

TEST_F(TestReaction, TestSeeHashTagAuthor) {
	hash_tag.SetHashTag("#LIKE", &user);
	ASSERT_EQ("@Artemdjdj", hash_tag.SeeAuthor());
}
