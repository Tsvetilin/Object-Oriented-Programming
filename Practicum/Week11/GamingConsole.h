#ifndef _GAMINGCONSOLE_H
#define _GAMINGCONSOLE_H

#include<iostream>
#include "Computer.h"

class GamingConsole : public Computer {
public:
	GamingConsole(double processorPower, const char* videoCardModel, int supplyPower, int RAM);
	GamingConsole() = default;
	void printType() const override;
	const char* const* getPeripherals() const override;

private:
	const char* peripherals[2] = { "Joystick", "Monitor" };
};

#endif // !_GAMINGCONSOLE_H