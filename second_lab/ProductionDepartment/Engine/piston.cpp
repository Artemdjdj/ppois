#include "basic_params.h"
#include "piston.h"

Piston::Piston() = default;

Piston::Piston(int diameter_p, int height_p, int compression_height_p, int count_of_cycles_p, int weight_p):
    diameter_(diameter_p), height_(height_p), compression_height_(compression_height_p), count_of_cycles_(count_of_cycles_p),
    weight_(weight_p){}

bool Piston::SetAllParameters(int diameter, int height, int compression_height, int count_of_cycles, int weight) {
    return SetSingleValue(diameter, "The diameter should be bigger then 0!", this->diameter_)
    and SetSingleValue(height, "The height should be bigger then 0!", this->height_) and
    SetSingleValue(compression_height, "The Compression height should be bigger then 0!", this->compression_height_)
    and SetSingleValue(count_of_cycles, "The count_of_cycles should be bigger then 0!", this->count_of_cycles_) and
    SetSingleValue(weight, "The weight should be bigger then 0!", this->weight_);
}

int Piston::GetDiameter() const {
    return this->diameter_;
}

int Piston::GetCountOfCycles() const {
    return this->count_of_cycles_;
}

int Piston::GetHeight() const {
    return this->height_;
}

int Piston::GetWeight() const {
    return this->weight_;
}

bool Piston::CheckIsPistonInWorkingCondition() const {
   return (this->count_of_cycles_ <= 10000);
}

