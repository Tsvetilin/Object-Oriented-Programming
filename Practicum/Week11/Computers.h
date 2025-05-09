#pragma once
#include "Computer.h"

class PC : public Computer
{
private:
	 static constexpr char availableAccessories[] = "mouse, keyboard, microphone, headphones";
public:
	void getComputerType()const override;
	void accessories()const override;
};


class Laptop : public Computer
{
private:
	static constexpr char availableAccessories[] = "mouse pad, keyboard, monitor";
public:
	void getComputerType()const override;
	void accessories()const override;
};

class GamingConsole : public Computer
{
private:
	static constexpr char availableAccessories[] = "joystick, monitor";
public:
	void getComputerType()const override;
	void accessories()const override;
};