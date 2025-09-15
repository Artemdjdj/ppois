
#include "include_basic_params.h"
#include "include_wheel.h"
#include <string>
#include <iostream>
using namespace std;

bool BrakeShoe::check_type_of_material(string &material) {
    for (auto &good_material : type_of_materials_to_brake_shoe) {
        ToLower(material);
        if (material == good_material) {
            return true;
        }
    }
    return false;
}
BrakeShoe::BrakeShoe():BasicParams(), Color() {}
BrakeShoe::BrakeShoe(int height, int width, string material, string color):BasicParams(height, width), Color(color) {
    this->type_of_material = material;
}
BrakeShoe::BrakeShoe(string material):BasicParams() {
    this->type_of_material = material;
}
void BrakeShoe::set_material(string material) {
    if (!check_type_of_material(material)) return;
    this->type_of_material = material;
}
string BrakeShoe::get_material() {
    return this->type_of_material;
}

