#include <iostream>
#include <sqlite3.h>
#include "WorkingWithPassword/hide_password.h"

int main() {
	const std::string my_pass = HidePassword::ReadPassword();
	std::cout << my_pass << std::endl;
	return 0;
}
