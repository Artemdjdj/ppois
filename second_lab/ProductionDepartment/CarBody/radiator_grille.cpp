
#include "radiator_grille.h"

RadiatorGrille::RadiatorGrille():size_(){}

RadiatorGrille::RadiatorGrille(int height, int width, int count_of_holes, int diameter):
size_(height, width){
    this->count_of_holes_ = count_of_holes;
    this->diameter_of_hole_ = diameter;
}

bool RadiatorGrille::SetSize(int height, int width) {
    return this->size_.SetSize(height, width);
}

bool RadiatorGrille::SetCountOfHoles(int count_of_holes) {
    return SetSingleValue(count_of_holes, "The number of holes should be positive", this->count_of_holes_);
}

bool RadiatorGrille::SetDiameter(int diameter) {
    return SetSingleValue(diameter, "The diameter of hole should be positive", this->diameter_of_hole_);
}

int RadiatorGrille::GetCountOfHoles() const {
    return this->count_of_holes_;
}

int RadiatorGrille::GetDiameter() const {
    return this->diameter_of_hole_;
}

bool RadiatorGrille::CheckReliabilityOfGrille() const {
   return this->count_of_holes_>200 && this->diameter_of_hole_<10;
}
