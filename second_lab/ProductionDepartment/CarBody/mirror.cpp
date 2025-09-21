#include "mirror.h"
#include "basic_params.h"
#include "../Exceptions/exceptions.h"
#include "settings.h"
#include <iostream>
#include <string>

Mirror::Mirror(int height, int width, int thickness, bool is_tinting, std::string serial_number):BasicParams(height, width) {
    this->thickness_ = thickness;
    this->is_tinting_ = is_tinting;
    this->serial_number_ = serial_number;
}
Mirror::Mirror():BasicParams(){}

void Mirror::MakeMirrorTinting() {
    is_tinting_ = true;
    std::cout << "Mirror is tinting" << std::endl;
}

bool Mirror::SetThickness(int thickness) {
   return SetSingleValue(thickness, "The thickness can't be negative number!", thickness);
}

void Mirror::MakeTinting() {
    this->is_tinting_ = true;
}

void Mirror::ClearTinting() {
    this->is_tinting_ = false;
}

void Mirror::CheckHowMuchEmptySpace(std::string serial_number) {
    if (!CheckSerialNumber(serial_number) or serial_number.length() !=8 ) {
        throw ExceptionIncorrectSerialNumber("Incorrect serial number!");
    }
    this->serial_number_ = serial_number;
}

bool Mirror::SetSerialNumber(std::string serial_number) {
    try {
        CheckHowMuchEmptySpace(serial_number);
        return true;
    }
    catch (const ExceptionIncorrectSerialNumber& e) {
        LogToFile(e.what());
        return false;
    }
    catch (const Exception& e) {
        LogToFile(e.what());
        return false;
    }
}

void Mirror::GetInformationAboutMirror(int &height, int&width, int&thickness, bool&is_tinting, std::string &serial_number) const {
    height = GetHeight();
    width = GetWidth();
    thickness = this->thickness_;
    is_tinting = this->is_tinting_;
    serial_number = this->serial_number_;
}

std::string Mirror::GetSerialNumber() {
    return this->serial_number_;
}

bool Mirror::CheckSerialNumber(const std::string &serial_number) {
    if (!isupper(serial_number[0]) or !isupper(serial_number[1])) return false;
    for (int i =2; i < 8; i++) {
        if (!isdigit(serial_number[i])) {
            return false;
        }
    }
    return true;
}
