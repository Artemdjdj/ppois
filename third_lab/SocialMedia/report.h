#ifndef REPORT_H
#define REPORT_H
#include "../User/user.h"

class Report {
public:
    Report(const std::string &sender, const std::string& bad_user);

    void SetCause(const std::string &cause, const std::string &sender);

    void SetProof(const std::string &proof, const std::string &sender);

    void Approve();

    void Disapprove();

    std::string GetSender() const;

    std::string GetBadUser() const;

    bool IsApproved() const;

    std::string GetCause() const;

    std::string GetProof() const;

private:
    std::string sender_;
    std::string bad_user_;
    std::string cause_;
    std::string proof_;
    bool is_approved_{false};
};
#endif //REPORT_H
