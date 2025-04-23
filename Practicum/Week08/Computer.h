#ifndef _COMPUTER_H
#define _COMPUTER_H

#include<cstring>
#include<stdexcept>
#include<iostream>
#include "ConsultantUtils.h"

class Computer {
public:
	Computer(const char* brand, const char* processor, int video, int hardDrive, int weight, int batteryLife, double price, int quantity);
	Computer();
	Computer(const Computer& other);
	Computer& operator=(const Computer& other);
	~Computer();

	void setQuantity(int quantity);

	static int getSerialNumber();
	const char* getBrand() const;
	const char* getProcessor() const;
	int getVideo() const;
	int getHardDrive() const;
	int getWeight() const;
	int getBatteryLife() const;
	double getPrice() const;
	int getQuantity() const;

	void print() const;

private:
	static int serialNumber;
	char* brand;
	char* processor;
	int video;
	int hardDrive;
	int weight;
	int batteryLife;
	double price;
	int quantity;

	void copyFrom(const Computer& other);
	void freeBrand();
	void freeProcessor();
	void free();
};

#endif // !_COMPUTER_H
