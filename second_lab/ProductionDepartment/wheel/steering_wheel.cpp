
#include "wheel.h"
SignalButton::SignalButton():size(){}

SignalButton::SignalButton(int height, int width, bool is_clicked):size(height, width) {
    this->is_clicked = is_clicked;
}

void SignalButton::clicked_button() {
    this->is_clicked = (!is_clicked)?true:false;
}

bool SignalButton::get_is_clicked() const {
    return this->is_clicked;
}

bool SignalButton::set_size_for_button(int height, int width) {
    return this->size.set_size(height,width);
}

SteeringWheel::SteeringWheel():radius_of_steering_wheel(), radius_of_center_logo(){}

SteeringWheel::SteeringWheel(int first_radius, int second_radius, int height_of_button, int width_of_button, bool is_clicked):
radius_of_steering_wheel(first_radius), radius_of_center_logo(second_radius), signal_button(height_of_button, width_of_button, is_clicked){}

bool SteeringWheel::set_radius_of_steering_wheel(int radius) {
    return this->radius_of_steering_wheel.set_radius(radius);
}

bool SteeringWheel::set_radius_of_center_logo(int radius) {
    return this->radius_of_center_logo.set_radius(radius);
}

bool SteeringWheel::clicked_button_to_make_noise() {
    if (!signal_button.get_is_clicked()) {
        signal_button.clicked_button();
        log_to_file("Car signal!!");
        return true;
    }
    return false;
};

bool SteeringWheel::get_is_clicked() const {
    return this->signal_button.get_is_clicked();
}

bool SteeringWheel::set_size_for_button(int height, int width) {
    return signal_button.set_size_for_button(height, width);
}
