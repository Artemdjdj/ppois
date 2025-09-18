#include <string>
#include "include_fuel.h"
#include "include_basic_params.h"
#include "settings.h"
#include "include_exceptions.h"
Fuel::Fuel() {}
Fuel::Fuel(std::string type_of_fuel, std::string season):season(season) {
    this->type_of_fuel = type_of_fuel;
}
void Fuel::set_type_of_fuel_private(std::string type_of_fuel) {
    ToLower(type_of_fuel);
    if (!check_is_statement_correct(type_of_fuels, type_of_fuel)) {
        throw ExceptionIncorrectFuel("This is incorrect type of fuel");
    }
    this->type_of_fuel = type_of_fuel;
}

bool Fuel::set_type_of_fuel(std::string type_of_fuel) {
    try {
        set_type_of_fuel_private(type_of_fuel);
        return true;
    }
    catch (const ExceptionIncorrectFuel& e) {
        log_to_file(e.what());
        return false;
    }
    catch (const std::exception& e) {
        log_to_file(e.what());
        return false;
    }
}

bool Fuel::set_season(std::string season) {
    return this->season.set_season(season);
}

std::string Fuel::get_type_of_fuel() {
    return this->type_of_fuel;
}

std::string Fuel::get_season() {
    return this->season.get_season();
}