#include <iostream>
#include "CarBody/door.h"
#include "CarBody/mirror.h"
#include "basic_params.h"
#include "wheel/wheel.h"
using namespace std;
int main() {
    BrakeShoe brake_shoe = BrakeShoe(45, 56, "ceramic", "red");
    string color = brake_shoe.get_color();
    cout << color << endl;
    brake_shoe.set_color("green");
    cout << brake_shoe.get_color() << endl;
    return 0;
}