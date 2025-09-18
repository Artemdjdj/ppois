#include "include_wheel.h"
#include "include_basic_params.h"

bool BaseCircle::set_radius(int radius) {
    return set_single_value(radius, "Radius of wheel can't be negative number!", this->radius);
}

int BaseCircle::get_radius() {
    return this->radius;
}
