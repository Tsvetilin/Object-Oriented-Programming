#pragma once
#include "CarPart.h"

class Battery : CarPart
{
private:
	size_t capacity;
	char* batteryId;

	void free();
	void copyFrom(const Battery& other);
	void moveFrom(Battery&& other);
public:
	Battery(size_t id, const char* manufacturer, const char* description, size_t capcity,
		const char* batteryId);
	Battery(const Battery& other);
	Battery& operator=(const Battery& other);
	Battery(Battery&& other);
	Battery& operator=(Battery&& other);
	~Battery();

	friend std::ostream& operator<<(std::ostream& os, const Battery& other);
};

