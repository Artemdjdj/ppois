#include "include_basic_params.h"
#include "include_valve_spring.h"

ValveSpring::ValveSpring() = default;

ValveSpring::ValveSpring(int diameter, int length, int count_of_coils, bool is_compressed):
diameter(diameter), length(length), count_of_coils(count_of_coils), is_compressed(is_compressed){}

bool ValveSpring::set_all_parameters(int diameter, int length, int count_of_coils) {
    return  set_single_value(diameter, "The diameter can't be negative or zero!", this->diameter) and
    set_single_value(length, "The length can't be negative or zero!", this->length) and
    set_single_value(count_of_coils, "Count of coils can't be bigger negative or zero", this->count_of_coils);
}

void ValveSpring::compress() {
    this->is_compressed = true;
}

void ValveSpring::decompress() {
    this->is_compressed = false;
}

int ValveSpring::get_diameter() const {
    return this->diameter;
}

int ValveSpring::get_count_of_coils() const {
    return this->count_of_coils;
}

int ValveSpring::get_length() const {
    return this->length;
}

bool ValveSpring::check_is_compressed() const {
    return this->is_compressed;
}

double ValveSpring::dist_between_neighbours() const {
    return static_cast<double>(this->length / this->count_of_coils);
}
