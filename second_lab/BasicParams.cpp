#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <exception>
#include "include_exceptions.h"
#include "include_basic_params.h"
#include "settings.h"

BasicParams::BasicParams(int height, int width) {
    this->height = height;
    this->width = width;
}
BasicParams::BasicParams(){}

void BasicParams::set_height_private(int height) {
    if (height <0){
        throw ExceptionIncorrectSize("Высота не может быть меньше нуля!");
    }
    this->height = height;
}

void BasicParams::set_width_private(int width) {
    if (width <0){
        throw ExceptionIncorrectSize("Ширина не может быть меньше нуля!");
    }
    this->width = width;
}

bool BasicParams::set_height(int height) {
    try {
        set_height_private(height);
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

bool BasicParams::set_width(int width) {
    try {
        set_width_private(width);
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

bool BasicParams::set_size(int height,int width) {
    try {
        set_height_private(height);
        set_width_private(width);
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

int BasicParams::get_height() {
    return this->height;
}

int BasicParams::get_width() {
    return this->width;
}

void BasicParams::get_size(int & height, int & width) {
    height = this->height;
    width = this->width;
}

Color::Color(std::string color) {
    this->color = color;
}

Color::Color(){}

void Color::set_color_private(std::string color) {
    if (!check_color(color)) {
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

bool check_color(std::string& color) {
    for (auto &good_color : colors) {
        ToLower(color);
        if (good_color==color) {
            return true;
        }
    }
    return false;
}

void ToLower(std::string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

bool log_to_file(const char * message) {
    std::ofstream file;
    file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        file.open(PATH_TO_FILE, std::ios::out );
        file << std::endl<< message<<std::endl;
        file.close();
        return true;
    }
    catch (...) {return false;}
}