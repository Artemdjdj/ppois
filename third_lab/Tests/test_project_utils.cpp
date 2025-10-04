#include <ranges>
#include <gtest/gtest.h>
#include "../Utils/project_utils.h"

TEST(TestIsStatementInAllowed, TestIsValueinAllowedFirst) {
	const std::unordered_set<std::string> allowed_values = {"blue", "white", "green"};
	ASSERT_TRUE(DefaultProjectSettings::CheckIsStatementInAllowed("blue", allowed_values));
}

TEST(TestIsStatementInAllowed, TestIsValueinAllowedSecond) {
	const std::unordered_set<std::string> allowed_values = {"blue", "white", "green"};
	ASSERT_TRUE(DefaultProjectSettings::CheckIsStatementInAllowed("white", allowed_values));
}

TEST(TestIsStatementInAllowed, TestIsValueinAllowedThird) {
	const std::unordered_set<std::string> allowed_values = {"blue", "white", "green"};
	ASSERT_TRUE(DefaultProjectSettings::CheckIsStatementInAllowed("green", allowed_values));
}

TEST(TestIsStatementInAllowed, TestIsValueinAllowedNegativeNotSuchValue) {
	const std::unordered_set<std::string> allowed_values = {"blue", "white", "green"};
	ASSERT_FALSE(DefaultProjectSettings::CheckIsStatementInAllowed("black", allowed_values));
}

TEST(TestIsStatementInAllowed, TestIsValueinAllowedNegativeBigLetter) {
	const std::unordered_set<std::string> allowed_values = {"blue", "white", "green"};
	ASSERT_FALSE(DefaultProjectSettings::CheckIsStatementInAllowed("Blue", allowed_values));
}

TEST(TestToLower, TestAllBigLetters) {
	std::string test_str = "TEST";
	DefaultProjectSettings::ToLower(test_str);
	ASSERT_EQ(test_str, "test");
}

TEST(TestToLower, TestSomeBigLetters) {
	std::string test_str = "TesT";
	DefaultProjectSettings::ToLower(test_str);
	ASSERT_EQ(test_str, "test");
}