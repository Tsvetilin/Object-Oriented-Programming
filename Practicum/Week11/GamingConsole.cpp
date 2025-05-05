#include "GamingConsole.h"

GamingConsole::GamingConsole(double processorPower, const char* videoCardModel, int supplyPower, int RAM) : Computer(processorPower, videoCardModel, supplyPower, RAM) {
}

void GamingConsole::printType() const {
	std::cout << "This is gaming console!" << std::endl;
}

const char* const* GamingConsole::getPeripherals() const {
	return this->peripherals;
}