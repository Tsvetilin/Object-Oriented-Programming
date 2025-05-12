#include "PricesDatabase.h"

void PricesDatabase::copyFrom(const PricesDatabase& other)
{
	size = other.size;
	prices = new Price[size];
	for (size_t i = 0; i < size; i++)
	{
		prices[i] = other.prices[i];
	}
}

void PricesDatabase::free()
{
	delete[] prices;
	prices = nullptr;
	size = 0;
}

PricesDatabase::PricesDatabase()
{
	prices = new Price[0];
	size = 0;
}
PricesDatabase::PricesDatabase(Price* products, size_t size)
{
	this->size = size;
	prices = new Price[size];
	for (size_t i = 0; i < size; i++)
	{
		this->prices[i] = prices[i];
	}
}
PricesDatabase::PricesDatabase(const PricesDatabase& other)
{
	copyFrom(other);
}
PricesDatabase& PricesDatabase::operator=(const PricesDatabase& other)
{
	if(this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
PricesDatabase::~PricesDatabase()
{
	free();
}

State PricesDatabase::addPrice(Price price)
{
	if (size + 1 > maxPrices) return State::PriceFull;
	size++;
	Price* res = new Price[size];
	for (size_t i = 0; i < size-1; i++)
	{
		res[i] = prices[i];
	}
	delete[] prices;
	res[size - 1] = price;
	prices = res;
	return State::OK;
}

double PricesDatabase::getPrice(size_t id)
{
	for (size_t i = 0; i < size; i++)
	{
		if (prices[i].getId() == id) return prices[i].getPrice();
	}
	return 0;
}

