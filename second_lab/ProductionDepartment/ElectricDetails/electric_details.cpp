#include "basic_params.h"
#include "electric_details.h"

ElectroPart::ElectroPart()=default;

ElectroPart::ElectroPart(int voltage, int power, int current_strength):
voltage_(voltage),power_(power),current_strength_(current_strength){}

bool ElectroPart::SetVoltage(int voltage) {
    return SetSingleValue(voltage, "Voltage in electro part can't be smaller then zero!", this->voltage_);
}

bool ElectroPart::SetPower(int power) {
    return SetSingleValue(power, "Power in electro part can't be smaller then zero!", this->power_);
}

bool ElectroPart::SetCurrentStrength(int strength) {
    return SetSingleValue(strength, "Current strength in electro part can't be smaller then zero!", this->current_strength_);
}

int ElectroPart::GetVoltage() const {
    return this->voltage_;
}

int ElectroPart::GetPower() const {
    return this->power_;
}

int ElectroPart::GetCurrentStrength() const {
    return this->current_strength_;
}

Starter::Starter(){};

Starter::Starter(int voltage, int power, int current_strength, bool is_left_direction, int count_of_prong):
ElectroPart(voltage, power, current_strength), is_left_direction_(is_left_direction), count_of_prong_(count_of_prong){}

void Starter::ChooseRightDirection() {
    this->is_left_direction_ = false;
}

void Starter::ChooseLeftDirection() {
    this->is_left_direction_ = true;
}

bool Starter::SetCountOfProg(int count_of_prong) {
    return SetSingleValue(count_of_prong, "Count of prong can't be negative or zero!", this->count_of_prong_);
}

int Starter::GetCountOfProg() const {
    return this->count_of_prong_;
}

bool Starter::GetDirection() const {
    return this->is_left_direction_;
}

Battery::Battery(){};

Battery::Battery(int voltage, int power, int current_strength, int cold_cranking_current):
ElectroPart(voltage, power, current_strength), cold_cranking_current_(cold_cranking_current){}

bool Battery::SetColdCrankingCurrent(int cold_cranking_current) {
    return SetSingleValue(cold_cranking_current, "The cold cranking current can't be negative or zero!", this->cold_cranking_current_);
}

int Battery::GetColdCrankingCurrent() const {
    return this->cold_cranking_current_;
}
