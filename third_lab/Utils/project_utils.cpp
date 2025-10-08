#include "project_utils.h"
#include <algorithm>
#include <fstream>
#include <iostream>

void DefaultProjectSettings::LogFile(const char *msg, const std::string &file_name) {
	try {
		std::ofstream file(file_name, std::ios::app);
		file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
		file << std::endl << msg << std::endl;
		file.close();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void DefaultProjectSettings::ClearFile(const std::string &file_name) {
	try {
		std::ofstream file(file_name, std::ios::trunc);
		file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
		file.close();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

bool DefaultProjectSettings::CheckIsStatementInAllowed(const std::string &statement, const std::unordered_set<std::string> &allowed_values) {
	return allowed_values.contains(statement);
}

void DefaultProjectSettings::ToLower(std::string &str) {
	std::ranges::transform(str, str.begin(),::tolower);
}

std::string DefaultProjectSettings::GetRealTime() {
	const time_t realtime = time(nullptr);
	const struct tm tm = *localtime(&realtime);
	return std::to_string(tm.tm_hour) + ":" + std::to_string(tm.tm_min);
}

void Menu::PrintMainMenu() {
	std::cout << std::endl << "===============Social Network Art===============" << std::endl;
	std::cout << std::endl << "1 - View Profile";
	std::cout << std::endl << "2 - View Friends";
	std::cout << std::endl << "3 - View groups and chat";
	std::cout << std::endl << "4 - Check profile of Friends";
	std::cout << std::endl << "5 - Delete Friends";
	std::cout << std::endl << "6 - Subscribe new person";
	std::cout << std::endl << "7 - Refactor your profile";
	std::cout << std::endl << "8 - Logout";
	std::cout << std::endl << "9 - Exit";
	std::cout << std::endl << "==================================================" << std::endl;
}

void Menu::PrintHelp() {
	std::cout << std::endl << "==============What is Art==========="<<std::endl;
	std::cout << "The Art is new social network which should help people communicate, with each other."<<std::endl;
	std::cout<<"This is console app."<<std::endl;
}

void Menu::PrintVersion() {
	std::cout << std::endl<< NUMBER_OF_VERSION<<std::endl;
}