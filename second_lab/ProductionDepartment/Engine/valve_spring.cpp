#include "basic_params.h"
#include "valve_spring.h"

ValveSpring::ValveSpring() = default;

ValveSpring::ValveSpring(int diameter, int length, int count_of_coils, bool is_compressed): diameter_(diameter),
	length_(length), count_of_coils_(count_of_coils), is_compressed_(is_compressed) {
}

void ValveSpring::SetAllParameters(int diameter, int length, int count_of_coils) {
	CarSetter::SetSingleValue(diameter, "The diameter can't be negative or zero!", this->diameter_);
	CarSetter::SetSingleValue(length, "The length can't be negative or zero!", this->length_);
	CarSetter::SetSingleValue(count_of_coils, "Count of coils can't be bigger negative or zero", this->count_of_coils_);
}

void ValveSpring::Compress() {
	this->is_compressed_ = true;
}

void ValveSpring::DeCompress() {
	this->is_compressed_ = false;
}

int ValveSpring::GetDiameter() const {
	return this->diameter_;
}

int ValveSpring::GetCountOfCoils() const {
	return this->count_of_coils_;
}

int ValveSpring::GetLength() const {
	return this->length_;
}

bool ValveSpring::CheckIsCompressed() const {
	return this->is_compressed_;
}

double ValveSpring::DistBetweenNeighbours() const {
	if (this->count_of_coils_ == 0) {
		return 0;
	}
	return static_cast<double>(this->length_ / this->count_of_coils_);
}
