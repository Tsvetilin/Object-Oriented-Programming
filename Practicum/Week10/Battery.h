#ifndef _BATTERY_H
#define _BATTERY_H

#include "CarPart.h"
#include<stdexcept>
#include<iostream>
#include<cstring>

class Battery : public CarPart {
public:
	Battery(int id, const char* manufacturer, const char* description, int capacity, const char* batteryId);
	Battery();
	Battery(const Battery& other);
	Battery& operator=(const Battery& other);
	Battery(Battery&& other) noexcept;
	Battery& operator=(Battery&& other) noexcept;
	~Battery();

	void setCapacity(int capacity);
	void setBatteryId(const char* batteryId);

	int getCapacity() const;
	const char* getBatteryId() const;

	friend std::ostream& operator<<(std::ostream& os, const Battery& battery);

private:
	int capacity;
	char* batteryId;

	void copyFrom(const Battery& other);
	void moveFrom(Battery&& other) noexcept;
	void freeBatteryId();
	void freeBattery();
};

#endif // !_BATTERY_H
