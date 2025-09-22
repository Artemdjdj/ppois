#include "wheel.h"

SignalButton::SignalButton():size_(){}

SignalButton::SignalButton(int height, int width, bool is_clicked):size_(height, width) {
    this->is_clicked_ = is_clicked;
}

void SignalButton::ClickedButton() {
    this->is_clicked_ = (!is_clicked_)?true:false;
}

bool SignalButton::GetIsClicked() const {
    return this->is_clicked_;
}

bool SignalButton::SetSizeForButton(int height, int width) {
    return this->size_.SetSize(height,width);
}

SteeringWheel::SteeringWheel():radius_of_steering_wheel_(), radius_of_center_logo_(){}

SteeringWheel::SteeringWheel(int first_radius, int second_radius, int height_of_button, int width_of_button, bool is_clicked):
radius_of_steering_wheel_(first_radius), radius_of_center_logo_(second_radius), signal_button_(height_of_button, width_of_button, is_clicked){}

bool SteeringWheel::SetRadiusOfSteeringWheel(int radius) {
    return this->radius_of_steering_wheel_.SetRadius(radius);
}

bool SteeringWheel::SetRadiusOfCenterLogo(int radius) {
    return this->radius_of_center_logo_.SetRadius(radius);
}

bool SteeringWheel::ClickedButtonToMakeNoise() {
    if (!signal_button_.GetIsClicked()) {
        signal_button_.ClickedButton();
        LogToFile("Car signal!!");
        return true;
    }
    return false;
};

bool SteeringWheel::GetIsClicked() const {
    return this->signal_button_.GetIsClicked();
}

bool SteeringWheel::SetSizeForButton(int height, int width) {
    return signal_button_.SetSizeForButton(height, width);
}
