#include "engine.h"
#include <iostream>

#include "../../Exceptions/exceptions.h"

Engine::Engine(const bool is_worked, const int engine_life) : is_worked_(is_worked), engine_life_(engine_life) {
}

void Engine::SetInfoAboutRim(const int radius, const int thickness, const int density) {
    this->rim_.SetDataRim(radius, thickness, density);
}

void Engine::SetInfoAboutProng(const int first_side, const int second_side, const int third_side, const int thickness,
                               const int density) {
    this->prong_.SetDataProng(first_side, second_side, third_side, thickness, density);
}

void Engine::SetInfoAboutIntakeManifold(const int main_volume, const int radius_canal, const int height_canal,
                                        const int number_of_canals) {
    this->intake_manifold_.SetMainVolume(main_volume);
    this->intake_manifold_.SetRadiusCanal(radius_canal);
    this->intake_manifold_.SetHeightCanal(height_canal);
    this->intake_manifold_.SetNumberOfCanals(number_of_canals);
}

void Engine::SetInfoAboutMetalChain(const int count_of_metal_links, const int height_of_plata, const int width_of_plata,
                                    const int radius,
                                    const int height, const int weight) {
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

void Engine::SetInfoAboutPistons(int count_of_pistons, const int diameter, const int height,
                                 const int compression_height,
                                 const int count_of_cycles, const int weight) {
    if (count_of_pistons <= 0) return;
    Piston piston{};
    piston.SetAllParameters(diameter, height, compression_height, count_of_cycles, weight);
    for (int i = 0; i < count_of_pistons; i++) {
        Piston temp_piston{piston};
        this->pistons_.push_back(temp_piston);
    }
}

void Engine::SetInfoAboutValveSprings(const int count_of_valve_springs, const int diameter, const int length,
                                      const int count_of_coils) {
    if (count_of_valve_springs <= 0) return;
    ValveSpring valve_spring{};
    valve_spring.SetAllParameters(diameter, length, count_of_coils);
    for (int i = 0; i < count_of_valve_springs; i++) {
        ValveSpring temp_valve_spring{valve_spring};
        this->valve_springs_.push_back(temp_valve_spring);
    }
}


void Engine::SetInfoAboutTube(const int radius_tube, const int height_tube) {
    this->tube_.SetHeight(height_tube);
    this->tube_.SetRadius(radius_tube);
}

void Engine::SetInfoAboutWaterPump(const int flow, int density) {
    this->water_pump_ = WaterPump(flow, density);
}

void Engine::StartEngine() {
    this->is_worked_ = true;
}

void Engine::StopEngine() {
    this->is_worked_ = false;
}

void Engine::SetYearOfProducing(const int year_of_producing) {
    if (year_of_producing < 0) {
        throw ExceptionRuntimeError("Incorrect year of producing");
    }
    this->year_of_producing_ = year_of_producing;
}

void Engine::SetMaxServiceLife(const int max_service_life) {
    if (max_service_life < 0) {
        throw ExceptionRuntimeError("Incorrect service life");
    }
    this->max_service_life_ = max_service_life;
}

void Engine::SetCountOfCylinders(const int count) {
    if (count < 2 or count > 16) {
        throw ExceptionRuntimeError("Incorrect count of cylinders");
    }
    this->count_of_cylinders_ = count;
}

void Engine::SetGuarantee(const int guarantee) {
    if (guarantee < 0) {
        throw ExceptionRuntimeError("Incorrect guarantee");
    }
    this->guarantee_ = guarantee;
}

void Engine::SetMaxPower(const int power) {
    if (power < 0) {
        throw ExceptionRuntimeError("Too small power");
    }
    this->max_power_ = power;
}

void Engine::SetTorque(const int torque) {
    if (torque < 0) {
        throw ExceptionRuntimeError("Incorrect torque");
    }
    this->torque_ = torque;
}

void Engine::SetWorkCycle(const int cycle) {
    if (cycle == 2 or cycle == 4) {
        this->work_cycle_ = cycle;
        return;
    }
    throw ExceptionRuntimeError("Incorrect count of cycles");
}

void Engine::SetWeight(const int weight) {
    if (weight < 0) {
        throw ExceptionRuntimeError("Incorrect weight");
    }
    this->weight_ = weight;
}

void Engine::SetFuelConsumption(const double consumption) {
    if (consumption < 0) {
        throw ExceptionRuntimeError("Incorrect consumption");
    }
    this->fuel_consumption_ = consumption;
}

void Engine::SetRotationSpeed(const int speed) {
    if (speed < 0) {
        throw ExceptionRuntimeError("Incorrect speed");
    }
    this->rotation_speed_ = speed;
}

void Engine::SetCompany(const std::string &company) {
    this->company_ = company;
}

void Engine::SetCountry(const std::string &country) {
    this->country_ = country;
}

void Engine::SetCity(const std::string &city) {
    this->city_ = city;
}

void Engine::SetInformation(const std::string &info) {
    this->information_ = info;
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

int Engine::GetYearOfProducing() const {
    return this->year_of_producing_;
}

int Engine::GetMaxServiceLife() const {
    return this->max_service_life_;
}

int Engine::GetCountOfCylinders() const {
    return this->count_of_cylinders_;
}

int Engine::GetGuarantee() const {
    return this->guarantee_;
}


int Engine::GetMaxPower() const {
    return this->max_power_;
}

int Engine::GetTorque() const {
    return this->torque_;
}

int Engine::GetWorkCycle() const {
    return this->work_cycle_;
}

int Engine::GetWeight() const {
    return this->weight_;
}

double Engine::GetFuelConsumption() const {
    return this->fuel_consumption_;
}

int Engine::GetRotationSpeed() const {
    return this->rotation_speed_;
}

std::string Engine::GetCompany() const {
    return this->company_;
}

std::string Engine::GetCountry() const {
    return this->country_;
}

std::string Engine::GetCity() const {
    return this->city_;
}


std::string Engine::GetInformation() const {
    return this->information_;
}
