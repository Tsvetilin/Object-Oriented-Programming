#pragma once
#include "MyString.h"

class Student
{
private:
	MyString name;
	unsigned fn = 0;
	unsigned year = 0;
public:
	const char* getName() const;
	unsigned getFN() const;
	unsigned getYear() const;

	void setName(MyString name);
	void setFN(unsigned fn);
	void setYear(unsigned year);
};

