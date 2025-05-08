#include "Computer.h"
#include <iostream>
#include <stdexcept>
#pragma warning(disable:4996)

size_t Computer::pcCounter = 0;


void Computer::copyFrom(const Computer& other)
{
	pcCounter+=1;
	id = pcCounter;
	brand = new char[strlen(other.brand) + 1];
	strcpy(brand, other.brand);
	proccessor = new char[strlen(other.proccessor) + 1];
	strcpy(proccessor, other.proccessor);
	video = other.video;
	hardDrive = other.hardDrive;
	weight = other.weight;
	baterryLife = other.baterryLife;
	price = other.price;
	quantity = other.quantity;
}

void Computer::free()
{
	pcCounter -= 1;
	id = 0;
	delete[] brand;
	delete[] proccessor;
	video = 0;
	hardDrive = 0;
	weight = 0;
	baterryLife = 0;
	price = 0;
	quantity = 0;
}

Computer::Computer()
{
	pcCounter += 1;
	id = pcCounter;
	brand = new char[1];
	strcpy(brand, "");
	proccessor = new char[+ 1];
	strcpy(proccessor, "");
	video = 0;
	hardDrive = 0;
	weight = 0;
	baterryLife = 0;
	price = 0;
	quantity = 0;
}

Computer::Computer(const char* name, const char* proccessor, int video, size_t hardDrive, size_t weight, size_t batteryLife, double price, size_t quantity)
{
	pcCounter += 1;
	id = pcCounter;
	this->brand = new char[strlen(name) + 1];
	strcpy(this->brand, name);
	this->proccessor = new char[strlen(proccessor) + 1];
	strcpy(this->proccessor, proccessor);
	this->video = video;
	this->hardDrive = hardDrive;
	this->weight = weight;
	this->baterryLife = batteryLife;
	this->price = price;
	this->quantity = quantity;
}

Computer::Computer(const Computer& other)
{
	copyFrom(other);
}

Computer& Computer::operator=(const Computer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Computer::~Computer()
{
	free();
}

void Computer::setPrice(double price)
{
	this->price = price;
}

void Computer::changeQuantity(int quantity)
{
	quantity += quantity;
}

const char* Computer::getBrand() const
{
	return brand;
}

const char* Computer::getProccessor() const
{
	return proccessor;
}

int Computer::getVideo() const
{
	return video;
}

const size_t Computer::getHDD() const
{
	return hardDrive;
}

size_t Computer::getWeight() const
{
	return weight;
}

const size_t Computer::getBatteryLife() const
{
	return baterryLife;
}

const double Computer::getPrice() const
{
	return price;
}

const size_t Computer::getQuantity() const
{
	return quantity;
}
