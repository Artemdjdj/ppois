#include "radiator_grille.h"

#include "../../Exceptions/exceptions.h"
#include "../../Settings/project_settings.h"

RadiatorGrille::RadiatorGrille() : size_() {
}

RadiatorGrille::RadiatorGrille(const int height, const int width, const int count_of_holes, const int diameter) : size_(
    height, width) {
    this->count_of_holes_ = count_of_holes;
    this->diameter_of_hole_ = diameter;
}

void RadiatorGrille::SetSize(const int height, const int width) {
    this->size_.SetSize(height, width);
}

void RadiatorGrille::SetCountOfHoles(const int count_of_holes) {
    SetSingleValue(count_of_holes, "The number of holes should be positive", this->count_of_holes_);
}

void RadiatorGrille::SetDiameter(const int diameter) {
    SetSingleValue(diameter, "The diameter of hole should be positive", this->diameter_of_hole_);
}

int RadiatorGrille::GetCountOfHoles() const {
    return this->count_of_holes_;
}

int RadiatorGrille::GetDiameter() const {
    return this->diameter_of_hole_;
}

bool RadiatorGrille::CheckReliabilityOfGrille() const {
    return this->count_of_holes_ > 200 && this->diameter_of_hole_ < 10;
}

void RadiatorGrille::SetColor(const std::string &color) {
    this->color_.SetColor(color);
}

void RadiatorGrille::SetYearOfProducing(const int year_of_producing) {
    if (year_of_producing <= kFirstCar or year_of_producing >= kMaxYear) {
        throw ExceptionRuntimeError("Incorrect year of producing");
    }
    this->year_of_producing_ = year_of_producing;
}

void RadiatorGrille::SetLedLighting(const bool is_led_lighting) {
    this->is_led_lighting_ = is_led_lighting;
}

void RadiatorGrille::SetStoneGuard(const bool is_stone_guard) {
    this->is_stone_guard_ = is_stone_guard;
}

void RadiatorGrille::MakeReinforced(const bool is_reinforced) {
    this->is_reinforced_ = is_reinforced;
}

std::string RadiatorGrille::GetColor() const {
    return this->color_.GetColor();
}

int RadiatorGrille::GetYearOfProducing() const {
    return this->year_of_producing_;
}

bool RadiatorGrille::HasLedLighting() const {
    return this->is_led_lighting_;
}

bool RadiatorGrille::HasStoneGuard() const {
    return this->is_stone_guard_;
}

bool RadiatorGrille::IsReinforced() const {
    return this->is_reinforced_;
}
