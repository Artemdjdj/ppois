#include "project_settings.h"
#include <fstream>
#include <iostream>

int CheckFileLog(std::string file_name) {
	std::ofstream file(NAME_OF_FILE_LOGS_GENERATE_ID, std::ios::trunc);
	if (!file.is_open()) {
		std::cerr << "Ошибка открытия файла: " << NAME_OF_FILE_LOGS_GENERATE_ID << std::endl;
		return 1;
	}
	file.close();
	return 0;
}
