#pragma once
#include <iostream>

class CarPart
{
protected:
	size_t id;
	char* manufacturer;
	char* description;

	void free();
	void copyFrom(const CarPart& other);
	void moveFrom(CarPart&& other);
public:
	CarPart();
	CarPart(size_t id, const char* manufacturer, const char* description);
	CarPart(const CarPart& other);
	CarPart& operator=(const CarPart& other);
	CarPart(CarPart&& other) noexcept;
	CarPart& operator=(CarPart&& other) noexcept;
	~CarPart();

	size_t getId() const;
	const char* getManufacturer() const;
	const char* getDescription() const;

	friend std::ostream& operator<<(std::ostream& os, const CarPart& other);
};
