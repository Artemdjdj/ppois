//
// Created by Redmi on 14.09.2025.
//

#ifndef INCLUDE_WHEEL_H
#define INCLUDE_WHEEL_H
#include <vector>
#include <string>
#include "include_basic_params.h"

class BaseCircle {
private:
    int radius{0};
public:
    BaseCircle() {}
    BaseCircle(int radius) {
        this->radius = radius;
    }
    bool set_radius(int r);
    int get_radius();
};

class BrakeShoe:public BasicParams, public Color {
private:
    std::string type_of_material;
    // bool check_type_of_material(std::string& material);
    void set_material_private(std::string material);
public:
    BrakeShoe();
    BrakeShoe(int height, int width, std::string material, std::string color);
    BrakeShoe(std::string material);
    bool set_material(std::string material);
    std::string get_material();
    // void display_info();
};

class Wheel{
private:
    BaseCircle radius;
    BrakeShoe brake_shoe;
    int count_of_bolts{0};
public:
    Wheel();
    Wheel(int radius, int height, int width, std::string material, std::string color, int count_of_bolts);
    bool set_count_of_bolts(int count_of_bolts);
    int get_count_of_bolts();
    int get_radius();
    bool set_radius(int radius);
    bool set_material(std::string material);
    bool set_color(std::string color);
    bool set_size(int height, int width);
    std::string get_type_of_material_to_brake_shoe();
};

class SignalButton{
private:
    BasicParams size;
    bool is_clicked = false;
public:
    SignalButton();
    SignalButton(int height, int width, bool is_clicked);
    void clicked_button();
    bool get_is_clicked() const;
    bool set_size_for_button(int height, int width);
};

class SteeringWheel{
private:
    BaseCircle radius_of_steering_wheel;
    BaseCircle radius_of_center_logo;
    SignalButton signal_button;
public:
    SteeringWheel();
    SteeringWheel(int first_radius, int second_radius, int height_of_button, int width_of_button, bool is_clicked);
    bool set_radius_of_steering_wheel(int radius_of_steering_wheel);
    bool set_radius_of_center_logo(int radius_of_center_logo);
    void clicked_button_to_make_noise();
    bool get_is_clicked() const;
    bool set_size_for_button(int height_of_button, int width_of_button);
};
#endif //INCLUDE_WHEEL_H
