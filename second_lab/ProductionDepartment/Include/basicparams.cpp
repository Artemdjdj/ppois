#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "../../Exceptions/exceptions.h"
#include "basic_params.h"
#include "settings.h"

BasicParams::BasicParams(const int height, const int width) {
    SetHeight(height);
    SetWidth(width);
}

void BasicParams::SetHeight(const int height) {
    CarSetter::SetSingleValue(height, "The height must be greater then zero!", this->height_);
}

void BasicParams::SetWidth(const int width) {
    CarSetter::SetSingleValue(width, "The width must be greater then zero!", this->width_);
}

void BasicParams::SetSize(const int height, const int width) {
    SetHeight(height);
    SetWidth(width);
}

int BasicParams::GetHeight() const {
    return this->height_;
}

int BasicParams::GetWidth() const {
    return this->width_;
}

void BasicParams::GetSize(int &height, int &width) const {
    height = this->height_;
    width = this->width_;
}

Color::Color(const std::string &color) {
    SetColor(color);
}

void Color::SetColor(std::string color) {
    if (!CarValidator::CheckIsStatementCorrect(kColors, color)) {
        throw ExceptionIncorrectColor("This color is not correct!");
    }
    this->color_ = color;
}

std::string Color::GetColor() const {
    return this->color_;
}

Volume::Volume(const int volume) {
    SetVolume(volume);
}

void Volume::SetVolume(const int volume) {
    CarSetter::SetSingleValue(volume, "The volume must be greater then zero!", this->volume_);
}

int Volume::GetVolume() const {
    return this->volume_;
}

void CarSetter::SetSinglePercent(int procent, int &value) {
    if (procent < 0 || procent > 100) {
        throw ExceptionIncorrectProcent("Percentage must be between 0 and 100!");
    }
    value = procent;
}

void CarSetter::SetSingleValue(int integer_number, const char *description, int &value) {
    if (integer_number < 0) {
        throw ExceptionIncorrectSize(description);
    }
    value = integer_number;
}

void CarStringFormatter::ToLower(std::string &str) {
    std::ranges::transform(str, str.begin(), ::tolower);
}

bool CarLogger::LogToFile(const char *message, const std::string &file_name) {
    std::ofstream file;
    file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        file.open(file_name, std::ios::app);
        file << std::endl << message << std::endl;
        file.close();
        return true;
    } catch (...) { return false; }
}

int CarLogger::CheckFileLog(const std::string &file_name) {
    std::ofstream file(file_name, std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << file_name << std::endl;
        return 1;
    }
    file.close();
    return 0;
}

bool CarValidator::CheckIsStatementCorrect(const std::vector<std::string> &vector_of_string, std::string &statement) {
    for (auto &good_statement: vector_of_string) {
        CarStringFormatter::ToLower(statement);
        if (good_statement == statement) {
            return true;
        }
    }
    return false;
}

int MathOperations::GetNewValueAfterMultiplication(const int number, int procent) {
    return static_cast<int>(number * procent / 100);
}

double MathOperations::GetNewValueAfterMultiplication(const double temperature) {
    return kSpeedOfSound + 0.61 * temperature;
}
