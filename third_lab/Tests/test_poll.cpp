#include <gtest/gtest.h>
#include <sstream>
#include "exceptions.h"
#include "../SocialMedia/poll.h"
#include "../User/user.h"

class TestAllTypesOfPoll : public::testing::Test {
public:
    void SetUp() override {
        poll_without_refactoring_choose = Poll("The capital of Belarus",
                                                                       (std::vector<std::string>{
                                                                           "Minsk", "Washington", "Moscow"
                                                                       }), user);
        poll_with_refactoring_choose = PollWithRefactoringChoose("The capital of Russia",
                                                                 (std::vector<std::string>{
                                                                     "Minsk", "Washington", "Moscow"
                                                                 }), user);
        poll_with_getting_answer = PollWithGettingAnswer("The capital of USA",
                                                         (std::vector<std::string>{
                                                             "Minsk", "Washington", "Moscow"
                                                         }), 2, user);
        poll_with_refactoring_choose.AddAnswer(1, user);
    }

    std::shared_ptr<User>user = std::make_shared<User>("@Artemdjdj", "252352353");
    std::shared_ptr<User>user2 = std::make_shared<User>("@Eugen2007", "fshdjkfhsk4343");
    Poll poll_without_refactoring_choose;
    PollWithRefactoringChoose poll_with_refactoring_choose;
    PollWithGettingAnswer poll_with_getting_answer;
};

TEST_F(TestAllTypesOfPoll, TestOperatorEqPollWithoutRefactoringFalse) {
    auto poll_without_refactoring_choose2 = Poll("The result of 2+2",
                                                                       (std::vector<std::string>{
                                                                           "1", "2", "4"
                                                                       }), user);
    ASSERT_FALSE(poll_without_refactoring_choose2 == poll_without_refactoring_choose);
}

TEST_F(TestAllTypesOfPoll, TestOperatorEqPollWithoutRefactoringTrue) {
    auto poll_without_refactoring_choose2 = Poll("The capital of Belarus",
                                                                       (std::vector<std::string>{
                                                                           "Minsk", "Washington", "Moscow"
                                                                       }), user);
    ASSERT_TRUE(poll_without_refactoring_choose2 == poll_without_refactoring_choose);
}

TEST_F(TestAllTypesOfPoll, TestOperatorEqPollWithoRefactoringFalse) {
    auto poll_with_refactoring_choose2 = PollWithRefactoringChoose("The result of 2+2",
                                                                       (std::vector<std::string>{
                                                                           "1", "2", "4"
                                                                       }), user);
    ASSERT_FALSE(poll_with_refactoring_choose2 == poll_with_refactoring_choose);
}

TEST_F(TestAllTypesOfPoll, TestOperatorEqPollWithRefactoringTrue) {
    auto poll_with_refactoring_choose2 = PollWithRefactoringChoose("The capital of Russia",
                                                                 (std::vector<std::string>{
                                                                     "Minsk", "Washington", "Moscow"
                                                                 }), user);
    ASSERT_TRUE(poll_with_refactoring_choose2 == poll_with_refactoring_choose);
}

TEST_F(TestAllTypesOfPoll, TestOperatorEqPollWithGettingFalse) {
    auto poll_with_getting_answer2 = PollWithGettingAnswer("The result of 2+2",
                                                                       (std::vector<std::string>{
                                                                           "1", "2", "4"
                                                                       }),3, user);
    ASSERT_FALSE(poll_with_getting_answer2 == poll_with_refactoring_choose);
}

TEST_F(TestAllTypesOfPoll, TestOperatorEqPollPollWithGettingTrue) {
    auto poll_with_getting_answer2 = PollWithGettingAnswer("The capital of USA",
                                                         (std::vector<std::string>{
                                                             "Minsk", "Washington", "Moscow"
                                                         }), 2, user);
    ASSERT_TRUE(poll_with_getting_answer2 == poll_with_getting_answer);
}

TEST_F(TestAllTypesOfPoll, TestAddAnswer) {
    poll_without_refactoring_choose.AddAnswer(1, user);
    std::string result;
    poll_without_refactoring_choose.SeeUserAnswer(user, result);
    ASSERT_EQ("Minsk", result);
}

TEST_F(TestAllTypesOfPoll, TestAddAnswerIncorrectNumber) {
    ASSERT_THROW(poll_without_refactoring_choose.AddAnswer(66,user),
                 ExceptionIncorrectNumber);
    std::string result;
    poll_without_refactoring_choose.SeeUserAnswer(user, result);
    ASSERT_EQ("", result);
}

