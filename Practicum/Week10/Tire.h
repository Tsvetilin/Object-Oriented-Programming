#pragma once
#include "CarPart.h"
#include <iostream>

class Tire : public CarPart
{
private:
	uint16_t width;
	uint16_t profile;
	uint16_t diameter;
public:
	Tire();
	Tire(size_t id, const char* manufacturer, const char* description,
		uint16_t width, uint16_t profile, uint16_t diameter);

	friend std::ostream& operator<<(std::ostream& os, const Tire& other);
};

