#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include "../User/user.h"
#include "../Utils/project_utils.h"

class Notification final : public Info {
public:
    Notification(const std::string &name, const std::string &info, const std::string &sender, const std::string &receiver);

    void ShowNotification();

    void DoNotShowNotification();

    std::string GetTime() const;

    std::string GetSender() const;

    std::string GetReceiver() const;

    bool IsShow() const;

private:
    std::string sender_;
    std::string receiver_;
    std::string time_;
    bool is_show_{true};
};
#endif //NOTIFICATION_H
