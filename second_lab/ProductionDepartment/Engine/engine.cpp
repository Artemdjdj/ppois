#include "engine.h"
#include <iostream>

bool Engine::SetInfoAboutRim(int radius, int thickness, int density) {
	return this->rim_.SetDataRim(radius, thickness, density);
}

bool Engine::SetInfoAboutProng(int first_side, int second_side, int third_side, int thickness, int density) {
	return this->prong_.SetDataProng(first_side, second_side, third_side, thickness, density);
}

bool Engine::SetInfoAboutIntakeManifold(int main_volume, int radius_canal, int height_canal, int number_of_canals) {
	return this->intake_manifold_.SetMainVolume(main_volume) and
			this->intake_manifold_.SetRadiusCanal(radius_canal) and
			this->intake_manifold_.SetHeightCanal(height_canal) and
			this->intake_manifold_.SetNumberOfCanals(number_of_canals);
}

bool Engine::SetInfoAboutMetalChain(int count_of_metal_links, int height_of_plata, int width_of_plata, int radius,
									int height, int weight) {
	MetalLink metal_link{};
	if (metal_link.SetDataForCylinder(radius, height, weight) and metal_link.SetDataForTwoPlats(
			height_of_plata, width_of_plata)) {
		for (int i = 0; i < count_of_metal_links; i++) {
			MetalLink temp_metal_link{metal_link};
			this->metal_chain_.AddNewMetalLink(temp_metal_link);
		}
		return true;
	}
	return false;
}

bool Engine::SetInfoAboutPistons(int count_of_pistons, int diameter, int height, int compression_height,
								int count_of_cycles, int weight) {
	Piston piston{};
	if (piston.SetAllParameters(diameter, height, compression_height, count_of_cycles, weight)) {
		for (int i = 0; i < count_of_pistons; i++) {
			Piston temp_piston{piston};
			this->pistons_.push_back(temp_piston);
		}
		return true;
	}
	return false;
}

bool Engine::SetInfoAboutValveSprings(int count_of_valve_springs, int diameter, int length, int count_of_coils) {
	if (ValveSpring valve_spring{}; valve_spring.SetAllParameters(diameter, length, count_of_coils)) {
		for (int i = 0; i < count_of_valve_springs; i++) {
			ValveSpring temp_valve_spring{valve_spring};
			this->valve_springs_.push_back(temp_valve_spring);
		}
		return true;
	}
	return false;
}


bool Engine::SetInfoAboutTube(int radius_tube, int height_tube) {
	return this->tube_.SetHeight(height_tube) and this->tube_.SetRadius(radius_tube);
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

std::string Engine::GetInfoAboutRim() const{
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
	return (pistons_.size()==0)?"No any pistons in engine!":pistons_[0].GetInfoAboutPart();
}

std::string Engine::GetInfoAboutValveSprings() const {
	return (valve_springs_.size()==0)?"No any valve springs!":valve_springs_[0].GetInfoAboutPart();
}

std::string Engine::GetInfoAboutTube() const {
	return this->tube_.GetInfoAboutPart();
}

std::string Engine::GetInfoAboutWaterPump() const {
	return this->water_pump_.GetInfoAboutPart();
}






