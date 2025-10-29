#include <string>
#include "fuel.h"
#include "basic_params.h"
#include "../Include/settings.h"
#include "../../Exceptions/exceptions.h"

Fuel::Fuel() {
}

Fuel::Fuel(const std::string &type_of_fuel, const std::string &season){
	SetTypeOfFuel(type_of_fuel);
	SetSeason(season);
}

void Fuel::SetTypeOfFuel(std::string type_of_fuel) {
	CarStringFormatter::ToLower(type_of_fuel);
	if (!CarValidator::CheckIsStatementCorrect(kTypeOfFuels, type_of_fuel)) {
		throw ExceptionIncorrectFuel("This is incorrect type of fuel");
	}
	this->type_of_fuel_ = type_of_fuel;
}

void Fuel::SetSeason(const Season& season) {
	this->season_ = season;
}

std::string Fuel::GetTypeOfFuel() const {
	return this->type_of_fuel_;
}

std::string Fuel::GetSeason() const {
	return this->season_.GetSeason();
}
