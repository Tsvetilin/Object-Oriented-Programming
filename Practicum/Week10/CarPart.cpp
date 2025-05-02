#include "CarPart.h"
#include <iostream>
#pragma warning(disable:4996)

void CarPart::free()
{
	delete[] manufacturer;
	delete[] description;
	id = 0;
}

void CarPart::copyFrom(const CarPart& other)
{
	id = other.id;
	manufacturer = new char[strlen(other.manufacturer) + 1];
	strcpy(manufacturer, other.manufacturer);
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
}

void CarPart::moveFrom(CarPart&& other)
{
	id = other.id;
	manufacturer = other.manufacturer;
	description = other.description;
	other.manufacturer = nullptr;
	other.description = nullptr;
	other.id = 0;
}

CarPart::CarPart()
{
	id = 0;
	manufacturer = new char[1];
	description = new char[1];
	strcpy(manufacturer, "");
	strcpy(description, "");
}

CarPart::CarPart(size_t id, const char* manufacturer, const char* description)
{
	this->id = id;
	this->manufacturer = new char[strlen(manufacturer) + 1];
	this->description = new char[strlen(description) + 1];
	strcpy(this->manufacturer, manufacturer);
	strcpy(this->description, description);
}

CarPart::CarPart(const CarPart& other)
{
	copyFrom(other);
}

CarPart& CarPart::operator=(const CarPart& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

CarPart::CarPart(CarPart&& other) noexcept
{
	moveFrom(std::move(other));
}

CarPart& CarPart::operator=(CarPart&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

CarPart::~CarPart()
{
	delete[] manufacturer;
	delete[] description;
	id = 0;
}

size_t CarPart::getId() const
{
	return id;
}

const char* CarPart::getManufacturer() const
{
	return manufacturer;
}

const char* CarPart::getDescription() const
{
	return description;
}

std::ostream& operator<<(std::ostream& os, const CarPart& other)
{
	os << "(" << other.getId() << ")" << " by " << other.getManufacturer() << " - " << other.getDescription() <<" - ";
	return os;
}

