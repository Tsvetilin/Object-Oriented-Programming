#include "Accommodation.h"
#include <iostream>
#pragma warning(disable:4996)


void Accommodation::copyFrom(const Accommodation& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	id = other.id;
	type = other.type;
	point = other.point;
	price = other.price;
	isFree = other.isFree;
	days = other.days;
}

void Accommodation::free()
{
	delete[] name;
	id = 0;
	point = {0,0};
	price = 0;
	isFree = 0;
	days = 0;
}

Accommodation::Accommodation()
{
	name = new char[1];
	strcpy(name, "");
	id = 0;
	type = AccommType::Apartament;
	point = {0,0};
	price = 0;
	isFree = 0;
	days = 0;
}

Accommodation::Accommodation(const Accommodation& other)
{
	copyFrom(other);
}

Accommodation& Accommodation::operator=(const Accommodation& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Accommodation::~Accommodation()
{
	free();
}

void Accommodation::setId(size_t id)
{
	this->id = id;
}

void Accommodation::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Accommodation::setAccommType(AccommType type)
{
	this->type = type;
}

void Accommodation::setPoint(Point p)
{
	point = p;
}

void Accommodation::setPrice(double price)
{
	this->price = price;
}

void Accommodation::setDays(size_t days)
{
	this->days = days;
	isFree = !days;
}

size_t Accommodation::getId() const
{
	return id;
}

const char* Accommodation::getName() const
{
	return name;
}

AccommType Accommodation::getAccommType() const
{
	return type;
}

Point Accommodation::getPoint() const
{
	return point;
}

double Accommodation::getPrice() const
{
	return price;
}

size_t Accommodation::getDays() const
{
	return days;
}

bool Accommodation::getIsFree() const
{
	return isFree;
}

void Accommodation::makeReservation(size_t days)
{
	this->days = days;
	isFree = false;
}

void Accommodation::removeReservation()
{
	days = 0;
	isFree = true;
}

double Accommodation::total() const
{
	return price * days;
}
