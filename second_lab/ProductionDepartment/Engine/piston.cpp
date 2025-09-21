#include "basic_params.h"
#include "piston.h"

Piston::Piston() = default;

Piston::Piston(int diameter_p, int height_p, int compression_height_p, int count_of_cycles_p, int weight_p):
    diameter(diameter_p), height(height_p), compression_height(compression_height_p), count_of_cycles(count_of_cycles_p),
    weight(weight_p){}

bool Piston::set_all_parameters(int diameter, int height, int compression_height, int count_of_cycles, int weight) {
    return set_single_value(diameter, "The diameter should be bigger then 0!", this->diameter)
    and set_single_value(height, "The height should be bigger then 0!", this->height) and
    set_single_value(compression_height, "The compression height should be bigger then 0!", this->compression_height)
    and set_single_value(count_of_cycles, "The count_of_cycles should be bigger then 0!", this->count_of_cycles) and
    set_single_value(weight, "The weight should be bigger then 0!", this->weight);
}

int Piston::get_diameter() const {
    return this->diameter;
}

int Piston::get_count_of_cycles() const {
    return this->count_of_cycles;
}

int Piston::get_height() const {
    return this->height;
}

int Piston::get_weight() const {
    return this->weight;
}

bool Piston::check_is_piston_in_working_condition() const {
   return (this->count_of_cycles <= 10000);
}

