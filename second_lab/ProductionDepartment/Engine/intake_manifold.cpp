#include "intake_manifold.h"
#include <cmath>
#include "../../Exceptions/exceptions.h"
#include <iostream>

IntakeManifold::IntakeManifold() = default;

IntakeManifold::IntakeManifold(int main_volume, int radius_canal, int height_canal,
								int number_of_canals): main_volume_(main_volume), canal_(radius_canal, height_canal) {
	this->number_of_canals_ = number_of_canals;
}

void IntakeManifold::SetMainVolume(int volume) {
	this->main_volume_.SetVolume(volume);
}

void IntakeManifold::SetPlenumVolume() {
	this->plenum_volume_.SetVolume(static_cast<int>(this->main_volume_.GetVolume() * 0.7));
}

void IntakeManifold::SetHeightCanal(int height_canal) {
	this->canal_.SetHeight(height_canal);
}

void IntakeManifold::SetNumberOfCanals(int number_of_canals) {
	SetSingleValue(number_of_canals, "The number of canals can't be negative or zero!", this->number_of_canals_);
}

int IntakeManifold::GetNumberOfCanals() const {
	return this->number_of_canals_;
}

int IntakeManifold::GetRadiusCanal() const {
	return this->canal_.GetRadius();
}

int IntakeManifold::GetHeightCanal() const {
	return this->canal_.GetHeight();
}

void IntakeManifold::SetRadiusCanal(int radius_canal) {
	this->canal_.SetRadius(radius_canal);
}

int IntakeManifold::GetPlenumVolume() const {
	return this->plenum_volume_.GetVolume();
}

std::optional<double> IntakeManifold::CalculateResponseFrequency(double temperature) const {
	if (GetPlenumVolume() <= 0) {
		return std::nullopt;
	}
	double speed = CalculateTheSpeedOfSoundInSpecialTemperature(temperature);
	return std::optional<double>(
		speed / (2 * M_PI * pow(plenum_volume_.GetVolume() * canal_.GetHeight() * pow(10, -6), 0.5)));
}
