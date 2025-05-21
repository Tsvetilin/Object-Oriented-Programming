#pragma once
#include "States.h"

class Price
{
public:
	Price();
	Price(size_t productId,double price);
	~Price();

	double getPrice() const;
	size_t getId() const;
	State updatePrice(double amount);

private:
	size_t productId;
	double price;
};