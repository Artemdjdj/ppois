//
// Created by Redmi on 14.09.2025.
//

#ifndef INCLUDE_WHEEL_H
#define INCLUDE_WHEEL_H
#include <vector>
#include <string>
#include "include_basic_params.h"
using namespace std;
const std::vector<std::string> type_of_materials_to_brake_shoe = {
    "semi-metallic", "organic", "low-metal", "ceramic"
};

class BaseCircle {
private:
    int radius{0};
public:
    BaseCircle() {}
    BaseCircle(int radius) {
        this->radius = radius;
    }
    void setRadius(int r);
    int getRadius();
};

class BrakeShoe:public BasicParams, public Color {
private:
    string type_of_material;
    bool check_type_of_material(string& material);
    void set_material_private(string material);
public:
    BrakeShoe();
    BrakeShoe(int height, int width, string material, string color);
    BrakeShoe(string material);
    bool set_material(string material);
    string get_material();
    // void display_info();
};

class Wheel {
private:
    BaseCircle radius;
    BrakeShoe brake_shoe;
    int count_of_bolts{0};
    void set_count_of_bolts_private(int count);
    void set_radius_private(int radius);

public:
    Wheel();
    Wheel(int radius, int height, int width, string material, string color, int count_of_bolts);
    bool set_count_of_bolts(int count_of_bolts);
    int get_count_of_bolts();
    int get_radius();
    bool set_radius(int radius);
    bool set_material(string material);
    bool set_color(string color);
    bool set_size(int height, int width);
    string get_type_of_material_to_brake_shoe();
};

#endif //INCLUDE_WHEEL_H
