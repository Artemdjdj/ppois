#ifndef Poll_H
#define Poll_H
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <optional>
#include "../User/user.h"


class Poll {
public:
    Poll() = default;

    Poll(const std::string &question, const std::vector<std::string> &answers);

    bool operator==(const Poll &other) const {
        return this->question_ == other.question_ and this->answers_ == other.answers_;
    }

    void SeeAnswer() const;

    void AddAnswer(int number_of_answer, const User *user);

    void SeeUserAnswer(const User *user, std::string &result) const;

    void SeeStatistics() const;

    std::optional<int> GetAuthorAndHisAnswer(const User *user, int new_answer);

    std::string GetQuestion() const;

protected:
    std::string question_;
    std::vector<std::string> answers_;
    std::map<std::string, int> statistics_;
    std::vector<std::pair<const User *, int> > users_and_their_answers_;
    int result_count_of_voices_{0};

    int GetAnswerOfUser(const User *user) const;
};

class PollWithRefactoringChoose : public Poll {
public:
    PollWithRefactoringChoose();

    PollWithRefactoringChoose(const std::string &question, const std::vector<std::string> &answers);

    void RefactorYourChoose(const User *user, int new_answer);
};

class PollWithGettingAnswer : public Poll {
public:
    PollWithGettingAnswer();

    PollWithGettingAnswer(const std::string &question, const std::vector<std::string> &answers,
                          int number_of_correct_answer);

    void AddAnswer(int number_of_answer, const User *user);

private:
    int correct_answer_;

    void SeeAnswer() const;
};
#endif //Poll_H
