
#include "include_basic_params.h"
#include "include_exceptions.h"
#include "include_wheel.h"
#include <iostream>
using namespace std;

Wheel::Wheel(): radius(), brake_shoe() {}

Wheel::Wheel(int radius, int height, int width, string material, string color, int count_of_bolts): radius(radius), brake_shoe(height, width, material, color) {
    this->count_of_bolts = count_of_bolts;
}

void Wheel::set_count_of_bolts_private(int count) {
    if (count <0) {
        throw ExceptionIncorrectSize("Count of bolts can't be smaller the null!");
    }
    this->count_of_bolts =count;
}

bool Wheel::set_count_of_bolts(int count_of_bolts) {
    try {
        set_count_of_bolts_private(count_of_bolts);
        return true;
    }
    catch (const ExceptionIncorrectSize & e) {
        log_to_file(e.what());
        return false;
    }
    catch (const Exception & e) {
        log_to_file(e.what());
        return false;
    }
}

int Wheel::get_count_of_bolts() {
    return count_of_bolts;
}

void Wheel::set_radius_private(int radius) {
    if (radius<0) {
        throw ExceptionIncorrectSize("Radius of wheel can't be negative number!");
    }
    this->radius = radius;
}

bool Wheel::set_radius(int radius) {
    try {
        set_radius_private(radius);
        return true;
    }
    catch (const ExceptionIncorrectSize& e) {
        log_to_file(e.what());
        return false;
    }
    catch (const Exception & e) {
        log_to_file(e.what());
        return false;
    }
}

int Wheel::get_radius() {
    return this->radius.getRadius();
}

bool Wheel::set_material(string material) {
    return this->brake_shoe.set_material(material);
}

bool Wheel::set_color(string color) {
    return this->brake_shoe.set_color(color);
}

bool Wheel::set_size(int height, int width) {
    return this->brake_shoe.set_size(height, width);
}

string Wheel::get_type_of_material_to_brake_shoe() {
    return this->brake_shoe.get_material();
}

