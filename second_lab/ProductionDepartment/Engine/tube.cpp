#include "tube.h"
#include <cmath>

#include "../../Exceptions/exceptions.h"

Tube::Tube() = default;

Tube::Tube(const int radius, const int height) : radius_(BaseCircle(radius)), height_(height) {
}

void Tube::SetRadius(const int radius) {
    if (radius < 0) {
        throw ExceptionIncorrectSize("Incorrect radius of tube");
    }
    this->radius_.SetRadius(radius);
}

void Tube::SetHeight(const int height) {
    if (height < 0) {
        throw ExceptionIncorrectSize("Incorrect height of tube");
    }
    this->height_ = height;
}

void Tube::SetManufacturer(const std::string &manufacturer) {
    this->manufacturer_ = manufacturer;
}

void Tube::SetMaxPressure(const int max_pressure) {
    if (max_pressure < 0) {
        throw ExceptionRuntimeError("Incorrect max pressure");
    }
    this->max_pressure_ = max_pressure;
}

void Tube::SetFlexibility(const bool is_flexible) {
    this->is_flexible_ = is_flexible;
}

void Tube::SetOperatingTemperature(const int temperature) {
    this->operating_temperature_ = temperature;
}

void Tube::SetLifespan(const int life_span) {
    if (life_span < 0) {
        throw ExceptionRuntimeError("Incorrect life span");
    }
    this->life_span_ = life_span;
}

void Tube::SetWallThickness(const int thickness) {
    if (thickness < 0) {
        throw ExceptionRuntimeError("Incorrect thickness");
    }
    this->thickness_ = thickness;
}

int Tube::GetRadius() const {
    return radius_.GetRadius();
}

int Tube::GetHeight() const {
    return height_;
}

std::string Tube::GetManufacturer() const {
    return this->manufacturer_;
}

int Tube::GetMaxPressure() const {
    return this->max_pressure_;
}

bool Tube::IsFlexible() const {
    return this->is_flexible_;
}

int Tube::GetOperatingTemperature() const {
    return this->operating_temperature_;
}

int Tube::GetLifespan() const {
    return this->life_span_;
}

int Tube::GetWallThickness() const {
    return this->thickness_;
}
