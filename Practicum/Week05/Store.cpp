#include "Store.h"
#include <iostream>
#pragma warning (disable:4996)



void Store::copyFrom(const Store& other)
{
	wafflesCnt = other.wafflesCnt;
	waffles = new Waffle[wafflesCnt];
	for (size_t i = 0; i < wafflesCnt; i++)
	{
		waffles[i] = other.waffles[i];
	}
	maxCapacity = other.maxCapacity;
	income = other.income;
	expenses = other.expenses;
}

void Store::free()
{
	delete[] waffles;
	waffles = nullptr;
	wafflesCnt = 0;
	maxCapacity = 0;
	income = 0;
	expenses = 0;
}



Store::Store()
{
	waffles = nullptr;
	wafflesCnt = 0;
	maxCapacity = 0;
	income = 0;
	expenses = 0;
}

Store::Store(Waffle* waffles, size_t wafflesCnt, size_t maxCapacity)
{
	setWaffles(waffles, wafflesCnt);
	setMaxCapacity(maxCapacity);
	income = getIncome();
	expenses = getExpenses();
}

Store::Store(const Store& other)
{
	copyFrom(other);
}

Store& Store::operator=(const Store& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Store::~Store()
{
	free();
}


Waffle* Store::getWaffles() const { return waffles; }
size_t Store::getWafflesCnt() const { return wafflesCnt; }
size_t Store::getMaxCapacity() const { return maxCapacity; }
double Store::getIncome() const 
{
	double res = 0;
	for (size_t i = 0; i < wafflesCnt; i++)
	{
		res += waffles[i].getPriceForSale();
	}
	return res;
}
double Store::getExpenses() const
{
	double res = 0;
	for (size_t i = 0; i < wafflesCnt; i++)
	{
		res+= waffles[i].getPrice();
	}
	return res;
}


void Store::setWaffles(Waffle* waffles,size_t wafflesCnt)
{
	if (!waffles || this->waffles == waffles || wafflesCnt == 0) return;

	this->wafflesCnt = wafflesCnt;
	delete[] this->waffles;
	this->waffles = new Waffle[wafflesCnt];
	for (size_t i = 0; i < this->wafflesCnt; i++)
	{
		this->waffles[i] = waffles[i];
	}
}
void Store::setMaxCapacity(size_t maxCapacity)
{
	if (maxCapacity == 0) return;
	this->maxCapacity = maxCapacity;
}


void removeLastWaffle(Waffle*& waffles,size_t& wafflesCnt)
{
	Waffle* res = new Waffle[--wafflesCnt];
	for (size_t i = 0; i < wafflesCnt; i++)
	{
		res[i] = waffles[i];
	}
	delete[] waffles;
	waffles = res;
}

void Store::sellWaffle(const char* brand)
{
	for (size_t i = 0; i < wafflesCnt; i++)
	{
		if (!strcmp(waffles[i].getBrand(), brand))
		{
			std::swap(waffles[i], waffles[wafflesCnt - 1]);
			removeLastWaffle(waffles,wafflesCnt);
			return;
		}
	}
}

void Store::sellWaffles(size_t cnt, const char* brand)
{
	size_t sold = 0;
	for (size_t i = 0; i < wafflesCnt; i++)
	{
		if (sold >= cnt) return;
		if (!strcmp(waffles[i].getBrand(), brand))
		{
			std::swap(waffles[i], waffles[wafflesCnt - 1]);
			removeLastWaffle(waffles, wafflesCnt);
			sold++;
			i--;
		}
	}
	if (cnt > sold)
	{
		std::cout << "Not enough stock.Only " << sold << " found and sold, " << cnt - sold << " unavailable";
	}
}

size_t Store::brandCnt(const char* brand)
{
	size_t cnt = 0;
	for (size_t i = 0; i < wafflesCnt; i++)
	{
		if (!strcmp(waffles[i].getBrand(), brand)) cnt++;
	}
	return cnt;
}

double Store::profit()
{
	return income - expenses;
}


