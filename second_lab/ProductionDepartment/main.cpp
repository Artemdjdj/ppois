#include <iostream>
#include "include_door.h"
#include "include_mirror.h"
#include "include_basic_params.h"
#include "include_wheel.h"
using namespace std;
int main() {
    BrakeShoe brake_shoe = BrakeShoe(45, 56, "ceramic", "red");
    string color = brake_shoe.get_color();
    cout << color << endl;
    brake_shoe.set_color("green");
    cout << brake_shoe.get_color() << endl;
    return 0;
}