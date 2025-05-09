#pragma once
#include "Price.h"

class PricesDatabase
{
	const size_t maxPrices = 100;
public:
	void copyFrom(const PricesDatabase& other);
	void free();
	PricesDatabase();
	PricesDatabase(Price* products, size_t size);
	PricesDatabase(const PricesDatabase& other);
	PricesDatabase& operator=(const PricesDatabase& other);
	~PricesDatabase();

	State addPrice(Price price);
	double getPrice(size_t id);

private:
	Price* prices;
	size_t size;
};