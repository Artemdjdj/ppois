#include "basic_params.h"
#include "speedometer.h"

DefaultSpeedometer::DefaultSpeedometer() = default;

DefaultSpeedometer::DefaultSpeedometer(int speed, int mileage):
speed_(speed), mileage_(mileage){}

int DefaultSpeedometer::GetSpeed() const {
    return this->speed_;
}

int DefaultSpeedometer::GetMileage() const {
    return this->mileage_;
}

SpeedometerInKilometers::SpeedometerInKilometers():DefaultSpeedometer(){}

SpeedometerInKilometers::SpeedometerInKilometers(int speed, int mileage):DefaultSpeedometer(speed, mileage){}

bool SpeedometerInKilometers::SetSpeed(int speed) {
    return SetSingleValue(speed, "The speed should be bigger then zero!", this->speed_);
}

bool SpeedometerInKilometers::SetMileage(int mileage) {
    return SetSingleValue(mileage, "The mileage should be bigger then zero!", this->mileage_);
}

SpeedometerInMiles::SpeedometerInMiles():DefaultSpeedometer(){}

SpeedometerInMiles::SpeedometerInMiles(int speed, int mileage):DefaultSpeedometer(static_cast<int>(speed * 0.6), static_cast<int>(mileage * 0.6)){}

bool SpeedometerInMiles::SetSpeed(int speed) {
    return SetSingleValue(static_cast<int>(speed * 0.6), "The speed should be bigger then zero!", this->speed_);
}

bool SpeedometerInMiles::SetMileage(int mileage) {
    return SetSingleValue(static_cast<int>(mileage * 0.6), "The mileage should be bigger then zero!", this->mileage_);
}

