#ifndef REPORT_H
#define REPORT_H
#include "../User/user.h"

class Report {
public:
    Report(const std::shared_ptr<User> &sender, const std::shared_ptr<User>& bad_user);

    void SetCause(const std::string &cause, const std::shared_ptr<User> &sender);

    void SetProof(const std::string &proof, const std::shared_ptr<User> &sender);

    void Approve();

    void Disapprove();

    std::shared_ptr<User> GetSender() const;

    std::shared_ptr<User> GetBadUser() const;

    bool IsApproved() const;

    std::string GetCause() const;

    std::string GetProof() const;

private:
    std::weak_ptr<User> sender_;
    std::weak_ptr<User> bad_user_;
    std::string cause_;
    std::string proof_;
    bool is_approved_{false};
};
#endif //REPORT_H
