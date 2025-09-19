#include "include_basic_params.h"
#include "include_speedometer.h"

DefaultSpeedometer::DefaultSpeedometer() = default;

DefaultSpeedometer::DefaultSpeedometer(int speed, int mileage):
speed(speed), mileage(mileage){}

int DefaultSpeedometer::get_speed() const {
    return this->speed;
}

int DefaultSpeedometer::get_mileage() const {
    return this->mileage;
}

SpeedometerInKilometers::SpeedometerInKilometers():DefaultSpeedometer(){}

SpeedometerInKilometers::SpeedometerInKilometers(int speed, int mileage):DefaultSpeedometer(speed, mileage){}

bool SpeedometerInKilometers::set_speed(int speed) {
    return set_single_value(speed, "The speed should be bigger then zero!", this->speed);
}

bool SpeedometerInKilometers::set_mileage(int mileage) {
    return set_single_value(mileage, "The mileage should be bigger then zero!", this->mileage);
}

SpeedometerInMiles::SpeedometerInMiles():DefaultSpeedometer(){}

SpeedometerInMiles::SpeedometerInMiles(int speed, int mileage):DefaultSpeedometer(static_cast<int>(speed * 0.6), static_cast<int>(mileage * 0.6)){}

bool SpeedometerInMiles::set_speed(int speed) {
    return set_single_value(static_cast<int>(speed * 0.6), "The speed should be bigger then zero!", this->speed);
}

bool SpeedometerInMiles::set_mileage(int mileage) {
    return set_single_value(static_cast<int>(mileage * 0.6), "The mileage should be bigger then zero!", this->mileage);
}

