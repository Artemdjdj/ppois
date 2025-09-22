#include "basic_params.h"
#include "../Exceptions/exceptions.h"
#include "wheel.h"
#include "settings.h"
#include <string>
#include <iostream>

BrakeShoe::BrakeShoe():BasicParams(), Color() {}

BrakeShoe::BrakeShoe(int height, int width, std::string material, std::string color):BasicParams(height, width), Color(color) {
    this->type_of_material_ = material;
}

BrakeShoe::BrakeShoe(std::string material):BasicParams() {
    this->type_of_material_ = material;
}

void BrakeShoe::SetMaterialPrivate(std::string material) {
    if (!CheckIsStatementCorrect(type_of_materials_to_brake_shoe,material)) {
        throw ExceptionIncorrectMaterial("This material is not used!");
    }
    this->type_of_material_ = material;
}

bool BrakeShoe::SetMaterial(std::string material) {
    try {
        SetMaterialPrivate(material);
        return true;
    }
    catch (const ExceptionIncorrectMaterial& e) {
        LogToFile(e.what());
        return false;
    }
    catch (const Exception&e) {
        LogToFile(e.what());
        return false;
    }
}

std::string BrakeShoe::GetMaterial() {
    return this->type_of_material_;
}

