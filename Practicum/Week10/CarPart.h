#ifndef _CARPART_H
#define _CARPART_H

#include<iostream>
#include<cstring>
#include<stdexcept>

class CarPart {
public:
	CarPart(int id, const char* manufacturer, const char* description);
	CarPart();
	CarPart(const CarPart& other);
	CarPart& operator=(const CarPart& other);
	CarPart(CarPart&& other) noexcept;
	CarPart& operator=(CarPart&& other) noexcept;
	~CarPart();

	void setId(int id);
	void setManufacturer(const char* manufacturer);
	void setDescription(const char* description);

	int getId() const;
	const char* getDescription() const;
	const char* getManufacturer() const;

	friend std::ostream& operator<<(std::ostream& os, const CarPart& carPart);

private:
	int id;
	char* manufacturer;
	char* description;

	void copyFrom(const CarPart& other);
	void moveFrom(CarPart&& other) noexcept;
	void freeManufacturer();
	void freeDescription();
	void free();
};

#endif // !_CARPART_H
