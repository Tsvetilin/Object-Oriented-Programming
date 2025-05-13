#include "Batterry.h"
#include <iostream>
#pragma warning(disable:4996)

void Battery::free()
{
	delete[] batteryId;
	capacity = 0;
	CarPart::free();
}

void Battery::copyFrom(const Battery& other)
{
	batteryId = new char[strlen(other.batteryId) + 1];
	strcpy(batteryId, other.batteryId);
	capacity = other.capacity;
	CarPart::copyFrom(other);
}

void Battery::moveFrom(Battery&& other)
{
	batteryId = other.batteryId;
	capacity = other.capacity;
	other.batteryId = nullptr;
	other.capacity = 0;
	CarPart::moveFrom(std::move(other));
}

Battery::Battery(size_t id, const char* manufacturer, const char* description, size_t capcity, const char* batteryId)
	: CarPart(id, manufacturer, description)
{
	this->capacity = capcity;
	this->batteryId = new char[strlen(batteryId) + 1];
	strcpy(this->batteryId, batteryId);
}

Battery::Battery(const Battery& other)
{
	copyFrom(other);
}

Battery& Battery::operator=(const Battery& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Battery::Battery(Battery&& other)
{
	moveFrom(std::move(other));
}

Battery& Battery::operator=(Battery&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Battery::~Battery()
{
	free();
}

std::ostream& operator<<(std::ostream& os, const Battery& other)
{
	os << CarPart(other) << other.capacity << "Ah" << std::endl;
	return os;
}
