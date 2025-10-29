#include "wheel.h"
#include "basic_params.h"

BaseCircle::BaseCircle(const int radius) {
    SetRadius(radius);
}

void BaseCircle::SetRadius(const int radius) {
    CarSetter::SetSingleValue(radius, "Radius of wheel can't be negative number!", this->radius_);
}

int BaseCircle::GetRadius() const {
    return this->radius_;
}
