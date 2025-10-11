#include <gtest/gtest.h>

#include "exceptions.h"
#include "../SocialMedia/poll.h"
#include "../User/user.h"

class TestAllTypesOfPoll : public::testing::Test {
public:
    void SetUp() override {
        poll_without_refactoring_choose = PollWithoutRefactoringChoose("The capital of Belarus",
                                                                       (std::vector<std::string>{
                                                                           "Minsk", "Washington", "Moscow"
                                                                       }));
        poll_with_refactoring_choose = PollWithRefactoringChoose("The capital of Russia",
                                                                 (std::vector<std::string>{
                                                                     "Minsk", "Washington", "Moscow"
                                                                 }));
        poll_with_getting_answer = PollWithGettingAnswer("The capital of USA",
                                                         (std::vector<std::string>{
                                                             "Minsk", "Washington", "Moscow"
                                                         }), 2);
        poll_with_refactoring_choose.AddAnswer(1, &user);
    }

    User user = User("@Artemdjdj", "252352353");
    User user2 = User("@Eugen2007", "fshdjkfhsk4343");
    PollWithoutRefactoringChoose poll_without_refactoring_choose;
    PollWithRefactoringChoose poll_with_refactoring_choose;
    PollWithGettingAnswer poll_with_getting_answer;
};

TEST_F(TestAllTypesOfPoll, TestAddAnswer) {
    poll_without_refactoring_choose.AddAnswer(1, &user);
    std::string result;
    poll_without_refactoring_choose.SeeUserAnswer(&user, result);
    ASSERT_EQ("Minsk", result);
}

TEST_F(TestAllTypesOfPoll, TestAddAnswerIncorrectNumber) {
    ASSERT_THROW(poll_without_refactoring_choose.AddAnswer(66,&user),
                 ExceptionIncorrectNumber);
    std::string result;
    poll_without_refactoring_choose.SeeUserAnswer(&user, result);
    ASSERT_EQ("", result);
}

TEST_F(TestAllTypesOfPoll, TestAddAnswerIncorrectUser) {
    ASSERT_THROW(
        poll_with_refactoring_choose.AddAnswer(1,&user),
        ExceptionUserExist);
}

TEST_F(TestAllTypesOfPoll, TestAddRefactoringPoll) {
    poll_with_refactoring_choose.AddAnswer(2, &user2);
    std::string result;
    poll_with_refactoring_choose.SeeUserAnswer(&user2, result);
    ASSERT_EQ("Washington", result);
}

TEST_F(TestAllTypesOfPoll, TestAddAnswerIncorrectForRefactoringPoll) {
    ASSERT_THROW(poll_with_refactoring_choose.AddAnswer(-1,&user2),
                 ExceptionIncorrectNumber);
    std::string result;
    poll_with_refactoring_choose.SeeUserAnswer(&user2, result);
    ASSERT_EQ("", result);
}

TEST_F(TestAllTypesOfPoll, TestGetAuthorAndHisAnswer) {
    ASSERT_EQ(1, poll_with_refactoring_choose.GetAuthorAndHisAnswer(&user,2).value());
}

TEST_F(TestAllTypesOfPoll, TestGetAuthorAndHisAnswerNegative) {
    ASSERT_EQ(std::nullopt, poll_with_refactoring_choose.GetAuthorAndHisAnswer(&user2,2));
}

TEST_F(TestAllTypesOfPoll, TestRefactorAnswer) {
    std::string result;
    poll_with_refactoring_choose.SeeUserAnswer(&user, result);
    ASSERT_EQ("Minsk", result);
    poll_with_refactoring_choose.RefactorYourChoose(&user, 2);
    poll_with_refactoring_choose.SeeUserAnswer(&user, result);
    ASSERT_EQ("Washington", result);
}

TEST_F(TestAllTypesOfPoll, TestRefactorAnswerIncorrectNewAnswerBig) {
    ASSERT_THROW(
        poll_with_refactoring_choose.RefactorYourChoose(&user, 6),
        ExceptionIncorrectNumber);
}

TEST_F(TestAllTypesOfPoll, TestRefactorAnswerIncorrectNewAnswerSmallerThenZero) {
    ASSERT_THROW(
        poll_with_refactoring_choose.RefactorYourChoose(&user, -1),
        ExceptionIncorrectNumber);
}

TEST_F(TestAllTypesOfPoll, TestRefactorAnswerIncorrectAuthor) {
    ASSERT_THROW(
        poll_with_refactoring_choose.RefactorYourChoose(&user2, 1),
        ExceptionAccess);
}
