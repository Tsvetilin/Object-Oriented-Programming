#include "Tire.h"
#include <iostream>
#pragma warning(disable:4996)


static const uint16_t MAX_WIDTH = 365;
static const uint16_t MIN_WIDTH = 155;
static const uint16_t MAX_PROFILE = 80;
static const uint16_t MIN_PROFILE = 30;
static const uint16_t MIN_DIAMETER = 13;
static const uint16_t MAX_DIAMETER = 21;



Tire::Tire() : CarPart()
{
	width = 0;
	profile = 0;
	diameter = 0;
}

Tire::Tire(size_t id, const char* manufacturer, const char* description,
	uint16_t width, uint16_t profile, uint16_t diameter) : CarPart(id,manufacturer,description)
{
	width >= MIN_WIDTH && width <= MAX_WIDTH ?  this->width = width : this->width = 0;
	profile >= MIN_PROFILE && profile <= MAX_PROFILE ?  this->profile = profile : this->profile = 0;
	diameter >= MIN_DIAMETER && diameter <= MAX_DIAMETER ?  this->diameter = diameter : this->diameter = 0;
}

std::ostream& operator<<(std::ostream& os, const Tire& other)
{
	os << CarPart(other) << other.width << "/" << other.profile << "R" << other.diameter << std::endl;
	return os;
}
