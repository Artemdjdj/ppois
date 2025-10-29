#include "basic_params.h"
#include "../../Exceptions/exceptions.h"
#include "wheel.h"
#include <iostream>

Wheel::Wheel(const int radius, const int height, const int width, const std::string &material, const int count_of_bolts,
             const Color &color) : radius_(radius), brake_shoe_(height, width, material, color) {
    SetCountOfBolts(count_of_bolts);
}

void Wheel::SetCountOfBolts(const int count_of_bolts) {
    CarSetter::SetSingleValue(count_of_bolts, "Count of bolts can't be smaller the null!", this->count_of_bolts_);
}

int Wheel::GetCountOfBolts() const {
    return count_of_bolts_;
}

void Wheel::SetRadius(const int radius) {
    this->radius_.SetRadius(radius);
}

int Wheel::GetRadius() const {
    return this->radius_.GetRadius();
}

void Wheel::SetMaterial(const std::string &material) {
    this->brake_shoe_.SetMaterial(material);
}

void Wheel::SetColor(const Color &color) {
    this->brake_shoe_.SetColor(color);
}

void Wheel::SetSize(const int height, const int width) {
    this->brake_shoe_.SetSize(height, width);
}

std::string Wheel::GetTypeOfMaterialToBrakeShoe() {
    return this->brake_shoe_.GetMaterial();
}
