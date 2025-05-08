#include <iostream>
#include "NumberSeries.h"


void NumberSeries::copyFrom(const NumberSeries& other)
{
	a_0 = other.a_0;
	func = other.func;
	nums = other.nums;
	numsSize = other.numsSize;
}
void NumberSeries::free()
{
	delete[] nums;
	a_0 = 0;
	func = nullptr;
	numsSize = 0;
	nums = nullptr;
}



NumberSeries::NumberSeries()
{
	a_0 = 0;
	func = nullptr;
	numsSize = 1;
	nums = new int[numsSize];
	nums[0] = a_0;
}

NumberSeries::NumberSeries(int a_0, int(*func)(int a))
{
	this->a_0 = a_0;
	this->func = func;
	numsSize = 1;
	nums = new int[numsSize];
	nums[0] = a_0;
}

NumberSeries::NumberSeries(const NumberSeries& other)
{
	copyFrom(other);
}

NumberSeries& NumberSeries::operator=(const NumberSeries& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

NumberSeries::~NumberSeries()
{
	delete[] nums;
	numsSize = 0;
	a_0 = 0;
	func = nullptr;
}

int NumberSeries::getA_i(size_t index)
{
	if (index >= numsSize)
	{
		int* res = new int[index];
		for (size_t i = 0; i < numsSize; i++)
		{
			res[i] = nums[i];
		}
		delete[] nums;
		nums = nullptr;
		for (size_t i = numsSize; i < index; i++)
		{
			res[i] = func(res[i - 1]);
		}
		numsSize = index;
		nums = res;
	}
	return nums[numsSize-1];
}

bool NumberSeries::isPartOfSeries(int a)
{
	size_t currIndex= 0;
	while (a >= nums[numsSize-1])
	{
		currIndex = numsSize;
		getA_i(numsSize * 2);
		for (size_t i = currIndex; i < numsSize; i++)
		{
			if (nums[i] == a) return true;
		}
	}
	return false;;
}

void NumberSeries::setA_0(int a_0)
{
	this->a_0 = a_0;
	delete[] nums;
	numsSize = 1;
	nums = new int[numsSize];
	nums[0] = a_0;
}

void NumberSeries::setFunc(int(*func)(int a))
{
	delete[] nums;
	numsSize = 1;
	nums = new int[numsSize];
	nums[0] = a_0;
	this->func = func;
}
