#include "notification.h"


Notification::Notification(const std::string &name, const std::string &info, User *sender,
                           User *receiver): sender_(sender), receiver_(receiver) {
    BaseInfo::SetName(name);
    BaseInfo::SetInfo(info);
    this->time_ = DefaultProjectSettings::GetRealTime();
}

void Notification::ShowNotification() {
    this->is_show_ = true;
}

void Notification::DonNotShowNotification() {
    this->is_show_ = false;
}

std::string Notification::GetTime() const {
    return this->time_;
}

User *Notification::GetSender() const {
    return this->sender_;
}

User *Notification::GetReceiver() const {
    return this->receiver_;
}

bool Notification::IsShow() const {
    return this->is_show_;
}
