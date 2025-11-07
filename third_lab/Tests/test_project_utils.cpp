#include <ranges>
#include <gtest/gtest.h>
#include "../Utils/project_utils.h"
#include "../Utils/validator.h"

TEST(TestIsStatementInAllowed, TestIsValueinAllowedFirst) {
	const std::unordered_set<std::string> allowed_values = {"blue", "white", "green"};
	ASSERT_TRUE(ValidatorString::CheckIsStatementInAllowed("blue", allowed_values));
}

TEST(TestIsStatementInAllowed, TestIsValueinAllowedSecond) {
	const std::unordered_set<std::string> allowed_values = {"blue", "white", "green"};
	ASSERT_TRUE(ValidatorString::CheckIsStatementInAllowed("white", allowed_values));
}

TEST(TestIsStatementInAllowed, TestIsValueinAllowedThird) {
	const std::unordered_set<std::string> allowed_values = {"blue", "white", "green"};
	ASSERT_TRUE(ValidatorString::CheckIsStatementInAllowed("green", allowed_values));
}

TEST(TestIsStatementInAllowed, TestIsValueinAllowedNegativeNotSuchValue) {
	const std::unordered_set<std::string> allowed_values = {"blue", "white", "green"};
	ASSERT_FALSE(ValidatorString::CheckIsStatementInAllowed("black", allowed_values));
}

TEST(TestIsStatementInAllowed, TestIsValueinAllowedNegativeBigLetter) {
	const std::unordered_set<std::string> allowed_values = {"blue", "white", "green"};
	ASSERT_FALSE(ValidatorString::CheckIsStatementInAllowed("Blue", allowed_values));
}

TEST(TestToLower, TestAllBigLetters) {
	std::string test_str = "TEST";
	StringFormatter::ToLower(test_str);
	ASSERT_EQ(test_str, "test");
}

TEST(TestToLower, TestSomeBigLetters) {
	std::string test_str = "TesT";
	StringFormatter::ToLower(test_str);
	ASSERT_EQ(test_str, "test");
}

 TEST(TestRefactor, TestInIntVector) {
	std::vector<int> test_ints = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	WorkingWithVector::RefactorElement(test_ints, 17,0);
	ASSERT_EQ(test_ints[0], 17);
}