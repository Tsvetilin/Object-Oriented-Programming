#ifndef _CAR_H
#define _CAR_H

#include "Tire.h"
#include "Engine.h"
#include "Battery.h"
#include "FuelTank.h"
#include "InsufficientFuelError.h"
#include<iostream>
#include<stdexcept>

const size_t MAX_NUMBER_OF_TIRES = 4;
const double EPSILON = 0.0001;

class Car {
public:
	Car(const FuelTank& fuelTank, const Engine& engine, const Tire* tires, const Battery& battery, double mileage, double weight);
	Car();
	Car(const Car& other);
	Car& operator=(const Car& other);
	Car(Car&& other) noexcept;
	Car& operator=(Car&& other) noexcept;
	~Car();

	void setFuelTank(const FuelTank& fuelTank);
	void setEngine(const Engine& engine);
	void setTires(const Tire* tires);
	void setBattery(const Battery& battery);
	void setMileage(double mileage);
	void setWeight(double weight);

	FuelTank& getFuelTank();  // No const version
	const Engine& getEngine() const;
	const Tire* getTires() const;
	const Battery& getBattery() const;
	double getMileage() const;
	double getWeight() const;

	void drive(double km);

	friend Car* dragRace(Car* car1, Car* car2);

	void printCarInfo() const;

private:
	FuelTank fuelTank;
	Engine engine;
	Tire tires[MAX_NUMBER_OF_TIRES];
	Battery battery;
	double mileage;
	double weight;

	void copyFrom(const Car& other);
	void moveFrom(Car&& other) noexcept;
	void freeCar();
};

#endif // !_CAR_H
