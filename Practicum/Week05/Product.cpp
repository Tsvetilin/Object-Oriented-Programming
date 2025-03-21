#include "Product.h"
#include <iostream>
#pragma warning (disable:4996)



void Product::copyFrom(const Product& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	ownedId = other.ownedId;
	quantity = other.quantity;
	productId = other.productId;
}
void Product::free()
{
	delete[] name;
	name = nullptr;
	ownedId = 0;
	quantity = 0;
	productId = 0;
}

Product::Product()
{
	name = new char[1];
	strcpy(name, "");
	ownedId = 0;
	quantity = 0;
	productId = 0;
}
Product::Product(const char* name, size_t ownedId, size_t quantity, size_t productId)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->ownedId = ownedId;
	this->quantity = quantity;
	this->productId = productId;
}
Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Product::Product(const Product& other)
{
	copyFrom(other);
}
Product::~Product()
{
	free();
}

size_t Product::getQuantity() const { return quantity; }
State Product::updateQuantity(int amount)
{
	if ((int)quantity + amount < 0) { return State::NegativeQuantity; }
	quantity += amount;
	return State::OK;
}

size_t Product::getProductId() const{return productId;}
size_t Product::getOwnerId() const{return ownedId;}







