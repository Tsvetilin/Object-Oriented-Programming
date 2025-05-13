#include "FilteresStudentDB.h"
#include <iostream>
#pragma warning(disable:4996)

static const size_t SIZE = 1024;

void FilteresStudentDB::filterByName()
{
	std::cout << "Name minimum criteria: ";
	char info[SIZE];
	std::cin >> info;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(students[i].getName(), info) < 0) remove(students[i].getFN());
	}
}

void FilteresStudentDB::filterByFN()
{
	std::cout << "FN minimum criteria: ";
	unsigned limit = 0;
	std::cin >> limit;
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getFN() < limit) remove(students[i].getFN());
	}
}

void FilteresStudentDB::filterByYear()
{
	std::cout << "Year minimum criteria: ";
	unsigned limit = 0;
	std::cin >> limit;
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getYear() < limit) remove(students[i].getFN());
	}
}

void FilteresStudentDB::filter(Criteria criteria)
{
	switch (criteria)
	{
	case Criteria::name:
		filterByName();
		break;
	case Criteria::fn:
		filterByFN();
		break;
	case Criteria::year:
		filterByYear();
		break;
	default:
		break;
	}
}

void FilteresStudentDB::limit(size_t n)
{
	if (n >= size) return;
	Student* res = new Student[n];
	for (size_t i = 0; i < n; i++)
	{
		res[i] = students[i];
	}
	delete[] students;
	students = res;
}
