#include "SortedStudentDB.h"
#include <iostream>
#pragma warning(disable:4996)

void SortedStudentDB::sortByName()
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i+1; j < size; j++)
		{
			if (strcmp(students[i].getName(), students[j].getName()) > 0)
			{
				std::swap(students[i], students[j]);
			}
		}
	}
}

void SortedStudentDB::sortByFn()
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (students[i].getFN() > students[j].getFN())
			{
				std::swap(students[i], students[j]);
			}
		}
	}
}

void SortedStudentDB::sortByYear()
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (students[i].getYear() > students[j].getYear())
			{
				std::swap(students[i], students[j]);
			}
		}
	}
}

void SortedStudentDB::sortBy(Criteria criteria)
{
	switch (criteria)
	{
	case Criteria::name:
		sortByName();
		break;
	case Criteria::fn:
		sortByFn();
		break;
	case Criteria::year:
		sortByYear();
		break;
	default:
		break;
	}
}

