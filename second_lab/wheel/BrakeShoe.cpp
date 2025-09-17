
#include "include_basic_params.h"
#include "include_wheel.h"
#include <string>
#include <iostream>

#include "include_exceptions.h"
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
void BrakeShoe::set_material_private(string material) {
    if (!check_type_of_material(material)) {
        throw ExceptionIncorrectMaterial("This material is not used!");
    }
    this->type_of_material = material;
}
bool BrakeShoe::set_material(string material) {
    try {
        set_material_private(material);
        return true;
    }
    catch (const ExceptionIncorrectMaterial& e) {
        log_to_file(e.what());
        return false;
    }
    catch (const Exception&e) {
        log_to_file(e.what());
        return false;
    }
}

string BrakeShoe::get_material() {
    return this->type_of_material;
}

