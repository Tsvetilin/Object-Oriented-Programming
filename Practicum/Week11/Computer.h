#ifndef _COMPUTER_H
#define _COMPUTER_H

#include<stdexcept>
#include<iostream>
#include<cstring>

class Computer {
public:
	Computer(double processorPower, const char* videoCardModel, int supplyPower, int RAM);
	Computer() = default;
	Computer(const Computer& other);
	Computer& operator=(const Computer& other);
	Computer(Computer&& other) noexcept;
	Computer& operator=(Computer&& other) noexcept;
	~Computer();

	void setProcessorPower(double processorPower);
	void setVideoCardModel(const char* videoCardModel);
	void setSupplyPower(int supplyPower);
	void setRAM(int RAM);

	double getProcessorPower() const;
	const char* getVideoCardModel() const;
	int getSupplyPower() const;
	int getRAM() const;

	virtual void printType() const = 0;
	virtual const char* const* getPeripherals() const = 0;

private:
	double processorPower = 0;
	char* videoCardModel = nullptr;
	int supplyPower = 0;
	int RAM = 0;

	void copyFrom(const Computer& other);
	void moveFrom(Computer&& other) noexcept;
	void freeVideoCardModel();
	void free();
};

#endif // !_COMPUTER_H