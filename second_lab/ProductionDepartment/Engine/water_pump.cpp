#include "water_pump.h"
#include <algorithm>

WaterPump::WaterPump(int flow, int max_pressure) :
flow_rate_(flow),max_pressure_(max_pressure),current_pressure_(0),is_working_(false),resource_(100){}

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

int WaterPump::CalculateFlow(int pressure) {
    if (!is_working_ or pressure > max_pressure_) {
        return 0;
    }
    current_pressure_ = pressure;
    return (flow_rate_ * pressure) / max_pressure_;
}

int WaterPump::CalculatePower(int pressure) const {
    if (!is_working_) return 0;
    return flow_rate_*pressure;
}

int WaterPump::GetResource() const{
    return resource_;
}

int WaterPump::GetCurrentPressure() const{
    return current_pressure_;
}

int WaterPump::GetMaxPressure() const{
    return max_pressure_;
}

int WaterPump::GetFlowRate() const{
    return flow_rate_;
}

bool WaterPump::GetWorkingState() const{
    return is_working_;
}