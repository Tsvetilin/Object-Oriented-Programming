#include "Prize.h"
#include <iostream>
#include <fstream>


Prize::Prize(double price, size_t points)
{
	this->price = price;
	this->points= points;
}

void Penguin::visualize() 
{
	if (points >= neededPoints)
	{
		std::cout << "Penguin won";
		points -= neededPoints;
	}
}

void Pacman::visualize() 
{
	if (points >= neededPoints)
	{
		std::cout << "Pacman won";
		points -= neededPoints;
	}
}

void ComputerBoy::visualize()
{
	if (points >= neededPoints)
	{
		std::cout << "ComputerBoy won";
		points -= neededPoints;
	}
}

void Squidward::visualize()
{
	if (points >= neededPoints)
	{
		std::cout << "Squidward won";
		points -= neededPoints;
	}
}

void Sylvester::visualize()
{
	if (points >= neededPoints)
	{
		std::cout << "Sylvester won";
		points -= neededPoints;
	}
}
