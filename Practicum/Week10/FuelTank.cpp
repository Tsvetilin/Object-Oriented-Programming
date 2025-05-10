#include "FuelTank.h"

void FuelTank::setTotalFuelTankCapacity(double totalCapacity) {
	if (totalCapacity < 0) {
		throw std::invalid_argument("Invalid total fuel tank capacity!");
	}

	this->totalCapacity = totalCapacity;
}

double FuelTank::getTotalFuelTankCapacity() const {
	return this->totalCapacity;
}

double FuelTank::getCurrentFuelTankCapacity() const {
	return this->currentCapacity;
}

void FuelTank::refuel(double amount) {
	if (amount < 0) {
		throw std::invalid_argument("Invalid amount of fuel!");
	}

	if (this->currentCapacity + amount > this->totalCapacity) {
		this->currentCapacity = this->totalCapacity;
	}
	else {
		this->currentCapacity += amount;
	}
}

void FuelTank::useFuel(double amount) {
	if (amount < 0) {
		throw std::invalid_argument("Invalid amount of fuel!");
	}

	if (amount > this->currentCapacity) {
		throw insufficient_fuel_error("Not enough fuel in the tank!");
	}

	this->currentCapacity -= amount;
}

void FuelTank::copyFrom(const FuelTank& other) {
	if (other.totalCapacity < 0) {
		throw std::invalid_argument("Invalid total fuel tank capacity!");
	}

	this->totalCapacity = other.totalCapacity;

	if (other.currentCapacity < 0) {
		throw std::invalid_argument("Invalid current amount of fuel!");
	}

	this->currentCapacity = other.currentCapacity;
}

void FuelTank::moveFrom(FuelTank&& other) noexcept {
	this->totalCapacity = other.totalCapacity;
	this->currentCapacity = other.currentCapacity;

	other.totalCapacity = 0;
	other.currentCapacity = 0;
}

void FuelTank::freeFuelTank() {
	this->totalCapacity = 0;
	this->currentCapacity = 0;
}

FuelTank::FuelTank(int id, const char* manufacturer, const char* description, double totalCapacity): CarPart(id,manufacturer,description) {
	setTotalFuelTankCapacity(totalCapacity);
	this->currentCapacity = totalCapacity;
}

FuelTank::FuelTank(): CarPart() {
	this->currentCapacity = 0;
	this->totalCapacity = 0;
}

FuelTank::FuelTank(const FuelTank& other): CarPart(other) {
	this->copyFrom(other);
}

FuelTank& FuelTank::operator=(const FuelTank& other) {
	if (this != &other) {
		CarPart::operator=(other);
		this->freeFuelTank();
		this->copyFrom(other);
	}

	return *this;
}

FuelTank::FuelTank(FuelTank&& other) noexcept: CarPart(std::move(other)) {
	this->moveFrom(std::move(other));
}

FuelTank& FuelTank::operator=(FuelTank&& other) noexcept {
	if (this != &other) {
		CarPart::operator=(std::move(other));
		this->freeFuelTank();
		this->moveFrom(std::move(other));
	}

	return *this;
}

FuelTank::~FuelTank() {
	this->freeFuelTank();
}

std::ostream& operator<<(std::ostream& os, const FuelTank& fuelTank) {
	const CarPart& base = fuelTank;
	operator<<(os, base);
	os << " - " << "Total fuel tank capacity: " << fuelTank.getTotalFuelTankCapacity() << ", " << "Current amount of capacity in fuel tank: " << fuelTank.getCurrentFuelTankCapacity();
	return os;
}