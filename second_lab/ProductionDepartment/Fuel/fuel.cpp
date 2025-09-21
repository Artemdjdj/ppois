#include <string>
#include "fuel.h"
#include "basic_params.h"
#include "settings.h"
#include "../Exceptions/exceptions.h"
Fuel::Fuel() {}
Fuel::Fuel(std::string type_of_fuel, std::string season):season_(season) {
    this->type_of_fuel_ = type_of_fuel;
}
void Fuel::SetTypeOfFuelPrivate(std::string type_of_fuel) {
    ToLower(type_of_fuel);
    if (!CheckIsStatementCorrect(type_of_fuels, type_of_fuel)) {
        throw ExceptionIncorrectFuel("This is incorrect type of fuel");
    }
    this->type_of_fuel_ = type_of_fuel;
}

bool Fuel::SetTypeOfFuel(std::string type_of_fuel) {
    try {
        SetTypeOfFuelPrivate(type_of_fuel);
        return true;
    }
    catch (const ExceptionIncorrectFuel& e) {
        LogToFile(e.what());
        return false;
    }
    catch (const std::exception& e) {
        LogToFile(e.what());
        return false;
    }
}

bool Fuel::SetSeason(std::string season) {
    return this->season_.SetSeason(season);
}

std::string Fuel::GetTypeOfFuel() {
    return this->type_of_fuel_;
}

std::string Fuel::GetSeason() {
    return this->season_.GetSeason();
}