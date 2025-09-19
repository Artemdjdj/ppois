

#ifndef INCLUDE_BASIC_PARAMS_H
#define INCLUDE_BASIC_PARAMS_H

#include <string>
#include <vector>
#include "include_exceptions.h"

#include "settings.h"

class BasicParams {
private:
    int height{0};
    int width{0};
    // void set_height_private(int height);
    // void set_width_private(int width);
public:
    BasicParams(int height, int width);
    BasicParams();
    bool set_height(int height);
    bool set_width(int width);
    bool set_size(int height, int width);
    int get_height() const;
    int get_width() const;
    void get_size(int & height, int & width) const;
};

class Color {
private:
    std::string color;
    void set_color_private(std::string color);
public:
    Color(std::string color);
    Color();
    bool set_color(std::string color);
    std::string get_color();
};

class Volume {
private:
    int volume{0};
public:
    Volume();
    Volume(int volume);
    bool set_volume(int volume);
    int get_volume() const;
};

void set_integer_number(int integer_number, const char * description);

void set_procent(int percentage);

bool set_single_procent(int procent, int & value);

bool set_single_value(int integer_number, const char * description, int &value);

void ToLower(std::string& str);

bool log_to_file(const char * message);

bool check_is_statement_correct(const std::vector<std::string>& vector_of_string, std::string& statement);

int get_new_value_after_multiplication(int number, int procent);

double calculate_the_speed_of_sound_in_special_temperature(double temperature);
#endif //INCLUDE_BASIC_PARAMS_H
