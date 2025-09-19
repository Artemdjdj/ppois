
#ifndef TUBE_H
#define TUBE_H
#include "include_wheel.h"

class Tube {
private:
    BaseCircle radius;
    int height{0};
public:
    Tube();
    Tube(int radius, int height);
    bool set_radius(int radius);
    bool set_height(int height);
    int get_radius() const;
    int get_height() const;

};
#endif //TUBE_H
