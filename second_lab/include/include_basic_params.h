

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
public:
    BasicParams(int height, int width);
    BasicParams();
    void set_height_basic_params(int height);
    void set_width_basic_params(int width);
    void set_size(int height, int width);
    int get_height();
    int get_width();
    void get_size(int & height, int & width);
};

class Color {
private:
    string color;
public:
    Color(string color);
    Color();
    void set_color(string color);
    string get_color();
};
bool check_color(string color);
string ToLower(string str);
#endif //INCLUDE_BASIC_PARAMS_H
