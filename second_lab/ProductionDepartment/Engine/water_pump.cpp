#include "include_water_pump.h"
#include <algorithm>

WaterPump::WaterPump(int flow, int max_pressure) :
flow_rate(flow),max_pressure(max_pressure),current_pressure(0),is_working(false),resource(100){}

bool WaterPump::start_pump() {
    if (!is_working && resource > 0) {
        is_working = true;
        return true;
    }
    return false;
}

void WaterPump::stop_pump() {
    is_working = false;
    current_pressure = 0;
}

int WaterPump::calculate_flow(int pressure) {
    if (!is_working or pressure > max_pressure) {
        return 0;
    }
    current_pressure = pressure;
    return (flow_rate * pressure) / max_pressure;
}

int WaterPump::calculate_power(int pressure) const {
    if (!is_working) return 0;
    return flow_rate*pressure;
}

int WaterPump::get_resource() const{
    return resource;
}

int WaterPump::get_current_pressure() const{
    return current_pressure;
}

int WaterPump::get_max_pressure() const{
    return max_pressure;
}

int WaterPump::get_flow_rate() const{
    return flow_rate;
}

bool WaterPump::get_working_state() const{
    return is_working;
}