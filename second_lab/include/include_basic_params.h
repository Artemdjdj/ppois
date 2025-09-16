

#ifndef INCLUDE_BASIC_PARAMS_H
#define INCLUDE_BASIC_PARAMS_H

#include <string>
#include <vector>
using namespace std;
const std::vector<std::string> colors = {
    "blue", "black", "grey", "green", "red", "orange", "brown"
};
class BasicParams {
private:
    int height{0};
    int width{0};
    void set_height_private(int height);
    void set_width_private(int width);
public:
    BasicParams(int height, int width);
    BasicParams();
    bool set_height(int height);
    bool set_width(int width);
    bool set_size(int height, int width);
    int get_height();
    int get_width();
    void get_size(int & height, int & width);
};

class Color {
private:
    string color;
    void set_color_private(string color);
public:
    Color(string color);
    Color();
    bool set_color(string color);
    string get_color();
};
bool check_color(string& color);
void ToLower(string& str);
bool log_to_file(const char * message);
#endif //INCLUDE_BASIC_PARAMS_H
