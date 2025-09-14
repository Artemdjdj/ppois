
#include "include_basic_params.h"
#include <string>
#include <algorithm>
using namespace std;
BasicParams::BasicParams(int height, int width) {
    this->height = height;
    this->width = width;
}
BasicParams::BasicParams(){}
void BasicParams::set_height_basic_params(int height) {
    this->height = height;
}
void BasicParams::set_width_basic_params(int width) {
    this->width = width;
}
void BasicParams::set_size(int width, int height) {
    this->height = height;
    this->width = width;
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
Color::Color(string color) {
    this->color = color;
}
Color::Color(){}
void Color::set_color(string color) {
    this->color = color;
}
string Color::get_color() {
    return this->color;
}

bool check_color(string color) {
    for (auto &good_color : colors) {
        if (good_color==ToLower(color)) {
            return true;
        }
    }
    return false;
}
string ToLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}