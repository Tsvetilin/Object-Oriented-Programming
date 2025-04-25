#include "AirBnb.h"
#include<stdexcept>

void AirBnb::copyFrom(const AirBnb& other)
{
	size = other.size;
	places = new Accommodation[size];
	for (size_t i = 0; i < size; i++)
	{
		places[i] = other.places[i];
	}
}

void AirBnb::free()
{
	size = 0;
	delete[] places;
}

size_t AirBnb::findPlaceIndex(size_t id) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (places[i].getId() == id) return i;
	}
	throw std::invalid_argument("Invalid Id");
}

size_t AirBnb::getDiffPoints(const Point a,const  Point b) const
{
	int diff = (a.x - b.x) + (a.y - b.y);
	return diff > 0 ? diff : -diff;
}

AirBnb::AirBnb()
{
	places = nullptr;
	size = 0;
}

AirBnb::AirBnb(Accommodation* places, size_t size)
{
	this->size = size;
	places = new Accommodation[size];
	for (size_t i = 0; i < size; i++)
	{
		this->places[i] = places[i];
	}
}

AirBnb::AirBnb(const AirBnb& other)
{
	copyFrom(other);
}

AirBnb& AirBnb::operator=(const AirBnb& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

AirBnb::~AirBnb()
{
	free();
}

void AirBnb::addPlace(Accommodation place)
{
	size++;
	Accommodation* res = new Accommodation[size];
	for (size_t i = 0; i < size-1; i++)
	{
		res[i] = places[i];
	}
	res[size - 1] = place;
	delete[] places;
	places = res;
}

void AirBnb::makeReservation(size_t id, size_t days)
{
	size_t index = findPlaceIndex(id);
	places[index].makeReservation(days);
}

void AirBnb::removeReservation(size_t id)
{
	size_t index = findPlaceIndex(id);
	places[index].removeReservation();
}

double AirBnb::getIncome() const
{
	double sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += places[i].getPrice();
	}
	return sum;
}

Accommodation AirBnb::findClosest(Point p) const
{
	size_t diff = INT_MAX;
	size_t index = size;
	for (size_t i = 0; i < size; i++)
	{
		if (getDiffPoints(this->places[i].getPoint(), p) < diff)
		{
			index = i;
		}
	}
	if (index >= size || index < 0) throw std::invalid_argument("Cannot found place!");
	return places[index];
}

void AirBnb::removePlace(size_t id)
{
	size--;
	Accommodation* res = new Accommodation[size];
	size_t index = findPlaceIndex(id);
	std::swap(places[index], places[size]);
	for (size_t i = 0; i < size; i++)
	{
		res[i] = places[i];
	}
	delete[] places;
	places = res;
}
