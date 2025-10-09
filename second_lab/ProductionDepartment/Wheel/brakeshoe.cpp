#include "basic_params.h"
#include "../../Exceptions/exceptions.h"
#include "wheel.h"
#include "../Include/settings.h"
#include <string>
#include <iostream>

BrakeShoe::BrakeShoe(): BasicParams() {
}

BrakeShoe::BrakeShoe(int height, int width, std::string material): BasicParams(height, width) {
	this->type_of_material_ = material;
}

BrakeShoe::BrakeShoe(std::string material): BasicParams() {
	this->type_of_material_ = material;
}

void BrakeShoe::SetColor(std::string color) {
	this->color_.SetColor(color);
}

std::string BrakeShoe::GetColor() {
	return this->color_.GetColor();
}

void BrakeShoe::SetMaterial(std::string material) {
	if (!CheckIsStatementCorrect(type_of_materials_to_brake_shoe, material)) {
		throw ExceptionIncorrectMaterial("This material is not used!");
	}
	this->type_of_material_ = material;
}

std::string BrakeShoe::GetMaterial() {
	return this->type_of_material_;
}
