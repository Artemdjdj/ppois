
#ifndef INCLUDE_GAS_TANK_H
#define INCLUDE_GAS_TANK_H
#include "include_basic_params.h"
#include "include_fuel.h"
class GasTank {
private:
    Volume volume;
    Fuel fuel;
    int percentage_of_occupancy{0};
public:
    GasTank();
    GasTank(int percentage, std::string type_of_fuel, std::string season, int volume);
    bool set_percentage_of_occupancy(int procent);
    int get_percentage_of_occupancy() const;
    int get_volume();
    std::string get_fuel();
    bool set_volume(int volume);
    bool set_fuel(std::string type_of_fuel);
    bool set_season(std::string season);
    std::string get_season();
    int check_how_much_empty_space();
};

#endif //INCLUDE_GAS_TANK_H
