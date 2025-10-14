#include "report.h"

#include "../Utils/project_utils.h"

Report::Report(User *sender, User *bad_user): sender_(sender), bad_user_(bad_user) {
};

void Report::SetCause(const std::string &cause) {
    DefaultProjectSettings::SetValue(this->cause_, cause, "Cause can't be empty!");
}

void Report::SetProof(const std::string &proof) {
    DefaultProjectSettings::SetValue(this->proof_, proof, "Proof can't be empty!");
}

void Report::Approve() {
    this->is_approved_ = true;
}

void Report::Disapprove() {
    this->is_approved_ = false;
}

User *Report::GetSender() const {
    return this->sender_;
}

User *Report::GetBadUser() const {
    return this->bad_user_;
}

bool Report::IsApproved() const {
    return this->is_approved_;
}
