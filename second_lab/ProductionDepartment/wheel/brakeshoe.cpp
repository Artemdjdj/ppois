
#include "include_basic_params.h"
#include "include_exceptions.h"
#include "include_wheel.h"
#include "settings.h"
#include <string>
#include <iostream>

BrakeShoe::BrakeShoe():BasicParams(), Color() {}
BrakeShoe::BrakeShoe(int height, int width, std::string material, std::string color):BasicParams(height, width), Color(color) {
    this->type_of_material = material;
}
BrakeShoe::BrakeShoe(std::string material):BasicParams() {
    this->type_of_material = material;
}
void BrakeShoe::set_material_private(std::string material) {
    if (!check_is_statement_correct(type_of_materials_to_brake_shoe,material)) {
        throw ExceptionIncorrectMaterial("This material is not used!");
    }
    this->type_of_material = material;
}
bool BrakeShoe::set_material(std::string material) {
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

std::string BrakeShoe::get_material() {
    return this->type_of_material;
}

