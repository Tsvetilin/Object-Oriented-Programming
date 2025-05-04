#ifndef _PC_H
#define _PC_H

#include "Computer.h"
#include<iostream>

class PC : public Computer {
public:
    PC(double processorPower, const char* videoCardModel, int supplyPower, int RAM);
	PC() = default;
    void printType() const override;
    const char* const* getPeripherals() const override;

private:
    const char* peripherals[4] = { "Mouse", "Keyboard", "Microphone", "Headphones" };
};

#endif // !_PC_H