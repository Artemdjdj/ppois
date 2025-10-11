#include "poll.h"
#include <iostream>

#include "exceptions.h"
#include "../Utils/project_utils.h"

PollWithoutRefactoringChoose::PollWithoutRefactoringChoose() = default;

PollWithoutRefactoringChoose::PollWithoutRefactoringChoose(const std::string &question,
															const std::vector<std::string> &
															answers): question_(question), answers_(answers) {
}

int PollWithoutRefactoringChoose::GetAnswerOfUser(const User *user) const {
	for (const auto &answer: this->users_and_their_answers_) {
		if (answer.first == user) {
			return answer.second;
		}
	}
	return -1;
}

void PollWithoutRefactoringChoose::SeeAnswer() const {
	std::cout << "The answers on this question:" << " " << this->question_ << std::endl;
	int index = 1;
	for (const auto &answer: this->answers_) {
		std::cout << std::endl << index << ")" << answer;
		index++;
	}
}

void PollWithoutRefactoringChoose::AddAnswer(int number_of_answer, const User *user) {
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

void PollWithoutRefactoringChoose::SeeUserAnswer(const User *user, std::string &result) const {
	const int number_of_answer = GetAnswerOfUser(user);
	if (number_of_answer == -1) {
		DefaultProjectSettings::LogFile("You do not have any answer!", main_log_file);
		return;
	}
	result = answers_[number_of_answer - 1];
}

std::optional<int> PollWithoutRefactoringChoose::GetAuthorAndHisAnswer(const User *user, int new_answer) {
	for (auto &pair: this->users_and_their_answers_) {
		if (user == pair.first) {
			int old_answer = pair.second;
			pair.second = new_answer;
			return old_answer;
		}
	}
	return std::nullopt;
}

void PollWithoutRefactoringChoose::SeeStatistics() const {
	std::cout << "The result of PollWithoutRefactoringChoose!" << std::endl;
	for (const auto &answer: statistics_) {
		std::cout << std::endl << answer.first << " --- " << static_cast<double>(
			answer.second * 100 / result_count_of_voices_) << "%" << std::endl;
	}
}

PollWithRefactoringChoose::PollWithRefactoringChoose() = default;

PollWithRefactoringChoose::PollWithRefactoringChoose(const std::string &question,
													const std::vector<std::string> &
													answers): PollWithoutRefactoringChoose(question, answers) {
}

void PollWithRefactoringChoose::RefactorYourChoose(const User *user, int new_answer) {
	if (new_answer > answers_.size() or new_answer < 1) {
		throw ExceptionIncorrectNumber("Incorrect answer, such answer is not in list of answers");
	}
	auto old_answer = GetAuthorAndHisAnswer(user, new_answer);
	if (old_answer == std::nullopt) {
		throw ExceptionAccess("Such user doesn't have any answers!");
	}
	const std::string old_answer_str = this->answers_[old_answer.value()- 1];
	const std::string new_answer_str = this->answers_[new_answer - 1];
	this->statistics_[old_answer_str]--;
	this->statistics_[new_answer_str]++;
}

PollWithGettingAnswer::PollWithGettingAnswer() = default;

PollWithGettingAnswer::PollWithGettingAnswer(const std::string &question, const std::vector<std::string> &answers,
											int number_of_correct_answer): PollWithoutRefactoringChoose(
																				question, answers),
																			correct_answer_(number_of_correct_answer) {
}

void PollWithGettingAnswer::AddAnswer(int number_of_answer, const User *user) {
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
	SeeAnswer();
}

void PollWithGettingAnswer::SeeAnswer() const {
	std::cout << "The answers on this question:" << " " << this->question_ << std::endl;
	int index = 1;
	for (const auto &answer: this->answers_) {
		if (index == this->correct_answer_)
			std::cout << std::endl << GREEN << index << ")" << answer << RESET;
		else {
			std::cout << std::endl << CYAN << index << ")" << answer << RESET;
		}
		index++;
	}
}
