#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include "../User/user.h"
#include "../Utils/project_utils.h"

class Notification : public BaseInfo {
public:
    Notification(const std::string &name, const std::string &info, User *sender, User *receiver);

    void ShowNotification();

    void DonNotShowNotification();

    std::string GetTime() const;

    User *GetSender() const;

    User *GetReceiver() const;

    bool IsShow() const;

private:
    User *sender_;
    User *receiver_;
    std::string time_;
    bool is_show_{true};
};
#endif //NOTIFICATION_H
