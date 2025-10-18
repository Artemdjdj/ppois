#include "menu.h"
#include <iostream>
#include "../Utils/project_utils.h"
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
    std::cout << std::endl << "==============What is Art===========" << std::endl;
    std::cout << "The Art is new social network which should help people communicate, with each other." << std::endl;
    std::cout << "This is console app." << std::endl;
}

void Menu::PrintVersion() {
    std::cout << std::endl << NUMBER_OF_VERSION << std::endl;
}
