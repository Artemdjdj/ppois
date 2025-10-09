#include "engine.h"
#include <iostream>

#include "../../Exceptions/exceptions.h"

Engine::Engine(bool is_worked, int engine_life): is_worked_(is_worked), engine_life_(engine_life) {
}

void Engine::SetInfoAboutRim(int radius, int thickness, int density) {
	this->rim_.SetDataRim(radius, thickness, density);
}

void Engine::SetInfoAboutProng(int first_side, int second_side, int third_side, int thickness, int density) {
	this->prong_.SetDataProng(first_side, second_side, third_side, thickness, density);
}

void Engine::SetInfoAboutIntakeManifold(int main_volume, int radius_canal, int height_canal, int number_of_canals) {
	this->intake_manifold_.SetMainVolume(main_volume);
	this->intake_manifold_.SetRadiusCanal(radius_canal);
	this->intake_manifold_.SetHeightCanal(height_canal);
	this->intake_manifold_.SetNumberOfCanals(number_of_canals);
}

void Engine::SetInfoAboutMetalChain(int count_of_metal_links, int height_of_plata, int width_of_plata, int radius,
									int height, int weight) {
	if (count_of_metal_links <= 0) return;
	MetalLink metal_link{};
	metal_link.SetDataForCylinder(radius, height, weight);
	metal_link.SetDataForTwoPlats(
		height_of_plata, width_of_plata);
	for (int i = 0; i < count_of_metal_links; i++) {
		MetalLink temp_metal_link{metal_link};
		this->metal_chain_.AddNewMetalLink(temp_metal_link);
	}
}

void Engine::SetInfoAboutPistons(int count_of_pistons, int diameter, int height, int compression_height,
								int count_of_cycles, int weight) {
	if (count_of_pistons <= 0) return;
	Piston piston{};
	piston.SetAllParameters(diameter, height, compression_height, count_of_cycles, weight);
	for (int i = 0; i < count_of_pistons; i++) {
		Piston temp_piston{piston};
		this->pistons_.push_back(temp_piston);
	}
}

void Engine::SetInfoAboutValveSprings(int count_of_valve_springs, int diameter, int length, int count_of_coils) {
	if (count_of_valve_springs <= 0) return;
	ValveSpring valve_spring{};
	valve_spring.SetAllParameters(diameter, length, count_of_coils);
	for (int i = 0; i < count_of_valve_springs; i++) {
		ValveSpring temp_valve_spring{valve_spring};
		this->valve_springs_.push_back(temp_valve_spring);
	}
}


void Engine::SetInfoAboutTube(int radius_tube, int height_tube) {
	this->tube_.SetHeight(height_tube);
	this->tube_.SetRadius(radius_tube);
}

void Engine::SetInfoAboutWaterPump(int flow, int density) {
	this->water_pump_ = WaterPump(flow, density);
}

void Engine::StartEngine() {
	this->is_worked_ = true;
}

void Engine::StopEngine() {
	this->is_worked_ = false;
}

bool Engine::CheckIsEngineWorking() const {
	return this->is_worked_;
}

std::string Engine::GetInfoAboutRim() const {
	return this->rim_.GetInfoAboutPart();
}

std::string Engine::GetInfoAboutProng() const {
	return this->prong_.GetInfoAboutPart();
}

std::string Engine::GetInfoAboutIntakeManifold() const {
	return this->intake_manifold_.GetInfoAboutPart();
}

std::string Engine::GetInfoAboutMetalChain() const {
	return this->metal_chain_.GetInfoAboutPart();
}

std::string Engine::GetInfoAboutPistons() const {
	return (pistons_.empty())
				? "No any pistons in engine!"
				: pistons_[0].GetInfoAboutPart() + " The count of pistons - " + std::to_string(pistons_.size());
}

std::string Engine::GetInfoAboutValveSprings() const {
	return (valve_springs_.empty())
				? "No any valve springs!"
				: valve_springs_[0].GetInfoAboutPart() + " The count of valve springs - " + std::to_string(
					valve_springs_.size());
}

std::string Engine::GetInfoAboutTube() const {
	return this->tube_.GetInfoAboutPart();
}

std::string Engine::GetInfoAboutWaterPump() const {
	return this->water_pump_.GetInfoAboutPart();
}

std::string Engine::CheckIsEngineShouldBeServed() const {
	return (this->current_mileage_ > this->engine_life_)
				? "You should undergo maintenance!"
				: "You shouldn't undergo maintenance!";
}

int Engine::GetInfoAboutEngineLife() const {
	return this->engine_life_;
}

int Engine::GetInfoAboutCurrentMileage() const {
	return this->current_mileage_;
}

void Engine::DriveTheWay(int way) {
	if (way <= 0) throw ExceptionWayError("Wrong way");
	this->current_mileage_ += way;
}
