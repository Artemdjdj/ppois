
#ifndef INCLUDE_ELECTRIC_DETAILS_H
#define INCLUDE_ELECTRIC_DETAILS_H
#include <string>

class ElectroPart {
private:
    int voltage{0};
    int power{0};
    int current_strength{0};
public:
    ElectroPart();
    ElectroPart(int voltage, int power, int current_strength);
    bool set_voltage(int voltage);
    bool set_power(int power);
    bool set_current_strength(int current_strength);
    int get_voltage() const;
    int get_power() const;
    int get_current_strength() const;
    virtual ~ElectroPart()= default;
    virtual std::string get_purpose()= 0;
};

class Starter : public ElectroPart {
private:
    bool is_left_direction;
    int count_of_prong{0};
public:
    Starter();
    Starter(int voltage, int power, int current_strength, bool is_left_direction, int count_of_prong);
    void choose_right_direction();
    void choose_left_direction();
    bool set_count_of_prog(int count_of_prong);
    int get_count_of_prog() const;
    bool get_direction() const;
    std::string get_purpose() override;
};

class Battery : public ElectroPart {
private:
    int cold_cranking_current{0};
public:
    Battery();
    Battery(int voltage, int power, int current_strength, int cold_cranking_current);
    bool set_cold_cranking_current(int cold_cranking_current);
    int get_cold_cranking_current() const;
    std::string get_purpose() override;
};
#endif //INCLUDE_ELECTRIC_DETAILS_H
