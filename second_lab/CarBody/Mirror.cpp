#include "include_mirror.h"
Mirror::Mirror(int height, int width, int thickness, bool is_tinting, string serial_number):BasicParams(height, width) {
    this->thickness = thickness;
    this->is_tinting = is_tinting;
    this->serial_number = serial_number;
}
Mirror::Mirror():BasicParams(){}
void Mirror::make_mirror_tinting() {
    is_tinting = true;
    cout << "Mirror is tinting" << endl;
}

void Mirror::set_thickness(int thickness) {
    this->thickness = thickness;
}
void Mirror::set_is_tinting(bool is_tinting) {
    this->is_tinting = is_tinting;
}
bool Mirror::set_serial_number(string serial_number) {
    if (check_serial_number(serial_number)) {
        this->serial_number = serial_number;
        return true;
    }
    return false;
}
void Mirror::get_information_about_mirror(int &height, int&width, int&thickness, bool&is_tinting, string &serial_number) {
    height = get_height();
    width = get_width();
    thickness = this->thickness;
    is_tinting = this->is_tinting;
    serial_number = this->serial_number;
}
bool Mirror::check_serial_number(const string &serial_number) {
    if (serial_number.length()!=8) return false;
    if (!isupper(serial_number[0]) or !isupper(serial_number[1])) return false;
    for (int i =2; i < 8; i++) {
        if (!isdigit(serial_number[i])) {
            return false;
        }
    }
    return true;
}

// int main() {
//     Mirror mirror = Mirror(2,3,5,false, "AC455436");
//     mirror.make_mirror_tinting();
//     bool res = mirror.set_serial_number("A0453434");
//     cout << res << endl;
//
// }
//
