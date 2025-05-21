#include "Waffle.h"
#include <iostream>
#pragma warning (disable:4996)

void Waffle::copyFrom(const Waffle& other)
{
	brand = new char[strlen(other.brand) + 1];
	strcpy(brand, other.brand);
	weight = other.weight;
	price = other.price;
	priceForSale = other.priceForSale;
}

void Waffle::free()
{
	if (brand)
	{
		delete[] this->brand;
		brand = nullptr;
	}
	this->weight = 0;
	this->price = 0;
	this->priceForSale = 0;;
}

char* Waffle::getBrand() const{ return brand; }
double Waffle::getWeight() const { return weight; }
double Waffle::getPrice() const { return price; }
double Waffle::getPriceForSale() const { return priceForSale; }

void Waffle::setBrand(const char* str)
{
	if (!str || brand == str)
	{
		return;
	}
	delete[] brand;
	brand = new char[strlen(str) + 1];
	strcpy(brand, str);
}
void Waffle::setWeight(double weight) { this->weight = weight; }
void Waffle::setPrice(double price) { this->price = price; }
void Waffle::setPriceForSale(double priceForSale) { this->priceForSale = priceForSale; }



Waffle::Waffle()
{
	brand = nullptr;
	weight = 0;
	price = 0;
	priceForSale = 0;
}

Waffle::Waffle(const char* brand, double weight, double price, double priceForSale)
{
	setBrand(brand);
	setWeight(weight);
	setPrice(price);
	setPriceForSale(priceForSale);
}

Waffle::Waffle(const Waffle& other)
{
	copyFrom(other);
}

Waffle& Waffle::operator=(const Waffle& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Waffle::~Waffle()
{
	free();
}





