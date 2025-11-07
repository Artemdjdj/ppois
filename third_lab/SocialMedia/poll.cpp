#include "poll.h"
#include <iostream>

#include "exceptions.h"
#include "../Utils/project_utils.h"

Poll::Poll(const std::string &question,
           const std::vector<std::string> &
           answers, const std::string &user): question_(question), answers_(answers), author_(user) {
}

int Poll::GetAnswerOfUser(const std::string &user) const {
    for (const auto &answer: this->users_and_their_answers_) {
        if (answer.first == user) {
            return answer.second;
        }
    }
    return -1;
}

void Poll::AddAnswer(int number_of_answer, std::string user) {
    if (number_of_answer > answers_.size() or number_of_answer < 1) {
        throw ExceptionIncorrectNumber("Incorrect answer, such answer is not in list of answers");
    }
    if (GetAnswerOfUser(user) != -1) {
        throw ExceptionUserExist("User already voted!");
    }
    const std::string answer = answers_[number_of_answer - 1];
    statistics_[answer]++;
    result_count_of_voices_++;
    users_and_their_answers_.emplace_back(user, number_of_answer);
}

void Poll::SeeUserAnswer(const std::string &user, std::string &result) const {
    const int number_of_answer = GetAnswerOfUser(user);
    if (number_of_answer == -1) {
        throw Exception("You do not have any answer!");
    }
    result = answers_[number_of_answer - 1];
}

std::optional<int> Poll::GetAuthorAndHisAnswer(const std::string &user, const int new_answer) {
    for (auto &pair: this->users_and_their_answers_) {
        if (user == pair.first) {
            int old_answer = pair.second;
            pair.second = new_answer;
            return old_answer;
        }
    }
    return std::nullopt;
}

std::string Poll::GetQuestion() const {
    return this->question_;
}

PollWithRefactoringChoose::PollWithRefactoringChoose(const std::string &question,
                                                     const std::vector<std::string> &
                                                     answers, const std::string &user): Poll(question, answers, user) {
}

void PollWithRefactoringChoose::RefactorYourChoose(const std::string &user, const int new_answer) {
    if (new_answer > answers_.size() or new_answer < 1) {
        throw ExceptionIncorrectNumber("Incorrect answer, such answer is not in list of answers");
    }
    const auto old_answer = GetAuthorAndHisAnswer(user, new_answer);
    if (old_answer == std::nullopt) {
        throw ExceptionAccess("Such user doesn't have any answers!");
    }
    const std::string old_answer_str = this->answers_[old_answer.value() - 1];
    const std::string new_answer_str = this->answers_[new_answer - 1];
    this->statistics_[old_answer_str]--;
    this->statistics_[new_answer_str]++;
}

PollWithGettingAnswer::PollWithGettingAnswer(const std::string &question, const std::vector<std::string> &answers,
                                             const int number_of_correct_answer, const std::string &user): Poll(
        question, answers, user),
    correct_answer_(number_of_correct_answer) {
}

void PollWithGettingAnswer::AddAnswer(int number_of_answer, std::string user) {
    if (number_of_answer > answers_.size() or number_of_answer < 1) {
        throw ExceptionIncorrectNumber("Incorrect answer, such answer is not in list of answers");
    }
    if (GetAnswerOfUser(user) != -1) {
        throw ExceptionUserExist("User already voted!");
    }
    const std::string answer = answers_[number_of_answer - 1];
    statistics_[answer]++;
    result_count_of_voices_++;
    users_and_their_answers_.emplace_back(user, number_of_answer);
}

std::vector<std::string> PollWithGettingAnswer::SeeAnswers() const {
    return this->answers_;
}

