#include "basic_params.h"
#include "gear.h"
#include <optional>
#include <cmath>
#include <iostream>
#include <ostream>

Triangle::Triangle() = default;

Triangle::Triangle(int first_side, int second_side, int third_side): first_side_(first_side), second_side_(second_side),
																	third_side_(third_side) {
}

void Triangle::SetSides(int first_side, int second_side, int third_side) {
	SetSingleValue(first_side, "The side can't be negative or zero!", this->first_side_);
	SetSingleValue(second_side, "The side can't be negative or zero!", this->second_side_);
	SetSingleValue(third_side, "The side can't be negative or zero!", this->third_side_);
}

std::optional<int> Triangle::GetOneOfSides(int number_of_side) const {
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
	double semiperimeter = GetPerimeter() / 2;
	return sqrt(
		semiperimeter * (semiperimeter - this->first_side_) * (semiperimeter - this->second_side_) * (
			semiperimeter - this->third_side_));
}

Circle::Circle() = default;

Circle::Circle(int radius): radius_(radius) {
}

void Circle::SetRadius(int radius) {
	SetSingleValue(radius, "The radius can't be negative or zero!", this->radius_);
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

Detail::Detail() {
};

Detail::Detail(const int thickness, const int density): thickness_(thickness), density_(density) {
}

void Detail::SetThickness(int thickness) {
	SetSingleValue(thickness, "Thickness can't be negative or zero!", this->thickness_);
}

void Detail::SetDensity(int density) {
	SetSingleValue(density, "Density can't be negative or zero!", this->density_);
}

int Detail::GetDensity() const {
	return this->density_;
}

int Detail::GetThickness() const {
	return this->thickness_;
}

Prong::Prong(): Triangle(), Detail() {
}

Prong::Prong(int first_side, int second_side, int third_side, int thickness, int density): Triangle(first_side,
	second_side, third_side), Detail(thickness, density) {
}

void Prong::SetDataProng(int first_side, int second_side, int third_side, int thickness, int density) {
	SetSides(first_side, second_side, third_side);
	SetThickness(thickness);
	SetDensity(density);
}

double Prong::GetWeight() {
	return GetSquare() * GetThickness() * GetDensity() * pow(10, -6);
}

Rim::Rim() = default;

Rim::Rim(int radius, int thickness, int density): Circle(radius), Detail(thickness, density) {
}

void Rim::SetDataRim(int radius, int thickness, int density) {
	SetRadius(radius);
	SetThickness(thickness);
	SetDensity(density);
}

double Rim::GetWeight() {
	return GetSquare() * GetThickness() * GetDensity() * pow(10, -6);
}
