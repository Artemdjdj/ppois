#include <gtest/gtest.h>
#include "../SocialMedia/reaction.h"
#include "../SocialMedia/hash_tag.h"
#include "../Exceptions/exceptions.h"

class TestReaction : public testing::Test {
public:
	void SetUp() override {
		reaction = Reaction();
		hash_tag = HashTag();
	}
	User author = User("@Artemdjdj", "hello6546world");
	std::string user = author.GetUsername();
	HashTag hash_tag;
	Reaction reaction;
};

TEST_F(TestReaction, TestReactionConstructorWithParams) {
	auto new_reaction = Reaction("like", user);
	ASSERT_EQ("like", new_reaction.GetReaction());
}

TEST_F(TestReaction, TestReactionConstructorWithParamsNegative) {
	ASSERT_THROW(
		Reaction("likss", user),
		ExceptionIncorrectReaction
	);
}

TEST_F(TestReaction, TestSetReactionSomeLetterInUpperCase) {
	reaction.SetReaction("LiKe", user);
	ASSERT_EQ("like", reaction.GetReaction());
}

TEST_F(TestReaction, TestSetReactionUpperCase) {
	reaction.SetReaction("LIKE", user);
	ASSERT_EQ("like", reaction.GetReaction());
}

TEST_F(TestReaction, TestSeeReactionAuthor) {
	reaction.SetReaction("LIKE", user);
	ASSERT_EQ("@Artemdjdj", reaction.SeeAuthor());
}

TEST_F(TestReaction, TestHashTagConstructorWithParams) {
	const auto new_hash_tag = HashTag("#legend", user);
	ASSERT_EQ("#legend", new_hash_tag.GetHashTag());
}

TEST_F(TestReaction, TestHashTagConstructorWithParamsNegative) {
	ASSERT_THROW(
		HashTag("likss", user),
		ExceptionIncorrectHashTag
	);
}

TEST_F(TestReaction, TestSetHashTag) {
	hash_tag.SetHashTag("#Like", user);
	ASSERT_EQ("#Like", hash_tag.GetHashTag());
}

TEST_F(TestReaction, TestSetCorrectHashTag) {
	hash_tag.SetHashTag("#Tik-Tok", user);
	ASSERT_EQ("#Tik-Tok", hash_tag.GetHashTag());
}

TEST_F(TestReaction, TestSetIncorrectHashTagLength) {
	ASSERT_THROW(
		hash_tag.SetHashTag(
			"#sjgljsljglsdjglkjslkgjlsjdlkjslkjglksjglkjslkgjlksdjgljsdklgjlkdsjgl"
			"kjdskgjlsdjglfjsfljsdlfjs", user),
		ExceptionIncorrectHashTag
	);
}

TEST_F(TestReaction, TestSetHashTagIncorrectSymbols) {
	ASSERT_THROW(
		hash_tag.SetHashTag("#Like_-", user),
		ExceptionIncorrectHashTag
	);
}

TEST_F(TestReaction, TestSetHashTagIncorrect) {
	ASSERT_THROW(
		hash_tag.SetHashTag("LIKE", user),
		ExceptionIncorrectHashTag
	);
}

TEST_F(TestReaction, TestSetHashTagIncorrectSymbol1) {
	ASSERT_THROW(
		hash_tag.SetHashTag("#like!", user),
		ExceptionIncorrectHashTag
	);
}

TEST_F(TestReaction, TestSetHashTagIncorrectSymbol2) {
	ASSERT_THROW(
		hash_tag.SetHashTag("#like$", user),
		ExceptionIncorrectHashTag
	);
}

TEST_F(TestReaction, TestSeeHashTagAuthor) {
	hash_tag.SetHashTag("#LIKE", user);
	ASSERT_EQ("@Artemdjdj", hash_tag.SeeAuthor());
}
