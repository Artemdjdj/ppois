#include "gas_tank.h"

GasTank::GasTank(int percentage, const Fuel &type_of_fuel, const Volume &volume) {
    this->fuel_ = type_of_fuel;
    this->volume_ = volume;
    this->percentage_of_occupancy_ = percentage;
}

void GasTank::SetPercentageOfOccupancy(int procent) {
    CarSetter::SetSinglePercent(procent, this->percentage_of_occupancy_);
}

int GasTank::GetPercentageOfOccupancy() const {
    return this->percentage_of_occupancy_;
}

int GasTank::GetVolume() const {
    return this->volume_.GetVolume();
}

std::string GasTank::GetFuel() const {
    return this->fuel_.GetTypeOfFuel();
}

void GasTank::SetVolume(const Volume &volume) {
    this->volume_ = volume;
}

void GasTank::SetFuel(const Fuel &type_of_fuel) {
    this->fuel_ = type_of_fuel;
}

void GasTank::SetSeason(const std::string &season) {
    this->fuel_.SetSeason(season);
}

void GasTank::SetMechanicalIndicator(bool is_mechanical_indicator) {
    this->is_mechanical_indicator_ = is_mechanical_indicator;
}

std::string GasTank::GetSeason() const {
    return this->fuel_.GetSeason();
}

int GasTank::CheckHowMuchEmptySpace() const {
    return this->volume_.GetVolume() - MathOperations::GetNewValueAfterMultiplication(
               this->volume_.GetVolume(), this->percentage_of_occupancy_);
}

bool GasTank::CheckIsMechanicalIndicator() const {
    return this->is_mechanical_indicator_;
}

std::string GasTank::CheckIsGasTankBig() const {
    int volume = this->volume_.GetVolume();
    if (volume <= kSmallVolumeOfGasTank) {
        return "small";
    } else if (volume > kSmallVolumeOfGasTank && volume <= kNormalVolumeOfGasTank) {
        return "normal";
    }
    return "big";
}
