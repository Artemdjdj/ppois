
#ifndef INCLUDE_INTAKE_MANIFOLD_H
#define INCLUDE_INTAKE_MANIFOLD_H
#include "include_basic_params.h"
#include "tube.h"
#include <optional>
class IntakeManifold {
private:
    Volume main_volume;
    Volume plenum_volume;
    Tube canal;
    int number_of_canals;
public:
    IntakeManifold();
    IntakeManifold(int main_volume, int radius_canal, int height_canal, int number_of_canals);
    bool set_main_volume(int main_volume);
    void set_plenum_volume();
    bool set_height_canal(int height_canal);
    bool set_radius_canal(int radius_canal);
    bool set_number_of_canals(int number_of_canals);
    int get_number_of_canals() const;
    int get_radius_canal() const;
    int get_height_canal() const;
    int get_plenum_volume() const;
    std::optional<double> calculate_response_frequency(double temperature) const;
private:
    void checking_volume() const;
};
#endif
