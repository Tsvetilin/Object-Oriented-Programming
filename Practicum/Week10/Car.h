#pragma once
#include "FuelTank.h"
#include "Tire.h"
#include "Batterry.h"
#include "Engine.h"

static const uint8_t TIRES_CNT = 4;
static const double RaceDist = 0.4;

class Car : FuelTank,Engine,Battery
{
private:
	Tire tires[TIRES_CNT];
	double drivenKm;
	size_t weigth;
public:
	Car(size_t id,const char* manufacturer,const char* description,
		uint16_t width, uint16_t profile, uint16_t diameter, size_t hp,
		size_t capacity, const char* batteryId,double fuelCapacity,
		double drivenKM,size_t weight);

	double getFuelLevel() const;
	void drive(double km);

	friend Car* dragRace(Car* car1, Car* car2);
};

