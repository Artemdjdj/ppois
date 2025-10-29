#include "notification.h"


Notification::Notification(const std::string &name, const std::string &info, const std::string &sender,
                           const std::string &receiver): sender_(sender), receiver_(receiver) {
    Info::SetName(name);
    Info::SetInfo(info);
    this->time_ = TimeProvider::GetRealTime();
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

std::string Notification::GetSender() const {
    return this->sender_;
}

std::string Notification::GetReceiver() const {
    return this->receiver_;
}

bool Notification::IsShow() const {
    return this->is_show_;
}
