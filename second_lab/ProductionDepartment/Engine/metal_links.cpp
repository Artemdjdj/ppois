#include "include_metal_links.h"

Plata::Plata() = default;

Plata::Plata(int height, int width): size(height, width){}

bool Plata::set_plata_size(int height, int width) {
    return this->size.set_size(height, width);
}

int Plata::get_height_of_plata() const {
    return this->size.get_height();
}

int Plata::get_width_of_plata() const {
    return this->size.get_width();
}

std::string Plata::get_material() const {
    return this->material;
}

MetalCylinder::MetalCylinder():Tube(){};

MetalCylinder::MetalCylinder(int radius, int height, int weight):Tube(radius, height), weight(weight){}

bool MetalCylinder::set_weight(int weight) {
    return set_single_value(weight, "Weight, can't be negative or zero!", this->weight);
}

int MetalCylinder::get_weight() const {
    return this->weight;
}

MetalLink::MetalLink() {};

MetalLink::MetalLink(int height_of_plata, int width_of_plata, int radius, int height, int weight):cylinder(radius, height, weight),
two_plats(Plata(height_of_plata, width_of_plata), Plata(height_of_plata, width_of_plata)){}

bool MetalLink::set_data_for_cylinder(int radius, int height, int weight) {
    return cylinder.set_weight(weight) and cylinder.set_radius(radius) and cylinder.set_height(height);
}

bool MetalLink::set_data_for_two_plats(int height_of_plata, int width_of_plata) {
    return this->two_plats.first.set_plata_size(height_of_plata, width_of_plata) and two_plats.second.set_plata_size(height_of_plata, width_of_plata);
}

int MetalLink::get_height_of_plata_for_user() const {
    return this->two_plats.first.get_height_of_plata();
}

int MetalLink::get_width_of_plata_for_user() const {
    return this->two_plats.first.get_width_of_plata();
}

void MetalChain::add_new_metal_link(const MetalLink &new_metal_link) {
    this->chain.push_back(new_metal_link);
}

void MetalChain::delete_metal_link() {
    if (this->chain.size()<=0) return;
    this->chain.pop_back();
}

int MetalChain::get_lens_of_metal_chain() const {
    return this->chain.size();
}





