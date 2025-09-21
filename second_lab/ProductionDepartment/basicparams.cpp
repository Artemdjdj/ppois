#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "Exceptions/exceptions.h"
#include "basic_params.h"
#include "settings.h"

BasicParams::BasicParams(int height, int width) {
    this->height = height;
    this->width = width;
}
BasicParams::BasicParams(){}

bool BasicParams::set_height(int height) {
    return set_single_value(height, "The height must be greater then zero!", this->height);
}

bool BasicParams::set_width(int width) {
    return set_single_value(width, "The width must be greater then zero!", this->width);
}

bool BasicParams::set_size(int height,int width) {
    if (!set_height(height)) return false;
    return set_width(width);
}

int BasicParams::get_height() const {
    return this->height;
}

int BasicParams::get_width() const {
    return this->width;
}

void BasicParams::get_size(int & height, int & width) const {
    height = this->height;
    width = this->width;
}

Color::Color(std::string color) {
    this->color = color;
}

Color::Color(){}

void Color::set_color_private(std::string color) {
    if (!check_is_statement_correct(colors,color)) {
        throw ExceptionIncorrectColor("This color is not correct!");
    }
    this->color = color;
}
bool Color::set_color(std::string color){
    try {
        set_color_private(color);
        return true;
    }
    catch (const ExceptionIncorrectColor& e) {
        log_to_file(e.what());
        return false;
    }
    catch (const Exception& e) {
        log_to_file(e.what());
        return false;
    }
}

std::string Color::get_color() {
    return this->color;
}

Volume::Volume() {};

Volume::Volume(int volume) {
    this->volume = volume;
}

bool Volume::set_volume(int volume) {
    return set_single_value(volume, "The volume must be greater then zero!", this->volume);
}
int Volume::get_volume() const {
    return this->volume;
}

void set_integer_number(int integer_number, const char * description) {
    if (integer_number <0){
        throw ExceptionIncorrectSize(description);
    }
}
void set_procent(int percentage) {
    if (percentage < 0 || percentage > 100) {
        throw ExceptionIncorrectProcent("Percentage must be between 0 and 100!");
    }
}

bool set_single_procent(int procent, int & value) {
    try {
        set_procent(procent);
        value = procent;
        return true;
    }
    catch (const ExceptionIncorrectProcent& e) {
        log_to_file(e.what());
        return false;
    }
    catch (const Exception& e) {
        log_to_file(e.what());
        return false;
    }
}

bool set_single_value(int integer_number, const char * description, int &value) {
    try {
        set_integer_number(integer_number, description);
        value = integer_number;
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

bool check_is_statement_correct(const std::vector<std::string>& vector_of_string, std::string& statement) {
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

int get_new_value_after_multiplication(int number, int procent) {
    return int(number * procent/100);
}

double calculate_the_speed_of_sound_in_special_temperature(double temperature) {
    return speed_of_sound+0.61*temperature;
}

bool log_to_file(const char * message) {
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
