#include "basic_params.h"
#include "gear.h"
#include <optional>
#include <cmath>
#include <iostream>
#include <ostream>

Triangle::Triangle(const int first_side, const int second_side, const int third_side) : first_side_(first_side),
    second_side_(second_side),
    third_side_(third_side) {
}

void Triangle::SetSides(const int first_side, const int second_side, const int third_side) {
    CarSetter::SetSingleValue(first_side, "The side can't be negative or zero!", this->first_side_);
    CarSetter::SetSingleValue(second_side, "The side can't be negative or zero!", this->second_side_);
    CarSetter::SetSingleValue(third_side, "The side can't be negative or zero!", this->third_side_);
}

std::optional<int> Triangle::GetOneOfSides(const int number_of_side) const {
    switch (number_of_side) {
        case 1: {
            return first_side_;
        }
        break;
        case 2: {
            return second_side_;
        }
        break;
        case 3: {
            return third_side_;
        }
        break;
        default: {
            return std::nullopt;
        }
    }
}

double Triangle::GetPerimeter() {
    return static_cast<double>(this->first_side_ + this->second_side_ + this->third_side_);
}

double Triangle::GetSquare() {
    const double semiperimeter = GetPerimeter() / 2;
    return sqrt(
        semiperimeter * (semiperimeter - this->first_side_) * (semiperimeter - this->second_side_) * (
            semiperimeter - this->third_side_));
}

Circle::Circle(const int radius) : radius_(radius) {
}

void Circle::SetRadius(const int radius) {
    CarSetter::SetSingleValue(radius, "The radius can't be negative or zero!", this->radius_);
}

int Circle::GetRadius() const {
    return this->radius_;
}

double Circle::GetPerimeter() {
    return 2 * M_PI * this->radius_;
}

double Circle::GetSquare() {
    return M_PI * pow(this->radius_, 2);
}

Detail::Detail(const int thickness, const int density) : thickness_(thickness), density_(density) {
}

void Detail::SetThickness(const int thickness) {
    CarSetter::SetSingleValue(thickness, "Thickness can't be negative or zero!", this->thickness_);
}

void Detail::SetDensity(const int density) {
    CarSetter::SetSingleValue(density, "Density can't be negative or zero!", this->density_);
}

int Detail::GetDensity() const {
    return this->density_;
}

int Detail::GetThickness() const {
    return this->thickness_;
}

Prong::Prong(const int first_side, const int second_side, const int third_side, const int thickness,
             const int density) : Triangle(first_side,
                                           second_side, third_side), Detail(thickness, density) {
}

void Prong::SetDataProng(const int first_side, const int second_side, const int third_side, const int thickness,
                         const int density) {
    SetSides(first_side, second_side, third_side);
    SetThickness(thickness);
    SetDensity(density);
}

double Prong::GetWeight() {
    return GetSquare() * GetThickness() * GetDensity() * pow(10, -6);
}

Rim::Rim(const int radius, const int thickness, const int density) : Circle(radius), Detail(thickness, density) {
}

void Rim::SetDataRim(const int radius, const int thickness, const int density) {
    SetRadius(radius);
    SetThickness(thickness);
    SetDensity(density);
}

double Rim::GetWeight() {
    return GetSquare() * GetThickness() * GetDensity() * pow(10, -6);
}
