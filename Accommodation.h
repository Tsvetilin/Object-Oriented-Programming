#ifndef _ACCOMMODATION_H
#define _ACCOMMODATION_H

#include "Location.h"
#include<cstring>

enum class Type {
	Apartment,
	Villa,
	Hotel
};

class Accommodation {
public:
	Accommodation(size_t id, const char* name, Type type, Location location, double pricePerNight, bool isAvailable, size_t daysToStay);
	Accommodation();
	Accommodation(const Accommodation& other);
	Accommodation& operator=(const Accommodation& other);
	~Accommodation();

	void setName(const char* name);
	void setType(Type type);
	void setLocation(Location location);
	void setPricePerNight(double pricePerNight);
	void setIsAvailable(bool isAvailable);
	void setDaysToStay(size_t daysToStay);

	size_t getId() const;
	const char* getName() const;
	Type getType() const;
	Location getLocation() const;
	double getPricePerNight() const;
	bool getIfItIsAvailable() const;
	size_t getDaysToStay() const;

	void makeReservation(size_t daysToStay);
	void cancelReservation();
	double getPriceForStay() const;

private:
	static size_t id;
	char* name;
	Type type;
	Location location;
	double pricePerNight;
	bool isAvailable;
	size_t daysToStay;

	void copyFrom(const Accommodation& other);
	void freeName();
	void free();
};

#endif // !_ACCOMMODATION_H
