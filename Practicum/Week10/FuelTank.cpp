#include "FuelTank.h"
#include "CustomException.h"

FuelTank::FuelTank(double capacity)
{
	this->capacity = capacity;
	level = capacity;
}

void FuelTank::consume(double usage)
{
	if (level > usage) level -= usage;
	else throw insufficient_fuel_error("");
}

void FuelTank::refuel(double add)
{
	if (level + add > capacity) level = capacity;
	level += add;
}