
#include "radiator_grille.h"

RadiatorGrille::RadiatorGrille():size(){}

RadiatorGrille::RadiatorGrille(int height, int width, int count_of_holes, int diameter):
size(height, width){
    this->count_of_holes = count_of_holes;
    this->diameter_of_hole = diameter;
}

bool RadiatorGrille::set_size(int height, int width) {
    return this->size.set_size(height, width);
}

bool RadiatorGrille::set_count_of_holes(int count_of_holes) {
    return set_single_value(count_of_holes, "The number of holes should be positive", this->count_of_holes);
}

bool RadiatorGrille::set_diameter(int diameter) {
    return set_single_value(diameter, "The diameter of hole should be positive", this->diameter_of_hole);
}

int RadiatorGrille::get_count_of_holes() const {
    return this->count_of_holes;
}

int RadiatorGrille::get_diameter() const {
    return this->diameter_of_hole;
}

bool RadiatorGrille::check_reliability_of_grille() const {
   return this->count_of_holes>200 && this->diameter_of_hole<10;
}
