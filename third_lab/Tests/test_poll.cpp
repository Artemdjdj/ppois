#include <gtest/gtest.h>
#include "../SocialMedia/poll.h"
#include "../User/user.h"

class TestAllTypesOfPoll:public::testing::Test {
public:
	void SetUp() override {
		poll_without_refactoring_choose = PollWithoutRefactoringChoose("The capital of Belarus", (std::vector<std::string>{"Minsk", "Washington", "Moscow"}));
		poll_with_refactoring_choose = PollWithRefactoringChoose("The capital of Russia", (std::vector<std::string>{"Minsk", "Washington", "Moscow"}));
		poll_with_getting_answer = PollWithGettingAnswer("The capital of USA", (std::vector<std::string>{"Minsk", "Washington", "Moscow"}), 2);
	}

	User user = User("@Artemdjdj", "252352353");
	PollWithoutRefactoringChoose poll_without_refactoring_choose;
	PollWithRefactoringChoose poll_with_refactoring_choose;
	PollWithGettingAnswer poll_with_getting_answer;
};

TEST_F(TestAllTypesOfPoll, TestAddAnswer) {
	poll_without_refactoring_choose.AddAnswer(1,&user);
	std::string result;
	poll_without_refactoring_choose.SeeUserAnswer(&user, result);
	ASSERT_EQ("Minsk", result);
}

TEST_F(TestAllTypesOfPoll, TestAddAnswerIncorrect) {
	poll_without_refactoring_choose.AddAnswer(66,&user);
	std::string result;
	poll_without_refactoring_choose.SeeUserAnswer(&user, result);
	ASSERT_EQ("", result);
}


