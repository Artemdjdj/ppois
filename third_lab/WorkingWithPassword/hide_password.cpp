#include "hide_password.h"
#include <windows.h>
#include <conio.h>
#include <iostream>

std::string HidePassword::ReadPassword() {
	std::string password;

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;

	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

	std::cout << "Введите пароль: ";

	char ch;
	while ((ch = _getch()) != '\r') {
		if (ch == '\b') {
			if (!password.empty()) {
				password.pop_back();
				std::cout << "\b \b";
			}
		} else if (ch >= 32 && ch <= 126) {
			password.push_back(ch);
			std::cout << '*';
		}
	}
	SetConsoleMode(hStdin, mode);
	std::cout << std::endl;

	return password;
}