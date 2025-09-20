#include "tube.h"

Tube::Tube() = default;

Tube::Tube(int radius, int height):radius(radius), height(height){}

bool Tube::set_radius(int radius) {
    return this->radius.set_radius(radius);
}

bool Tube::set_height(int height) {
    return set_single_value(height, "Height should be bigger then zero!", this->height);
}

int Tube::get_radius() const {
    return this->radius.get_radius();
}
int Tube::get_height() const {
    return this->height;
}


