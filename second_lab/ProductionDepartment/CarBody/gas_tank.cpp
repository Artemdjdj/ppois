#include "gas_tank.h"

GasTank::GasTank() {}

GasTank::GasTank(int percentage, std::string type_of_fuel, std::string season, int volume):volume_(volume),
fuel_(type_of_fuel, season) {
    this->percentage_of_occupancy_ = percentage;
}

bool GasTank::SetPercentageOfOccupancy(int procent) {
    return SetSinglePercent(procent, this->percentage_of_occupancy_);
}

int GasTank::GetPercentageOfOccupancy() const {
    return this->percentage_of_occupancy_;
}

int GasTank::GetVolume() const {
    return this->volume_.GetVolume();
}

std::string GasTank::GetFuel() {
    return this->fuel_.GetTypeOfFuel();
}

bool GasTank::SetVolume(int volume) {
    return this->volume_.SetVolume(volume);
}
bool GasTank::SetFuel(std::string type_of_fuel) {
    return this->fuel_.SetTypeOfFuel(type_of_fuel);
}

bool GasTank::SetSeason(std::string season) {
    return this->fuel_.SetSeason(season);
}

std::string GasTank::GetSeason() {
    return this->fuel_.GetSeason();
}
int GasTank::CheckHowMuchEmptySpace() const {
    return this->volume_.GetVolume() - GetNewValueAfterMultiplication(
        this->volume_.GetVolume(), this->percentage_of_occupancy_);
}
