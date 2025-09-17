#include "include_mirror.h"
#include "include_basic_params.h"
#include "include_exceptions.h"
#include <iostream>
#include <string>

Mirror::Mirror(int height, int width, int thickness, bool is_tinting, std::string serial_number):BasicParams(height, width) {
    this->thickness = thickness;
    this->is_tinting = is_tinting;
    this->serial_number = serial_number;
}
Mirror::Mirror():BasicParams(){}
void Mirror::make_mirror_tinting() {
    is_tinting = true;
    std::cout << "Mirror is tinting" << std::endl;
}

void Mirror::set_thickness_private(int thickness) {
    if (thickness< 0) {
        throw Exception("The thickness can't be negative!");
    }
    this->thickness = thickness;
}

bool Mirror::set_thickness(int thickness) {
    try {
        set_thickness_private(thickness);
        return true;
    }
    catch (const ExceptionIncorrectSize& e) {
        log_to_file(e.what());
        return false;
    }
    catch (const Exception& e) {
        log_to_file(e.what());
        return false;
    }
}

void Mirror::make_tinting() {
    this->is_tinting = true;
}

void Mirror::clear_tinting() {
    this->is_tinting = false;
}

void Mirror::set_serial_number_private(std::string serial_number) {
    if (serial_number.length()!=8) {
        throw ExceptionIncorrectSerialNumberLength("The lenght of serial number should be 8 symbols!");
    }
    if (!check_serial_number(serial_number)) {
        throw ExceptionIncorrectSerialNumber("Incorrect serial number!");
    }
    this->serial_number = serial_number;
}

bool Mirror::set_serial_number(std::string serial_number) {
    try {
        set_serial_number_private(serial_number);
        return true;
    }
    catch (const ExceptionIncorrectSerialNumberLength & e) {
        log_to_file(e.what());
        return false;
    }
    catch (const ExceptionIncorrectSerialNumber& e) {
        log_to_file(e.what());
        return false;
    }
    catch (const Exception& e) {
        log_to_file(e.what());
        return false;
    }
}z

void Mirror::get_information_about_mirror(int &height, int&width, int&thickness, bool&is_tinting, std::string &serial_number) {
    height = get_height();
    width = get_width();
    thickness = this->thickness;
    is_tinting = this->is_tinting;
    serial_number = this->serial_number;
}
std::string Mirror::get_serial_number() {
    return this->serial_number;
}

bool Mirror::check_serial_number(const std::string &serial_number) {
    if (!isupper(serial_number[0]) or !isupper(serial_number[1])) return false;
    for (int i =2; i < 8; i++) {
        if (!isdigit(serial_number[i])) {
            return false;
        }
    }
    return true;
}
