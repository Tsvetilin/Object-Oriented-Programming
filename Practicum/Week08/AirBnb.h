#pragma once
#include "Accommodation.h"

class AirBnb
{
private:
	Accommodation* places;
	size_t size;

	void copyFrom(const AirBnb& other);
	void free();
	size_t findPlaceIndex(size_t id) const;
	size_t getDiffPoints(const Point a, const Point b) const;
public:
	AirBnb();
	AirBnb(Accommodation* places,size_t size);
	AirBnb(const AirBnb& other);
	AirBnb& operator=(const AirBnb& other);
	~AirBnb();

	void addPlace(Accommodation place);
	void makeReservation(size_t id,size_t days);
	void removeReservation(size_t id);
	double getIncome() const;
	Accommodation findClosest(Point p) const;
	void removePlace(size_t id);

};

