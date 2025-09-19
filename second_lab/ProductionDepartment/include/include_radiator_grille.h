
#ifndef INCLUDE_RADIATOR_GRILLE_H
#define INCLUDE_RADIATOR_GRILLE_H
#include "include_basic_params.h"

class RadiatorGrille {
private:
    BasicParams size;
    int count_of_holes{0};
    int diameter_of_hole{0};
public:
    RadiatorGrille();
    RadiatorGrille(int height, int width, int count_of_holes, int diameter);
    bool set_size(int height, int width);
    bool set_count_of_holes(int count_of_holes);
    bool set_diameter(int diameter);
    int get_count_of_holes() const;
    int get_diameter() const;
    bool check_reliability_of_grille() const;
};
#endif //INCLUDE_RADIATOR_GRILLE_H
