#pragma once

class FuelTank
{
protected:
	double capacity;
	double level;
public:
	FuelTank(double capacity);

	void consume(double usage);
	void refuel(double add);
};

