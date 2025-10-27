#include "water_pump.h"
#include "../../Exceptions/exceptions.h"

WaterPump::WaterPump(const int flow, const int max_pressure) : flow_rate_(flow), max_pressure_(max_pressure),
                                                               current_pressure_(0),
                                                               is_working_(false), resource_(100) {
}

bool WaterPump::StartPump() {
    if (!is_working_ && resource_ > 0) {
        is_working_ = true;
        return true;
    }
    return false;
}

void WaterPump::StopPump() {
    is_working_ = false;
    current_pressure_ = 0;
}

int WaterPump::CalculateFlow(const int pressure) {
    if (!is_working_ or pressure > max_pressure_) {
        return 0;
    }
    current_pressure_ = pressure;
    return (flow_rate_ * pressure) / max_pressure_;
}

int WaterPump::CalculatePower(const int pressure) const {
    if (!is_working_) return 0;
    return flow_rate_ * pressure;
}

int WaterPump::GetResource() const {
    return resource_;
}

int WaterPump::GetCurrentPressure() const {
    return current_pressure_;
}

int WaterPump::GetMaxPressure() const {
    return max_pressure_;
}

int WaterPump::GetFlowRate() const {
    return flow_rate_;
}

bool WaterPump::GetWorkingState() const {
    return is_working_;
}

void WaterPump::SetOperatingTemperature(const int temperature) {
    if (temperature < 0) {
        throw ExceptionRuntimeError("Incorrect temperature");
    }
    this->operating_temperature_ = temperature;
}

int WaterPump::GetOperatingTemperature() const {
    return this->operating_temperature_;
}

void WaterPump::SetThermostat(const bool is_thermostat) {
    this->is_thermostat_ = is_thermostat;
}

bool WaterPump::IsThermostat() const {
    return this->is_thermostat_;
}

void WaterPump::SetLifeSpan(const int life_span) {
    if (life_span < 0) {
        throw ExceptionRuntimeError("Incorrect life span");
    }
    this->life_span_ = life_span;
}

int WaterPump::GetLifeSpan() const {
    return this->life_span_;
}

void WaterPump::SetPowerConsumption(const int power_consumption) {
    if (power_consumption < 0) {
        throw ExceptionRuntimeError("Incourrect power consumption");
    }
    this->power_consumption_ = power_consumption;
}

int WaterPump::GetPowerConsumption() const {
    return this->power_consumption_;
}

void WaterPump::SetManufacturer(const std::string &manufacturer) {
    this->manufacturer_ = manufacturer;
}

const std::string &WaterPump::GetManufacturer() const {
    return this->manufacturer_;
}

void WaterPump::SetWeight(const int weight) {
    if (weight <= 0) {
        throw ExceptionRuntimeError("Incorrect weight");
    }
    this->weight_ = weight;
}

int WaterPump::GetWeight() const {
    return this->weight_;
}
