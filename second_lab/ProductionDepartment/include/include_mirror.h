//
// Created by Redmi on 14.09.2025.
//

#ifndef INCLUDE_Mirror_H
#define INCLUDE_Mirror_H
#include <string>
#include "include_basic_params.h"

class Mirror:public BasicParams {
private:
    std::string serial_number;
    int thickness{0};
    bool is_tinting{false};
    void set_serial_number_private(std::string serial_number);
    bool check_serial_number(const std::string &serial_number);
public:
    Mirror(int height, int width, int thickness, bool is_tinting, std::string serial_number);
    Mirror();
    void make_mirror_tinting();
    bool set_thickness(int thickness);
    void make_tinting();
    void clear_tinting();
    bool set_serial_number(std::string serial_number);
    std::string get_serial_number();
    void get_information_about_mirror(int &height, int&width, int&thickness, bool&is_tinting, std::string &serial_number);
};

#endif //INCLUDE_Mirror_H
