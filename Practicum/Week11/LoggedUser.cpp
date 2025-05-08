#include "LoggedUser.h"
#include <iostream>
#include <stdexcept>
#pragma warning(disable:4996)

LoggedUser::LoggedUser(const char* pass) : Player()
{
	if (!pass || strlen(pass) > PASS_LEN) throw std::invalid_argument("Invalid password");
	strcpy(this->pass, pass);
	isLoged = false;
}

void LoggedUser::login()
{
	int id;
	char input[BUFF_LEN];
	std::cout << "ID: ";
	std::cin >> id;
	std::cout << "\nPass: ";
	std::cin >> input;
	if (this->id == id && strcmp(pass, input) == 0) isLoged = true;
}

void LoggedUser::logout()
{
	isLoged = false;
}

void LoggedUser::setNewPass(const char* pass)
{
	if (!pass || strlen(pass) > PASS_LEN) throw std::invalid_argument("Invalid password");
	strcpy(this->pass, pass);
}
