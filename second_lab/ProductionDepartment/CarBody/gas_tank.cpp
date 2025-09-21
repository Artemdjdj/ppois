#include "gas_tank.h"

GasTank::GasTank() {}

GasTank::GasTank(int percentage, std::string type_of_fuel, std::string season, int volume):volume(volume),
fuel(type_of_fuel, season) {
    this->percentage_of_occupancy = percentage;
}

bool GasTank::set_percentage_of_occupancy(int procent) {
    return set_single_procent(procent, this->percentage_of_occupancy);
}

int GasTank::get_percentage_of_occupancy() const {
    return this->percentage_of_occupancy;
}

int GasTank::get_volume() {
    return this->volume.get_volume();
}

std::string GasTank::get_fuel() {
    return this->fuel.get_type_of_fuel();
}

bool GasTank::set_volume(int volume) {
    return this->volume.set_volume(volume);
}
bool GasTank::set_fuel(std::string type_of_fuel) {
    return this->fuel.set_type_of_fuel(type_of_fuel);
}

bool GasTank::set_season(std::string season) {
    return this->fuel.set_season(season);
}

std::string GasTank::get_season() {
    return this->fuel.get_season();
}
int GasTank::check_how_much_empty_space() {
    return this->volume.get_volume() - get_new_value_after_multiplication(
        this->volume.get_volume(), this->percentage_of_occupancy);
}