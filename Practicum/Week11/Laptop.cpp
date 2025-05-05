#include "Laptop.h"

Laptop::Laptop(double processorPower, const char* videoCardModel, int supplyPower, int RAM): Computer(processorPower, videoCardModel, supplyPower, RAM) {
}

void Laptop::printType() const {
	std::cout << "This is laptop." << std::endl;
}

const char* const* Laptop::getPeripherals() const {
	return this->peripherals;
}
