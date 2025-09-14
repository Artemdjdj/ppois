
#include "include_basic_params.h"
#include "include_wheel.h"
#include <string>
#include <iostream>
using namespace std;

bool BrakeShoe::check_type_of_material(string material) {
    for (auto &good_material : type_of_materials_to_brake_shoe) {
        if (ToLower(material) == good_material) {
            return true;
        }
    }
    return false;
}
BrakeShoe::BrakeShoe():BasicParams(), Color() {}
BrakeShoe::BrakeShoe(int height, int width, string material, string color):BasicParams(height, width), Color(color) {
    this->type_of_material = material;
}
BrakeShoe::BrakeShoe(string material):BasicParams() {
    this->type_of_material = material;
}


// int main() {
//     BrakeShoe brake_shoe = BrakeShoe(45, 56, "ceramic", "red");
//     string color = brake_shoe.get_color();
//     cout << color << endl;
//     brake_shoe.set_color("green");
//     cout << brake_shoe.get_color() << endl;
//     return 0;
// }