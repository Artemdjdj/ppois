#ifndef REPORT_H
#define REPORT_H
#include "../User/user.h"

class Report {
public:
    Report(User *sender, User *bad_user);

    void SetCause(const std::string &cause);

    void SetProof(const std::string &proof);

    void Approve();

    void Disapprove();

    User *GetSender() const;

    User *GetBadUser() const;

    bool IsApproved() const;

private:
    User *sender_;
    User *bad_user_;
    std::string cause_;
    std::string proof_;
    bool is_approved_{false};
};
#endif //REPORT_H
