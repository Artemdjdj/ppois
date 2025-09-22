#include "tube.h"

Tube::Tube() = default;

Tube::Tube(int radius, int height): radius_(radius), height_(height) {
}

bool Tube::SetRadius(int radius) {
	return this->radius_.SetRadius(radius);
}

bool Tube::SetHeight(int height) {
	return SetSingleValue(height, "Height should be bigger then zero!", this->height_);
}

int Tube::GetRadius() const {
	return this->radius_.GetRadius();
}

int Tube::GetHeight() const {
	return this->height_;
}
