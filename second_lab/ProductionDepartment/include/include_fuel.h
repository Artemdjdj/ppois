
#ifndef INCLUDE_FUEL_H
#define INCLUDE_FUEL_H
#include <string>
#include "include_season.h"

class Fuel {
private:
    std::string type_of_fuel;
    Season season;
    void set_type_of_fuel_private(std::string type_of_fuel);
public:
    Fuel();
    Fuel(std::string type_of_fuel, std::string season);
    bool set_type_of_fuel(std::string type_of_fuel);
    bool set_season(std::string season);
    std::string get_type_of_fuel();
    std::string get_season();
};

#endif
