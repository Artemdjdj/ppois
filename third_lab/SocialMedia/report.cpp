#include "report.h"

#include "../Utils/project_utils.h"

Report::Report(const std::string &sender, const std::string &bad_user): sender_(sender), bad_user_(bad_user) {
};

void Report::SetCause(const std::string &cause, const std::string &sender) {
    DefaultPropertySetter::SetValueWithAuthor(this->cause_, cause, this->sender_, sender, "Incorrect sender", "Cause can't be empty");
}

void Report::SetProof(const std::string &proof, const std::string &sender) {
    DefaultPropertySetter::SetValueWithAuthor(this->proof_, proof, this->sender_, sender, "Incorrect sender", "Proof can't be empty");
}

void Report::Approve() {
    this->is_approved_ = true;
}

void Report::Disapprove() {
    this->is_approved_ = false;
}

std::string Report::GetSender() const {
    return this->sender_;
}

std::string Report::GetBadUser() const {
    return this->bad_user_;
}

bool Report::IsApproved() const {
    return this->is_approved_;
}

std::string Report::GetCause() const {
    return this->cause_;
}

std::string Report::GetProof() const {
    return this->proof_;
}
