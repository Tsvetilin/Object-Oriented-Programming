#include "Car.h"

Car::Car(size_t id, const char* manufacturer, const char* description, uint16_t width, uint16_t profile, uint16_t diameter, size_t hp, size_t capacity, const char* batteryId, double fuelCapacity, double drivenKM, size_t weigth)
: Engine(id, manufacturer, description, hp),
Battery(id, manufacturer, description, capacity, batteryId),
FuelTank(fuelCapacity)
{
	for (size_t i = 0; i < TIRES_CNT; ++i) 
	{
		tires[i] = Tire(id, manufacturer, description, width, profile, diameter);
	}
	this->weigth = weigth;
	this->drivenKm = drivenKM;
}

double Car::getFuelLevel() const
{
	return this->level;
}

void Car::drive(double km)
{
	consume(km);
	drivenKm -= km;
}

Car* dragRace(Car* car1, Car* car2)
{
	if (car1->getFuelLevel() < RaceDist && car2->getFuelLevel() < RaceDist) return nullptr;
	else if (car1->getFuelLevel() < RaceDist) return car2;
	else if (car2->getFuelLevel() < RaceDist) return car1;

	return (car1->weigth / car1->hp >= car1->weigth / car1->hp) ? car1 : car2;
}
