#include "basic_params.h"
#include "../../Exceptions/exceptions.h"
#include "wheel.h"
#include <iostream>

Wheel::Wheel(): radius_(), brake_shoe_() {}

Wheel::Wheel(int radius, int height, int width, std::string material, int count_of_bolts): radius_(radius), brake_shoe_(height, width, material) {
    this->count_of_bolts_ = count_of_bolts;
}

bool Wheel::SetCountOfBolts(int count_of_bolts) {
    return SetSingleValue(count_of_bolts,"Count of bolts can't be smaller the null!", this->count_of_bolts_);
}

int Wheel::GetCountOfBolts() const {
    return count_of_bolts_;
}

bool Wheel::SetRadius(int radius) {
    return this->radius_.SetRadius(radius);
}

int Wheel::GetRadius() const {
    return this->radius_.GetRadius();
}

bool Wheel::SetMaterial(std::string material) {
    return this->brake_shoe_.SetMaterial(material);
}

bool Wheel::SetColor(std::string color) {
    return this->brake_shoe_.SetColor(color);
}

bool Wheel::SetSize(int height, int width) {
    return this->brake_shoe_.SetSize(height, width);
}

std::string Wheel::GetTypeOfMaterialToBrakeShoe() {
    return this->brake_shoe_.GetMaterial();
}

