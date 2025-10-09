#include "wheel.h"
#include "basic_params.h"

BaseCircle::BaseCircle(int radius): radius_(radius) {}

void BaseCircle::SetRadius(int radius) {
    SetSingleValue(radius, "Radius of wheel can't be negative number!", this->radius_);
}

int BaseCircle::GetRadius() const {
    return this->radius_;
}
