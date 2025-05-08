#include "StudentDB.h"
#include <iostream>

void StudentDB::free()
{
	delete[] students;
	size = 0;
}

void StudentDB::copyFrom(const StudentDB& other)
{
	size = other.size;
	students = new Student[size];
	for (size_t i = 0; i < size; i++)
	{
		students[i] = other.students[i];
	}
}

void StudentDB::moveFrom(StudentDB&& other)
{
	size = other.size;
	students = other.students;
	other.size = 0;
	other.students = nullptr;
}

StudentDB::StudentDB(Student* students, size_t size)
{
	this->size = size;
	this->students = new Student[size];
	for (size_t i = 0; i < size; i++)
	{
		this->students[i] = students[i];
	}
}

StudentDB::StudentDB(const StudentDB& other)
{
	copyFrom(other);
}

StudentDB& StudentDB::operator=(const StudentDB& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

StudentDB::StudentDB(StudentDB&& other) noexcept
{
	moveFrom(std::move(other));
}

StudentDB& StudentDB::operator=(StudentDB&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

StudentDB::~StudentDB()
{
	free();
}

void StudentDB::add(Student student)
{
	Student* res = new Student[++size];
	for (size_t i = 0; i < size-1; i++)
	{
		res[i] = students[i];
	}
	res[size - 1] = student;
	delete[] students;
	students = res;
}

void StudentDB::remove(unsigned fn)
{
	Student* res = new Student[--size];
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getFN() == fn) continue;
		res[i] = students[i];
	}
	delete[] students;
	students = res;
}

Student StudentDB::find(unsigned fn) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getFN() == fn) return students[i];
	}
	return Student();
}

void StudentDB::display() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "Name: " << students[i].getName() <<
			",FN: " << students[i].getFN() << ",Year: " << students[i].getYear();
	}
}


