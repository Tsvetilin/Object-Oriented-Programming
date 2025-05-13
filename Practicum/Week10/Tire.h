#ifndef _TIRE_H
#define _TIRE_H

#include "CarPart.h"
#include<stdexcept>
#include<iostream>

const double MIN_TIRE_WIDTH = 155;
const double MAX_TIRE_WIDTH = 365;
const int MIN_TIRE_PROFILE = 30;
const int MAX_TIRE_PROFILE = 80;
const int MIN_TIRE_DIAMETER = 13;
const int MAX_TIRE_DIAMETER = 21;

class Tire : public CarPart {
public:
	Tire(int id, const char* manufacturer, const char* description, double width, int profile, int diameter);
	Tire();
	Tire(const Tire& other);
	Tire& operator=(const Tire& other);
	Tire(Tire&& other) noexcept;
	Tire& operator=(Tire&& other) noexcept;
	~Tire();

	void setWidth(double width);
	void setProfile(int profile);
	void setDiameter(int diameter);

	double getWidth() const;
	int getProfile() const;
	int getDiameter() const;

	friend std::ostream& operator<<(std::ostream& os, const Tire& tire);

private:
	double width;
	int profile;
	int diameter;

	void copyFrom(const Tire& other);
	void moveFrom(Tire&& other) noexcept;
	void freeTire();
};

#endif // !_TIRE_H
