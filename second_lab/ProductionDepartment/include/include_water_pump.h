
#ifndef INCLUDE_WATER_PUMP_H
#define INCLUDE_WATER_PUMP_H
class WaterPump{
private:
    int flow_rate{0};
    int max_pressure{0};
    int current_pressure{0};
    bool is_working{false};
    int resource{0};
public:
    WaterPump(int flow, int max_pressure);
    bool start_pump();
    void stop_pump();
    int calculate_flow(int pressure);
    int calculate_power(int pressure) const;
    int get_resource() const;
    int get_current_pressure() const;
    int get_max_pressure() const;
    int get_flow_rate() const;
    bool get_working_state() const;
};
#endif //INCLUDE_WATER_PUMP_H
