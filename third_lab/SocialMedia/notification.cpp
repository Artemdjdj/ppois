#include "notification.h"


Notification::Notification(const std::string &name, const std::string &info, const std::shared_ptr<User> &sender,
                           const std::shared_ptr<User> &receiver): sender_(sender), receiver_(receiver) {
    Info::SetName(name);
    Info::SetInfo(info);
    this->time_ = DefaultProjectSettings::GetRealTime();
}

void Notification::ShowNotification() {
    this->is_show_ = true;
}

void Notification::DoNotShowNotification() {
    this->is_show_ = false;
}

std::string Notification::GetTime() const {
    return this->time_;
}

std::shared_ptr<User> Notification::GetSender() const {
    return this->sender_.lock();
}

std::shared_ptr<User> Notification::GetReceiver() const {
    return this->receiver_.lock();
}

bool Notification::IsShow() const {
    return this->is_show_;
}
