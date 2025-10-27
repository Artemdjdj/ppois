#include "gas_tank.h"

GasTank::GasTank() = default;

GasTank::GasTank(int percentage, const std::string& type_of_fuel, const std::string& season, int volume): volume_(volume),
	fuel_(type_of_fuel, season) {
	this->percentage_of_occupancy_ = percentage;
}

void GasTank::SetPercentageOfOccupancy(int procent) {
	SetSinglePercent(procent, this->percentage_of_occupancy_);
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

void GasTank::SetVolume(int volume) {
	this->volume_.SetVolume(volume);
}

void GasTank::SetFuel(const std::string& type_of_fuel) {
	this->fuel_.SetTypeOfFuel(type_of_fuel);
}

void GasTank::SetSeason(const std::string& season) {
	this->fuel_.SetSeason(season);
}

void GasTank::SetMechanicalIndicator(bool is_mechanical_indicator){
    this->is_mechanical_indicator_ = is_mechanical_indicator;
}

std::string GasTank::GetSeason() {
	return this->fuel_.GetSeason();
}

int GasTank::CheckHowMuchEmptySpace() const {
	return this->volume_.GetVolume() - GetNewValueAfterMultiplication(
				this->volume_.GetVolume(), this->percentage_of_occupancy_);
}

bool GasTank::CheckIsMechanicalIndicator() const {
    return this->is_mechanical_indicator_;
}
