#include "basic_params.h"
#include "../../Exceptions/exceptions.h"
#include "wheel.h"
#include "../Include/settings.h"
#include <string>
#include <iostream>

BrakeShoe::BrakeShoe(const int height, const int width, const std::string &material, const Color& color): BasicParams(height, width) {
	this->type_of_material_ = material;
	this->color_ = color;
}

BrakeShoe::BrakeShoe(const std::string &material): BasicParams() {
	this->type_of_material_ = material;
}

void BrakeShoe::SetColor(const Color& color) {
	this->color_ = color;
}

std::string BrakeShoe::GetColor() const {
	return this->color_.GetColor();
}

void BrakeShoe::SetMaterial(std::string material) {
	if (!CarValidator::CheckIsStatementCorrect(kTypeOfMaterialsToBrakeShoe, material)) {
		throw ExceptionIncorrectMaterial("This material is not used!");
	}
	this->type_of_material_ = material;
}

std::string BrakeShoe::GetMaterial() {
	return this->type_of_material_;
}