TEST_F(TestAllTypesOfPoll, TestAddAnswerIncorrectUser) {
    ASSERT_THROW(
        poll_with_refactoring_choose.AddAnswer(1,user),
        ExceptionUserExist);
}

TEST_F(TestAllTypesOfPoll, TestAddRefactoringPoll) {
    poll_with_refactoring_choose.AddAnswer(2, user2);
    std::string result;
    poll_with_refactoring_choose.SeeUserAnswer(user2, result);
    ASSERT_EQ("Washington", result);
}

TEST_F(TestAllTypesOfPoll, TestAddAnswerIncorrectForRefactoringPoll) {
    ASSERT_THROW(poll_with_refactoring_choose.AddAnswer(-1,user2),
                 ExceptionIncorrectNumber);
    std::string result;
    poll_with_refactoring_choose.SeeUserAnswer(user2, result);
    ASSERT_EQ("", result);
}

TEST_F(TestAllTypesOfPoll, TestGetAuthorAndHisAnswer) {
    ASSERT_EQ(1, poll_with_refactoring_choose.GetAuthorAndHisAnswer(user,2).value());
}

TEST_F(TestAllTypesOfPoll, TestGetAuthorAndHisAnswerNegative) {
    ASSERT_EQ(std::nullopt, poll_with_refactoring_choose.GetAuthorAndHisAnswer(user2,2));
}

TEST_F(TestAllTypesOfPoll, TestRefactorAnswer) {
    std::string result;
    poll_with_refactoring_choose.SeeUserAnswer(user, result);
    ASSERT_EQ("Minsk", result);
    poll_with_refactoring_choose.RefactorYourChoose(user, 2);
    poll_with_refactoring_choose.SeeUserAnswer(user, result);
    ASSERT_EQ("Washington", result);
}

TEST_F(TestAllTypesOfPoll, TestRefactorAnswerIncorrectNewAnswerBig) {
    ASSERT_THROW(
        poll_with_refactoring_choose.RefactorYourChoose(user, 6),
        ExceptionIncorrectNumber);
}

TEST_F(TestAllTypesOfPoll, TestRefactorAnswerIncorrectNewAnswerSmallerThenZero) {
    ASSERT_THROW(
        poll_with_refactoring_choose.RefactorYourChoose(user, -1),
        ExceptionIncorrectNumber);
}

TEST_F(TestAllTypesOfPoll, TestRefactorAnswerIncorrectAuthor) {
    ASSERT_THROW(
        poll_with_refactoring_choose.RefactorYourChoose(user2, 1),
        ExceptionAccess);
}

TEST_F(TestAllTypesOfPoll, TestAddAnswerToPollWithGettingAnswerSmallerThenZero) {
    ASSERT_THROW(
        poll_with_getting_answer.AddAnswer(-11, user),
        ExceptionIncorrectNumber);
}

TEST_F(TestAllTypesOfPoll, TestAddAnswerToPollWithGettingAnswerSoBig) {
    ASSERT_THROW(
        poll_with_getting_answer.AddAnswer(11, user),
        ExceptionIncorrectNumber);
}

TEST_F(TestAllTypesOfPoll, TestAddAnswerToPollWithGettingAnswerUserExists) {
    poll_with_getting_answer.AddAnswer(1, user);
    ASSERT_THROW(
        poll_with_getting_answer.AddAnswer(1, user),
        ExceptionUserExist);
}

TEST_F(TestAllTypesOfPoll, TestGettingAnswers) {
    poll_with_getting_answer.AddAnswer(1, user);
    ASSERT_EQ(3,poll_with_getting_answer.SeeAnswers().size());
}

// TEST_F(TestAllTypesOfPoll, AddGettingAnswer) {
//     std::stringstream buffer;
//     std::streambuf *oldCout = std::cout.rdbuf();
//     std::cout.rdbuf(buffer.rdbuf());
//     poll_with_getting_answer.AddAnswer(1, &user);
//     std::cout.rdbuf(oldCout);
//     const std::string expected_cout =
//             "The answers on this question: The capital of USA\n\n\x1B[36m1) Minsk\x1B[0m\n\x1B[32m2) Washington\x1B[0m\n\x1B[36m3) Moscow\x1B[0m";
//     ASSERT_EQ(expected_cout, buffer.str());
// }
