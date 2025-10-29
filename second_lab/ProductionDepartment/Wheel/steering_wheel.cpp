#include "wheel.h"


SignalButton::SignalButton(int height, int width, bool is_clicked) : size_(height, width) {
    this->is_clicked_ = is_clicked;
}

void SignalButton::ClickedButton() {
    this->is_clicked_ = (!is_clicked_) ? true : false;
}

bool SignalButton::GetIsClicked() const {
    return this->is_clicked_;
}

void SignalButton::SetSizeForButton(int height, int width) {
    this->size_.SetSize(height, width);
}

void SignalButton::GetSize(int &height, int &width) const {
    height = this->size_.GetHeight();
    width = this->size_.GetWidth();
}

SteeringWheel::SteeringWheel(int first_radius, int second_radius, int height_of_button, int width_of_button,
                             bool is_clicked) : radius_of_steering_wheel_(first_radius),
                                                radius_of_center_logo_(second_radius),
                                                signal_button_(height_of_button, width_of_button, is_clicked) {
}

void SteeringWheel::SetRadiusOfSteeringWheel(int radius) {
    this->radius_of_steering_wheel_.SetRadius(radius);
}

void SteeringWheel::SetRadiusOfCenterLogo(int radius) {
    this->radius_of_center_logo_.SetRadius(radius);
}

int SteeringWheel::GetRadiusOfSteeringWheel() const {
    return this->radius_of_steering_wheel_.GetRadius();
}

int SteeringWheel::GetRadiusOfCenterLogo() const {
    return this->radius_of_center_logo_.GetRadius();
}

bool SteeringWheel::ClickedButtonToMakeNoise() {
    if (!signal_button_.GetIsClicked()) {
        signal_button_.ClickedButton();
        return true;
    }
    return false;
};

bool SteeringWheel::GetIsClicked() const {
    return this->signal_button_.GetIsClicked();
}

void SteeringWheel::SetSizeForButton(int height, int width) {
    signal_button_.SetSizeForButton(height, width);
}
