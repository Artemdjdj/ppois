#include "achievement.h"

#include <stdexcept>

#include "../Utils/project_utils.h"

Achievement::Achievement(const std::string &name, const std::string &info, const std::string &reward, const std::string &city) {
    BaseInfo::SetName(name);
    BaseInfo::SetInfo(info);
    SetReward(reward);
    SetCity(city);
}



void Achievement::AddCondition(const std::string &condition) {
    DefaultWorkingWithVector::AddElementToVector(this->conditions_, condition);
}

void Achievement::DeleteCondition(const int number) {
    DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->conditions_, number);
}

void Achievement::RefactorCondition(const std::string &condition, const int number) {
    DefaultWorkingWithVector::RefactorElement(this->conditions_, condition, number);
}

void Achievement::SetReward(const std::string &reward) {
    DefaultProjectSettings::SetValue(this->reward_, reward,
                                               "You can't set reward of your achievement empty");
}

void Achievement::SetCity(const std::string &city) {
    DefaultProjectSettings::SetValue(this->city_, city,
                                               "You can't city reward of your achievement empty");
}

std::string Achievement::GetReward() const {
    return this->reward_;
}

std::string Achievement::GetCity() const {
    return this->city_;
}

std::vector<std::string> Achievement::GetConditions() const {
    return this->conditions_;
}

