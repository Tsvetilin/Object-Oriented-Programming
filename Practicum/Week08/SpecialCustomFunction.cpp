#include "SpecialCustomFunction.h"

void SpecialCustomFunction::copyFrom(const SpecialCustomFunction& other)
{
	func = other.func;
	size = other.size;
	specialNums = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		specialNums[i] = other.specialNums[i];
	}
}

void SpecialCustomFunction::free()
{
	delete[] specialNums;
	specialNums = nullptr;
	size = 0;
	func = [](int num) -> int {return 0;};
}

bool SpecialCustomFunction::isSpecial(int num) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (num = specialNums[i]) return true;
	}
	return false;
}

SpecialCustomFunction::SpecialCustomFunction()
{
	size = 0;
	specialNums = nullptr;
	func = [](int num) -> int {return 0; };
}

SpecialCustomFunction::SpecialCustomFunction(int* arr, size_t size, int (*func)(int a))
{
	this->size = size;
	for (size_t i = 0; i < size; i++)
	{
		specialNums[i] = arr[i];
	}
	this->func = func;
}

SpecialCustomFunction::SpecialCustomFunction(const SpecialCustomFunction& other)
{
	copyFrom(other);
}

SpecialCustomFunction& SpecialCustomFunction::operator=(const SpecialCustomFunction& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

SpecialCustomFunction::~SpecialCustomFunction()
{
	free();
}

int SpecialCustomFunction::operator()(int num)
{
	if (isSpecial(num)) return num * num;
	return this->func(num);
}

SpecialCustomFunction& SpecialCustomFunction::operator++()
{
	for (size_t i = 0; i < size; i++)
	{
		specialNums[i]++;
	}
	return *this;
}

SpecialCustomFunction SpecialCustomFunction::operator++(int)
{
	SpecialCustomFunction res(specialNums,size,func);
	for (size_t i = 0; i < size; i++)
	{
		specialNums[i]++;
	}
	return res;
}

SpecialCustomFunction& SpecialCustomFunction::operator--()
{
	for (size_t i = 0; i < size; i++)
	{
		specialNums[i]--;
	}
	return *this;
}

SpecialCustomFunction SpecialCustomFunction::operator--(int)
{
	SpecialCustomFunction res(specialNums, size, func);
	for (size_t i = 0; i < size; i++)
	{
		specialNums[i]--;
	}
	return res;
}

SpecialCustomFunction SpecialCustomFunction::operator!()
{
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = -(specialNums[i]);
	}
	return SpecialCustomFunction(arr,size,func);
}
