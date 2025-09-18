
#include "include_basic_params.h"
#include "include_exceptions.h"
#include "include_wheel.h"
#include <iostream>

Wheel::Wheel(): radius(), brake_shoe() {}

Wheel::Wheel(int radius, int height, int width, std::string material, std::string color, int count_of_bolts): radius(radius), brake_shoe(height, width, material, color) {
    this->count_of_bolts = count_of_bolts;
}

bool Wheel::set_count_of_bolts(int count_of_bolts) {
    return set_single_value(count_of_bolts,"Count of bolts can't be smaller the null!", this->count_of_bolts);
}

int Wheel::get_count_of_bolts() {
    return count_of_bolts;
}

bool Wheel::set_radius(int radius) {
    return this->radius.set_radius(radius);
}

int Wheel::get_radius() {
    return this->radius.get_radius();
}

bool Wheel::set_material(std::string material) {
    return this->brake_shoe.set_material(material);
}

bool Wheel::set_color(std::string color) {
    return this->brake_shoe.set_color(color);
}

bool Wheel::set_size(int height, int width) {
    return this->brake_shoe.set_size(height, width);
}

std::string Wheel::get_type_of_material_to_brake_shoe() {
    return this->brake_shoe.get_material();
}

