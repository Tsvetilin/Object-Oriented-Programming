#pragma once
#include "Waffle.h"

class Store
{
public:
	Store();
	Store(Waffle* waffles,size_t wafflesCnt,size_t maxCapacity);
	Store(const Store& other);
	Store& operator=(const Store& other);
	~Store();
	void copyFrom(const Store& other);
	void free();
	Waffle* getWaffles() const;
	size_t getWafflesCnt() const;
	size_t getMaxCapacity() const;
	double getIncome() const;
	double getExpenses() const;
	void setWaffles(Waffle* waffles, size_t wafflesCnt);
	void setMaxCapacity(size_t maxCapacity);

	void sellWaffle(const char* brand);
	void sellWaffles(size_t cnt,const char* brand);
	size_t brandCnt(const char* brand);
	double profit();


private:
	Waffle* waffles;
	size_t wafflesCnt;
	size_t maxCapacity;
	double income;
	double expenses;
};