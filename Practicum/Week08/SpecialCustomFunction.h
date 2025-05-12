#pragma once
class SpecialCustomFunction
{
private:
	int* specialNums;
	size_t size;
	int (*func) (int a) = nullptr;

	void copyFrom(const SpecialCustomFunction& other);
	void free();

	bool isSpecial(int num) const;
public:
	SpecialCustomFunction();
	SpecialCustomFunction(int* arr,size_t size, int (*func)(int a));
	SpecialCustomFunction(const SpecialCustomFunction& other);
	SpecialCustomFunction& operator=(const SpecialCustomFunction& other);
	~SpecialCustomFunction();

	int operator()(int num);
	SpecialCustomFunction& operator++();   //prefix	
	SpecialCustomFunction operator++(int); //postfix
	SpecialCustomFunction& operator--();   //prefix
	SpecialCustomFunction operator--(int); //postfix
	SpecialCustomFunction operator!();

};

