#ifndef _AIRBNB_H
#define _AIRBNB_H

#include "Accommodation.h"

class AirBnB {
public:
	AirBnB(Accommodation* accommodations, size_t size, size_t capacity);
	AirBnB();
	AirBnB(const AirBnB& other);
	AirBnB& operator=(const AirBnB& other);
	~AirBnB();

	void setAccommodation(Accommodation* accommodations, size_t size, size_t capacity);
	void setSize(size_t size);
	void setCapacity(size_t capacity);

	const Accommodation* getAccommodation() const;
	size_t getSize() const;
	size_t getCapacity() const;
	double getTotal() const;

	void addAccommodation(const Accommodation& accommodation);
	void reserveById(size_t id, size_t days);
	void cancelReservationById(size_t id);
	double getTotalPriceForAllReservations() const;
	Accommodation findNearestAccommodation(double userX, double userY) const;
	void removeAccommodationById(size_t id);

private:
	Accommodation* accommodations;
	size_t size;
	size_t capacity;
	double total;

	void resize();
	void copyFrom(const AirBnB& other);
	void freeAccommodations();
	void free();
};

#endif // !_AIRBNB_H
