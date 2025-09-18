
#ifndef SEASON_H
#define SEASON_H
#include <iostream>
#include <string>
#include <vector>

class Season {
private:
    std::string season;
    void set_season_private(std::string season);
    // bool check_is_correct_season(std::string& season);
public:
    Season();
    Season(std::string season);
    bool set_season(std::string season);
    std::string get_season();
};
#endif //SEASON_H
