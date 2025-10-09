#include "tube.h"

Tube::Tube() = default;

Tube::Tube(int radius, int height): radius_(radius), height_(height) {
}

void Tube::SetRadius(int radius) {
	this->radius_.SetRadius(radius);
}

void Tube::SetHeight(int height) {
	SetSingleValue(height, "Height should be bigger then zero!", this->height_);
}

int Tube::GetRadius() const {
	return this->radius_.GetRadius();
}

int Tube::GetHeight() const {
	return this->height_;
}
