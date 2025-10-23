#include "menu.h"
#include <iostream>
#include "../Utils/project_utils.h"

void Menu::PrintStartWindow() {
    std::cout << std::endl << "===============Social Network Art===============" << std::endl;
    std::cout << std::endl << "1 - Registration";
    std::cout << std::endl << "2 - Login";
    std::cout << std::endl << "3 - Exit";
    std::cout << std::endl << "================================================" << std::endl;
}

void PrintMenuRefactorUser() {
    std::cout << std::endl << "===============Refactor user===============" << std::endl;
    std::cout << std::endl << "1 - Username";
    std::cout << std::endl << "2 - Telephone number";
    std::cout << std::endl << "3 - Email";
    std::cout << std::endl << "================================================" << std::endl;
}

void PrintMenuRefactorProfile() {
    std::cout << std::endl << "===============RefactorProfile===============" << std::endl;
    std::cout << std::endl << "1 - Location";
    std::cout << std::endl << "2 - Biography";
    std::cout << std::endl << "3 - Gender";
    std::cout << std::endl << "4 - Birthday";
    std::cout << std::endl << "================================================" << std::endl;
}

void Menu::PrintMainMenu() {
    std::cout << std::endl << "===============Social Network Art===============" << std::endl;
    std::cout << std::endl << " 1 - View profile";
    std::cout << std::endl << " 2 - Refactor profile";
    std::cout << std::endl << " 3 - Create new chat";
    std::cout << std::endl << " 4 - Send message";
    std::cout << std::endl << " 5 - Delete chat";
    std::cout << std::endl << " 6 - View all chats";
    std::cout << std::endl << " 7 - Logout";
    std::cout << std::endl << " 8 - Delete account";
    std::cout << std::endl << " 9 - Exit";
    std::cout << std::endl << "================================================" << std::endl;
}

void Menu::PrintHelp() {
    std::cout << std::endl << "==============What is Art===========" << std::endl;
    std::cout << "The Art is new social network which should help people communicate, with each other." << std::endl;
    std::cout << "This is console app." << std::endl;
}

void Menu::PrintVersion() {
    std::cout << std::endl << NUMBER_OF_VERSION << std::endl;
}
