#include "project_utils.h"
#include <fstream>
#include <iostream>

void LogFile(const char *msg, const std::string &file_name) {
	try {
		std::ofstream file(file_name, std::ios::app);
		file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
		file << msg;
		file.close();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void ClearFile(const std::string &file_name) {
	try {
		std::ofstream file(file_name, std::ios::trunc);
		file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
		file.close();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
