#include "Computer.h"
#include <iostream>
#pragma warning(disable:4996)

void Computer::free()
{
	delete[] GPU;
	GPU = nullptr;
	CPU = 0;
	PSU = 0;
	RAM= 0;
}

void Computer::copyFrom(const Computer& other)
{
	CPU = other.CPU;
	PSU = other.PSU;
	RAM = other.RAM;
	GPU = new char[strlen(other.GPU) + 1];
	strcpy(GPU, other.GPU);
}

void Computer::moveFrom(Computer&& other)
{
	CPU = other.CPU;
	PSU = other.PSU;
	RAM = other.RAM;
	GPU = other.GPU;
	other.GPU = nullptr;
}

Computer::Computer()
{
	GPU = new char[1];
	strcpy(GPU, "");
	CPU = 0;
	PSU = 0;
	RAM = 0;
}

Computer::Computer(double CPU, const char* GPU, size_t PSU, size_t RAM)
{
	this->GPU = new char[strlen(GPU) + 1];
	strcpy(this->GPU, GPU);
	this->CPU = CPU;
	this->PSU = PSU;
	this->RAM = RAM;
}

Computer::Computer(const Computer& other)
{
	copyFrom(other);
}

Computer& Computer::operator=(const Computer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Computer::Computer(Computer&& other) noexcept
{
	moveFrom(std::move(other));
}

Computer& Computer::operator=(Computer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Computer::~Computer()
{
	free();
}

void Computer::setCPU(double CPU)
{
	this->CPU = CPU;
}

void Computer::setGPU(const char* GPU)
{
	this->GPU = new char[strlen(GPU) + 1];
	strcpy(this->GPU, GPU);
}

void Computer::setPSU(size_t PSU)
{
	this->PSU = PSU;
}

void Computer::setRAM(size_t RAM)
{
	this->RAM = RAM;
}
