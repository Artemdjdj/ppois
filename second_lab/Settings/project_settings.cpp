#include <fstream>
#include <iostream>

int CheckFileLog(std::string file_name) {
	std::ofstream file(file_name, std::ios::trunc);
	if (!file.is_open()) {
		std::cerr << "Ошибка открытия файла: " <<file_name << std::endl;
		return 1;
	}
	file.close();
	return 0;
}
