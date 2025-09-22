#include "intake_manifold.h"
#include <cmath>
#include "../../Exceptions/exceptions.h"
#include <iostream>

IntakeManifold::IntakeManifold() = default;

IntakeManifold::IntakeManifold(int main_volume, int radius_canal, int height_canal,
								int number_of_canals): main_volume_(main_volume), canal_(radius_canal, height_canal) {
	this->number_of_canals_ = number_of_canals;
}

bool IntakeManifold::SetMainVolume(int volume) {
	return this->main_volume_.SetVolume(volume);
}

void IntakeManifold::SetPlenumVolume() {
	this->plenum_volume_.SetVolume(static_cast<int>(this->main_volume_.GetVolume() * 0.7));
}

bool IntakeManifold::SetHeightCanal(int height_canal) {
	return this->canal_.SetHeight(height_canal);
}

bool IntakeManifold::SetNumberOfCanals(int number_of_canals) {
	return SetSingleValue(number_of_canals, "The number of canals can't be negative or zero!", this->number_of_canals_);
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

bool IntakeManifold::SetRadiusCanal(int radius_canal) {
	return this->canal_.SetRadius(radius_canal);
}

int IntakeManifold::GetPlenumVolume() const {
	return this->plenum_volume_.GetVolume();
}

void IntakeManifold::CheckingVolume() const {
	if (GetPlenumVolume() <= 0) {
		throw ExceptionIncorrectVolume("Incorrect volume!");
	}
}

std::optional<double> IntakeManifold::CalculateResponseFrequency(double temperature) const {
	try {
		CheckingVolume();
		double speed = CalculateTheSpeedOfSoundInSpecialTemperature(temperature);
		return std::optional<double>(
			speed / (2 * M_PI * pow(plenum_volume_.GetVolume() * canal_.GetHeight() * pow(10, -6), 0.5)));
	} catch (const ExceptionIncorrectVolume &e) {
		LogToFile(e.what(), PATH_TO_FILE);
		return std::nullopt;
	}
	catch (const Exception &e) {
		LogToFile(e.what(), PATH_TO_FILE);
		return std::nullopt;
	}
}
