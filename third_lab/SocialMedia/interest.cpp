#include "interest.h"

Interest::Interest(const std::string &name, const std::string &info, const std::string &duration, int level) {
    BaseInfo::SetName(name);
    BaseInfo::SetInfo(info);
    SetDuration(duration);
    SetLevel(level);
}

void Interest::SetDuration(const std::string &duration) {
    this->duration_ = duration;
}

std::string Interest::GetDuration(const std::string &duration) {
    return this->duration_ = duration;
}

void Interest::SetLevel(int level) {
    if (level < 1 or level > 10) {
        throw ExceptionIncorrectLevelOfInterest("Incorrect level of interest");
    }
    this->level_ = level;
}

int Interest::GetLevel() const {
    return this->level_;
}
