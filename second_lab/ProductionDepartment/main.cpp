#include <iostream>
#include "CarBody/door.h"
#include "basic_params.h"
#include "Wheel/wheel.h"

int main() {
	BrakeShoe brake_shoe = BrakeShoe(45, 56, "ceramic", "red");
	std::string color = brake_shoe.GetColor();
	std::cout << color << std::endl;
	brake_shoe.SetColor("green");
	std::cout << brake_shoe.GetColor() << std::endl;
	return 0;
}
