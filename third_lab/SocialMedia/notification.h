#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include "../User/user.h"
#include "../Utils/project_utils.h"

class Notification final : public Info {
public:
    Notification(const std::string &name, const std::string &info, const std::shared_ptr<User> &sender, const std::shared_ptr<User> &receiver);

    void ShowNotification();

    void DoNotShowNotification();

    std::string GetTime() const;

    std::shared_ptr<User> GetSender() const;

    std::shared_ptr<User> GetReceiver() const;

    bool IsShow() const;

private:
    std::weak_ptr<User> sender_;
    std::weak_ptr<User> receiver_;
    std::string time_;
    bool is_show_{true};
};
#endif //NOTIFICATION_H
