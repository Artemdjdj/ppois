#ifndef PollWithoutRefactoringChoose_H
#define PollWithoutRefactoringChoose_H
#include <map>
#include <string>
#include <utility>
#include <vector>
#include "../User/user.h"

class PollWithoutRefactoringChoose {
public:
	PollWithoutRefactoringChoose();

	PollWithoutRefactoringChoose(const std::string &question, const std::vector<std::string> &answers);

	void SeeAnswer() const;

	void AddAnswer(int number_of_answer, const User *user);

	void SeeUserAnswer(const User *user, std::string &result) const;

	void SeeStatistics() const;

protected:
	std::string question_;
	std::vector<std::string> answers_;
	std::map<std::string, int> statistics_;
	std::vector<std::pair<const User *, int> > users_and_their_answers_;
	int result_count_of_voices_{0};

	int GetAnswerOfUser(const User *user) const;
};

class PollWithRefactoringChoose : public PollWithoutRefactoringChoose {
public:
	PollWithRefactoringChoose();

	PollWithRefactoringChoose(const std::string &question, const std::vector<std::string> &answers);

	void RefactorYourChoose(const User *user, int new_answer);
};

class PollWithGettingAnswer : public PollWithoutRefactoringChoose {
public:
	PollWithGettingAnswer();

	PollWithGettingAnswer(const std::string &question, const std::vector<std::string> &answers,int number_of_correct_answer);

	void AddAnswer(int number_of_answer, const User *user);

private:
	int correct_answer_;

	void SeeAnswer() const;
};
#endif //PollWithoutRefactoringChoose_H
