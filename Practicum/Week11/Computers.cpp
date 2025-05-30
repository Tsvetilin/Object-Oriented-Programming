#include "Computers.h"
#include <iostream>

void PC::getComputerType() const
{
	std::cout << "PC";
}

void PC::accessories() const
{
	std::cout << availableAccessories;
}

void Laptop::getComputerType() const
{
	std::cout << "Laptop";
}

void Laptop::accessories() const
{
	std::cout << availableAccessories;
}

void GamingConsole::getComputerType() const
{
	std::cout << "Gaming console";
}

void GamingConsole::accessories() const
{
	std::cout << availableAccessories;
}
