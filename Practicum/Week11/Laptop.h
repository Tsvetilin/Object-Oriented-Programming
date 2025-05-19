#ifndef LAPTOP_H
#define LAPTOP_H

#include<iostream>
#include "Computer.h"

class Laptop : public Computer {
public:
    Laptop(double processorPower, const char* videoCardModel, int supplyPower, int RAM);
	Laptop() = default;
    void printType() const override;
    const char* const* getPeripherals() const override;

private:
    const char* peripherals[3] = { "Mouse pad", "Keyboard", "Monitor" };
};

#endif // !_LAPTOP_H