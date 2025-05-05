#include "PC.h"

PC::PC(double processorPower, const char* videoCardModel, int supplyPower, int RAM)
    : Computer(processorPower, videoCardModel, supplyPower, RAM) { }

void PC::printType() const {
    std::cout << "This is a PC." << std::endl;
}

const char* const* PC::getPeripherals() const {
    return peripherals;
}