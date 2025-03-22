#pragma warning (disable: 4996)

#include <iostream>
#include <fstream>
#include <cmath>

namespace Constants
{
	constexpr size_t MAX_NAME_SIZE = 100;
	constexpr size_t MAX_SIZE = 50;
	constexpr double EPS = 1e-6;
}

namespace StudentNS
{
	using namespace Constants;

	struct Student
	{
		char name[MAX_SIZE + 1];
		size_t age;
		double grade;
	};

	Student initStudent(const char* name, size_t age, double grade)
	{
		if (!name) return {};

		Student toReturn;

		strcpy(toReturn.name, name);
		toReturn.age = age;
		toReturn.grade = grade;

		return toReturn;
	}

	void printStudent(const Student& obj)
	{
		std::cout << obj.name << " " << obj.grade << std::endl;
	}
}

namespace StudentsNS
{
	using namespace StudentNS;

	enum class Criteria : uint8_t
	{
		SortByName,
		SortByGrade
	};

	struct Students
	{
		Student* students;
		size_t size;
	};

	Students initStudents(size_t size)
	{
		Students toReturn;

		toReturn.size = size;
		toReturn.students = new Student[size];

		return toReturn;
	}

	void selectionSort(Students& students, bool (*compare)(const Student&, const Student&))
	{
		if (!compare) return;

		for (size_t i = 0; i < students.size - 1; i++)
		{
			size_t idx = i;

			for (size_t j = i + 1; j < students.size; j++)
			{
				if (compare(students.students[j], students.students[idx]))
				{
					idx = j;
				}
			}

			if (idx != i)
			{
				std::swap(students.students[i], students.students[idx]);
			}
		}
	}

	void sortData(Students& students, Criteria criteria)
	{
		switch (criteria)
		{
		case Criteria::SortByName:
			return selectionSort(students, [](const Student& lhs, const Student& rhs) -> bool {
				return strcmp(lhs.name, rhs.name) <= 0;
				});
		case Criteria::SortByGrade:
			return selectionSort(students, [](const Student& lhs, const Student& rhs) -> bool {
				return lhs.grade < rhs.grade || std::abs(lhs.grade - rhs.grade) <= EPS;
				});
		default: return;
		}
	}

	void printStudents(const Students& obj)
	{
		for (size_t i = 0; i < obj.size; i++)
		{
			printStudent(obj.students[i]);
		}

		std::cout << std::endl;
	}

	void freeStudents(Students& students)
	{
		delete[] students.students;
	}
}

int main()
{
	using namespace StudentsNS;

	Students students = initStudents(3);

	students.students[0] = initStudent("ABV", 20, 5);
	students.students[1] = initStudent("CDF", 21, 5.5);
	students.students[2] = initStudent("MNO", 18, 4.5);

	{
		sortData(students, Criteria::SortByName);
		printStudents(students);
	}
	{
		sortData(students, Criteria::SortByGrade);
		printStudents(students);
	}

	freeStudents(students);

	return 0;
}
