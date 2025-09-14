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
    void setRadius(int r);
    int getRadius();
};

class BrakeShoe:public BasicParams, public Color {
private:
    string type_of_material;
    bool check_type_of_material(string material);
public:
    BrakeShoe();
    BrakeShoe(int height, int width, string material, string color);
    BrakeShoe(string material);
};

#endif //INCLUDE_WHEEL_H
