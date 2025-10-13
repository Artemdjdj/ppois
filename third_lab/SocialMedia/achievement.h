#ifndef ACHIVEMENT_H
#define ACHIVEMENT_H
#include <string>
#include <vector>

class Achievement {
public:
    Achievement() = default;

    Achievement(const std::string &name, const std::string &info,
                const std::string &reward, const std::string &city);

    void SetName(const std::string &name);

    void SetInfo(const std::string &info);

    void AddCondition(const std::string &condition);

    void DeleteCondition(int number);

    void RefactorCondition(const std::string &condition, int number);

    void SetReward(const std::string &reward);

    void SetCity(const std::string &city);

    std::string GetName() const;

    std::string GetInfo() const;

    std::string GetReward() const;

    std::string GetCity() const;

    std::vector<std::string> GetConditions() const;

private:
    std::string name_;
    std::string info_;
    std::vector<std::string> conditions_;
    std::string reward_;
    std::string city_;
};
#endif //ACHIVEMENT_H
