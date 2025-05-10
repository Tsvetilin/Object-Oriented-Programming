#ifndef _FUELTANK_H
#define _FUELTANK_H

#include "CarPart.h"
#include<iostream>
#include<stdexcept>
#include "InsufficientFuelError.h"

class FuelTank: public CarPart {
public:
	FuelTank(int id, const char* manufacturer, const char* description, double totalCapacity);
	FuelTank();
	FuelTank(const FuelTank& other);
	FuelTank& operator=(const FuelTank& other);
	FuelTank(FuelTank&& other) noexcept;
	FuelTank& operator=(FuelTank&& other) noexcept;
	~FuelTank();

	void setTotalFuelTankCapacity(double totalCapacity);

	double getTotalFuelTankCapacity() const;
	double getCurrentFuelTankCapacity() const;

	void refuel(double amount);
	void useFuel(double amount);

	friend std::ostream& operator<<(std::ostream& os, const FuelTank& fuelTank);

private:
	int totalCapacity;
	mutable double currentCapacity;

	void copyFrom(const FuelTank& other);
	void moveFrom(FuelTank&& other) noexcept;
	void freeFuelTank();
};
#endif // !_FUELTANK_H