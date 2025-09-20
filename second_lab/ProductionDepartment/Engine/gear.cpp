#include "include_basic_params.h"
#include "include_gear.h"
#include <optional>
#include <cmath>
#include <iostream>
#include <ostream>

Triangle::Triangle() = default;

Triangle::Triangle(int first_side, int second_side, int third_side):
first_side(first_side), second_side(second_side), third_side(third_side) {}

bool Triangle::set_sides(int first_side, int second_side, int third_side) {
    return set_single_value(first_side, "The side can't be negative or zero!", this->first_side) and
    set_single_value(second_side, "The side can't be negative or zero!", this->second_side) and
    set_single_value(third_side, "The side can't be negative or zero!", this->third_side);
}

std::optional<int> Triangle::get_one_of_sides(int number_of_side) const {
    switch (number_of_side) {
        case 1:{
            return first_side;
        }break;
        case 2:{
            return second_side;
        }break;
        case 3:{
            return third_side;
        }break;
        default: {
            return std::nullopt;
        }
    }
}

double Triangle::get_perimeter() {
    return static_cast<double>(this->first_side + this->second_side + this->third_side);
}

double Triangle::get_square() {
    double semiperimeter = get_perimeter() / 2;
    return sqrt(semiperimeter * (semiperimeter - this->first_side) * (semiperimeter-this->second_side) * (semiperimeter-this->third_side));
}

Circle::Circle() = default;

Circle::Circle(int radius): radius(radius) {}

bool Circle::set_radius(int radius) {
    return set_single_value(radius, "The radius can't be negative or zero!", this->radius);
}

int Circle::get_radius() const{
    return this->radius;
}

double Circle::get_perimeter() {
    return 2*M_PI*this->radius;
}

double Circle::get_square() {
    return M_PI* pow(this->radius, 2);
}

Detail::Detail(){};

Detail::Detail(const int thickness, const int density):thickness(thickness), density(density) {}

bool Detail::set_thickness(int thickness) {
    return set_single_value(thickness,"Thickness can't be negative or zero!", this->thickness);
}

bool Detail::set_density(int density) {
    return set_single_value(density, "Density can't be negative or zero!", this->density);
}

int Detail::get_density() const {
    return this->density;
}

int Detail::get_thickness() const {
    return this->thickness;
}

Prong::Prong():Triangle(), Detail(){}

Prong::Prong(int first_side, int second_side, int third_side, int thickness, int density):Triangle(first_side, second_side, third_side), Detail(thickness, density){}

bool Prong::set_data_prong(int first_side, int second_side, int third_side, int thickness, int density) {
    return set_sides(first_side, second_side, third_side) and set_thickness(thickness) and set_density(density);
}

double Prong::get_weight() {
    return get_square()*get_thickness()*get_density()*pow(10, -6);
}

Rim::Rim()=default;

Rim::Rim(int radius, int thickness, int density):Circle(radius), Detail(thickness, density){}

bool Rim::set_data_rim(int radius, int thickness, int density) {
    return set_radius(radius) and set_thickness(thickness) and set_density(density);
}

double Rim::get_weight() {
    return get_square()*get_thickness()*get_density()*pow(10, -6);
}














