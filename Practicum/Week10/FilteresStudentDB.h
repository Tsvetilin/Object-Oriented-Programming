#pragma once
#include "StudentDb.h"

enum class Criteria
{
	name, fn, year
};

class FilteresStudentDB : StudentDB
{
private:
	void filterByName();
	void filterByFN();
	void filterByYear();
public:
	void filter(Criteria criteria);
	void limit(size_t n);
};

