#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "Exceptions/exceptions.h"
#include "basic_params.h"
#include "settings.h"

BasicParams::BasicParams(int height, int width) {
    this->height_ = height;
    this->width_ = width;
}
BasicParams::BasicParams(){}

bool BasicParams::SetHeight(int height) {
    return SetSingleValue(height, "The height must be greater then zero!", this->height_);
}

bool BasicParams::SetWidth(int width) {
    return SetSingleValue(width, "The width must be greater then zero!", this->width_);
}

bool BasicParams::SetSize(int height,int width) {
    if (!SetHeight(height)) return false;
    return SetWidth(width);
}

int BasicParams::GetHeight() const {
    return this->height_;
}

int BasicParams::GetWidth() const {
    return this->width_;
}

void BasicParams::GetSize(int & height, int & width) const {
    height = this->height_;
    width = this->width_;
}

Color::Color(std::string color) {
    this->color_ = color;
}

Color::Color(){}

void Color::SetColor_private(std::string color) {
    if (!CheckIsStatementCorrect(colors,color)) {
        throw ExceptionIncorrectColor("This color is not correct!");
    }
    this->color_ = color;
}
bool Color::SetColor(std::string color){
    try {
        SetColor_private(color);
        return true;
    }
    catch (const ExceptionIncorrectColor& e) {
        LogToFile(e.what());
        return false;
    }
    catch (const Exception& e) {
        LogToFile(e.what());
        return false;
    }
}

std::string Color::GetColor() {
    return this->color_;
}

Volume::Volume() {};

Volume::Volume(int volume) {
    this->volume_ = volume;
}

bool Volume::SetVolume(int volume) {
    return SetSingleValue(volume, "The volume must be greater then zero!", this->volume_);
}
int Volume::GetVolume() const {
    return this->volume_;
}

void SetIntegerNumber(int integer_number, const char * description) {
    if (integer_number <0){
        throw ExceptionIncorrectSize(description);
    }
}
void SetPercent(int percentage) {
    if (percentage < 0 || percentage > 100) {
        throw ExceptionIncorrectProcent("Percentage must be between 0 and 100!");
    }
}

bool SetSinglePercent(int procent, int & value) {
    try {
        SetPercent(procent);
        value = procent;
        return true;
    }
    catch (const ExceptionIncorrectProcent& e) {
        LogToFile(e.what());
        return false;
    }
    catch (const Exception& e) {
        LogToFile(e.what());
        return false;
    }
}

bool SetSingleValue(int integer_number, const char * description, int &value) {
    try {
        SetIntegerNumber(integer_number, description);
        value = integer_number;
        return true;
    }
    catch (const ExceptionIncorrectSize& e) {
        LogToFile(e.what());
        return false;
    }
    catch (const Exception& e) {
        LogToFile(e.what());
        return false;
    }
}

bool CheckIsStatementCorrect(const std::vector<std::string>& vector_of_string, std::string& statement) {
    for (auto &good_statement : vector_of_string) {
        ToLower(statement);
        if (good_statement==statement) {
            return true;
        }
    }
    return false;
}

void ToLower(std::string& str) {
    std::ranges::transform(str, str.begin(), ::tolower);
}

int GetNewValueAfterMultiplication(int number, int procent) {
    return int(number * procent/100);
}

double CalculateTheSpeedOfSoundInSpecialTemperature(double temperature) {
    return speed_of_sound+0.61*temperature;
}

bool LogToFile(const char * message) {
    std::ofstream file;
    file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        file.open(PATH_TO_FILE, std::ios::app);
        file << std::endl<< message<<std::endl;
        file.close();
        return true;
    }
    catch (...) {return false;}
}
