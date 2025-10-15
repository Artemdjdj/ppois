#ifndef INTEREST_H
#define INTEREST_H
#include <string>
#include "../Utils/project_utils.h"

class Interest : public Info {
public:
    Interest() = default;

    Interest(const std::string &name, const std::string &info, const std::string &duration, int level);

    void SetDuration(const std::string &duration);

    std::string GetDuration();

    void SetLevel(int level);

    int GetLevel() const;

private:
    std::string duration_;
    int level_;
};

#endif //INTEREST_H
