#include "basic_params.h"
#include "../../Exceptions/exceptions.h"
#include "wheel.h"
#include <iostream>

Wheel::Wheel(): radius_(), brake_shoe_() {}

Wheel::Wheel(int radius, int height, int width, std::string material, int count_of_bolts): radius_(radius), brake_shoe_(height, width, material) {
    this->count_of_bolts_ = count_of_bolts;
}

void Wheel::SetCountOfBolts(int count_of_bolts) {
    SetSingleValue(count_of_bolts,"Count of bolts can't be smaller the null!", this->count_of_bolts_);
}

int Wheel::GetCountOfBolts() const {
    return count_of_bolts_;
}

void Wheel::SetRadius(int radius) {
    this->radius_.SetRadius(radius);
}

int Wheel::GetRadius() const {
    return this->radius_.GetRadius();
}

void Wheel::SetMaterial(std::string material) {
    this->brake_shoe_.SetMaterial(material);
}

void Wheel::SetColor(std::string color) {
    this->brake_shoe_.SetColor(color);
}

void Wheel::SetSize(int height, int width) {
    this->brake_shoe_.SetSize(height, width);
}

std::string Wheel::GetTypeOfMaterialToBrakeShoe() {
    return this->brake_shoe_.GetMaterial();
}

