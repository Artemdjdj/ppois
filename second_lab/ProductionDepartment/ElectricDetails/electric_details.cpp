#include "basic_params.h"
#include "electric_details.h"

ElectroPart::ElectroPart()=default;

ElectroPart::ElectroPart(int voltage, int power, int current_strength):
voltage(voltage),power(power),current_strength(current_strength){}

bool ElectroPart::set_voltage(int voltage) {
    return set_single_value(voltage, "Voltage in electro part can't be smaller then zero!", this->voltage);
}

bool ElectroPart::set_power(int power) {
    return set_single_value(power, "Power in electro part can't be smaller then zero!", this->power);
}

bool ElectroPart::set_current_strength(int strength) {
    return set_single_value(strength, "Current strength in electro part can't be smaller then zero!", this->current_strength);
}

int ElectroPart::get_voltage() const {
    return this->voltage;
}

int ElectroPart::get_power() const {
    return this->power;
}

int ElectroPart::get_current_strength() const {
    return this->current_strength;
}

Starter::Starter(){};

Starter::Starter(int voltage, int power, int current_strength, bool is_left_direction, int count_of_prong):
ElectroPart(voltage, power, current_strength), is_left_direction(is_left_direction), count_of_prong(count_of_prong){}

void Starter::choose_right_direction() {
    this->is_left_direction = false;
}

void Starter::choose_left_direction() {
    this->is_left_direction = true;
}

bool Starter::set_count_of_prog(int count_of_prong) {
    return set_single_value(count_of_prong, "Count of prong can't be negative or zero!", this->count_of_prong);
}

int Starter::get_count_of_prog() const {
    return this->count_of_prong;
}

bool Starter::get_direction() const {
    return this->is_left_direction;
}

Battery::Battery(){};

Battery::Battery(int voltage, int power, int current_strength, int cold_cranking_current):
ElectroPart(voltage, power, current_strength), cold_cranking_current(cold_cranking_current){}

bool Battery::set_cold_cranking_current(int cold_cranking_current) {
    return set_single_value(cold_cranking_current, "The cold cranking current can't be negative or zero!", this->cold_cranking_current);
}

int Battery::get_cold_cranking_current() const {
    return this->cold_cranking_current;
}
