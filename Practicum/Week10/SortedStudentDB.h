#pragma once
#include "StudentDB.h"

enum class Criteria
{
	name, fn, year
};

class SortedStudentDB : StudentDB
{
private:
	void sortByName();
	void sortByFn();
	void sortByYear();
public:
	void sortBy(Criteria criteria);
};

