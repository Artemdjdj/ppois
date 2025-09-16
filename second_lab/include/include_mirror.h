//
// Created by Redmi on 14.09.2025.
//

#ifndef INCLUDE_MIRROR_H
#define INCLUDE_MIRROR_H
#include <iostream>
#include <string>
#include "include_basic_params.h"
using namespace std;

class Mirror:public BasicParams {
private:
    string serial_number;
    int thickness{0};
    bool is_tinting{false};
    void set_thickness_private(int thickness);
    void set_serial_number_private(string serial_number);
public:
    Mirror(int height, int width, int thickness, bool is_tinting, string serial_number);
    Mirror();
    void make_mirror_tinting();
    bool set_thickness(int thickness);
    void make_tinting();
    void clear_tinting();
    bool set_serial_number(string serial_number);
    string get_serial_number();
    void get_information_about_mirror(int &height, int&width, int&thickness, bool&is_tinting, string &serial_number);
    bool check_serial_number(const string &serial_number);
};

#endif //INCLUDE_MIRROR_H
