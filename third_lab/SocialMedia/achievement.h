#ifndef ACHIVEMENT_H
#define ACHIVEMENT_H
#include <string>
#include <vector>
#include "../Utils/project_utils.h"

class Achievement : public Info {
public:
    Achievement() = default;

    Achievement(const std::string &name, const std::string &info,
                const std::string &reward, const std::string &city);

    void AddCondition(const std::string &condition);

    void DeleteCondition(int number);

    void RefactorCondition(const std::string &condition, int number);

    void SetReward(const std::string &reward);

    void SetCity(const std::string &city);

    std::string GetReward() const;

    std::string GetCity() const;

    std::vector<std::string> GetConditions() const;

private:
    std::vector<std::string> conditions_;
    std::string reward_;
    std::string city_;
};
#endif //ACHIVEMENT_H
