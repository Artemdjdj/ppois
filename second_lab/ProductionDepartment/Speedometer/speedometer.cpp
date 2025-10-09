#include "basic_params.h"
#include "speedometer.h"

DefaultSpeedometer::DefaultSpeedometer() = default;

DefaultSpeedometer::DefaultSpeedometer(int speed, int mileage): speed_(speed), mileage_(mileage) {
}

int DefaultSpeedometer::GetSpeed() const {
	return this->speed_;
}

int DefaultSpeedometer::GetMileage() const {
	return this->mileage_;
}

SpeedometerInKilometers::SpeedometerInKilometers(): DefaultSpeedometer() {
}

SpeedometerInKilometers::SpeedometerInKilometers(int speed, int mileage): DefaultSpeedometer(speed, mileage) {
}

void SpeedometerInKilometers::SetSpeed(int speed) {
	SetSingleValue(speed, "The speed should be bigger then zero!", this->speed_);
}

void SpeedometerInKilometers::SetMileage(int mileage) {
	SetSingleValue(mileage, "The mileage should be bigger then zero!", this->mileage_);
}

SpeedometerInMiles::SpeedometerInMiles(): DefaultSpeedometer() {
}

SpeedometerInMiles::SpeedometerInMiles(int speed, int mileage): DefaultSpeedometer(
	static_cast<int>(speed * 0.6), static_cast<int>(mileage * 0.6)) {
}

void SpeedometerInMiles::SetSpeed(int speed) {
	SetSingleValue(static_cast<int>(speed * 0.6), "The speed should be bigger then zero!", this->speed_);
}

void SpeedometerInMiles::SetMileage(int mileage) {
	SetSingleValue(static_cast<int>(mileage * 0.6), "The mileage should be bigger then zero!", this->mileage_);
}
