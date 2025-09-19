
#ifndef INCLUDE_METAL_LINKS_H
#define INCLUDE_METAL_LINKS_H
#include "include_basic_params.h"
#include "include_tube.h"
#include <string>
#include <utility>
#include <vector>
class Plata{
private:
    BasicParams size;
    std::string material{"steel"};
public:
    Plata();
    Plata(int height, int width);
    bool set_plata_size(int height, int width);
    int get_height_of_plata() const;
    int get_width_of_plata() const;
    std::string get_material() const;
};

class MetalCylinder:public Tube{
private:
    int weight{0};
public:
    MetalCylinder();
    MetalCylinder(int radius, int height, int weight);
    bool set_weight(int weight);
    int get_weight() const;
};

class MetalLink {
private:
    std::pair<Plata, Plata> two_plats;
    MetalCylinder cylinder;
public:
    MetalLink();
    MetalLink(int height_of_plata, int width_of_plata, int radius, int height, int weight);
    bool set_data_for_two_plats(int height_of_plata, int width_of_plata);
    int get_height_of_plata_for_user() const;
    int get_width_of_plata_for_user() const;
    bool set_data_for_cylinder(int radius, int height, int weight);
};

class MetalChain {
private:
    std::vector<MetalLink> chain;
public:
    void add_new_metal_link(const MetalLink& new_metal_link);
    void delete_metal_link();
    int get_lens_of_metal_chain() const;
};
#endif //INCLUDE_METAL_LINKS_H
