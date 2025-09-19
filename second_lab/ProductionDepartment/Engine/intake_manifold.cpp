#include "include_intake_manifold.h"
#include <cmath>
#include "include_exceptions.h"
#include <iostream>

IntakeManifold::IntakeManifold()=default;

IntakeManifold::IntakeManifold(int main_volume, int radius_canal, int height_canal, int number_of_canals):main_volume(main_volume), canal(radius_canal, height_canal) {
    this->number_of_canals = number_of_canals;
}

bool IntakeManifold::set_main_volume(int volume) {
    return this->main_volume.set_volume(volume);
}

void IntakeManifold::set_plenum_volume() {
    this->plenum_volume.set_volume(static_cast<int>(this->main_volume.get_volume() * 0.7));
}

bool IntakeManifold::set_height_canal(int height_canal) {
    return this->canal.set_height(height_canal);
}

bool IntakeManifold::set_number_of_canals(int number_of_canals) {
    return set_single_value(number_of_canals, "The number of canals can't be negative or zero!", this->number_of_canals);
}

int IntakeManifold::get_number_of_canals() const {
    return this->number_of_canals;
}

int IntakeManifold::get_radius_canal() const {
    return this->canal.get_radius();
}

int IntakeManifold::get_height_canal() const {
    return this->canal.get_height();
}

bool IntakeManifold::set_radius_canal(int radius_canal) {
    return this->canal.set_radius(radius_canal);
}

int IntakeManifold::get_plenum_volume() const {
    return this->plenum_volume.get_volume();
}

void IntakeManifold::checking_volume() const {
    if (get_plenum_volume()<=0) {
        throw ExceptionIncorrectVolume("Incorrect volume!");
    }
}

std::optional<double>  IntakeManifold::calculate_response_frequency(double temperature) const {
    try {
        checking_volume();
        double speed = calculate_the_speed_of_sound_in_special_temperature(temperature);
        return std::optional<double>(speed/(2*M_PI*pow(plenum_volume.get_volume()*canal.get_height()*pow(10, -6),0.5)));
    }
    catch (const ExceptionIncorrectVolume& e){
        log_to_file(e.what());
        return std::nullopt;
    }
    catch (const Exception & e) {
        log_to_file(e.what());
        return std::nullopt;
    }
}
