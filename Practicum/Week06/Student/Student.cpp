#include "Student.h"

void Student::copyFrom(const Student& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->grades = new int[other.gradesCount];
	for (size_t i = 0; i < other.gradesCount; i++)
	{
		this->grades[i] = other.grades[i];
	}

	this->gradesCount = other.gradesCount;
	strcpy(this->quote, other.quote);
}

void Student::free()
{
	delete[]this->name;
	delete[]this->grades;

	this->name = nullptr;
	this->grades = nullptr;
	this->gradesCount = 0;
}

Student::Student() : name(nullptr), grades(nullptr), gradesCount(0), quote("")
{
}

Student::Student(const char* name, const int* grades, size_t gradesCount, const char* quote)
{
	setName(name);
	setGrades(grades, gradesCount);
	setQuote(quote);
}

const char* Student::getName() const
{
	return this->name;
}

const int* Student::getGrades() const
{
	return this->grades;
}

size_t Student::getGradesCount() const
{
	return this->gradesCount;
}

const char* Student::getQuote() const
{
	return this->quote;
}

void Student::setName(const char* name)
{
	if (!name || this->name == name) return;

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Student::setGrades(const int* grades, size_t gradesCount)
{
	if (!grades || this->grades == grades) return;

	delete[] this->grades;
	this->grades = new int[gradesCount];
	this->gradesCount = gradesCount;

	for (size_t i = 0; i < this->gradesCount; i++)
	{
		this->grades[i] = grades[i];
	}
}

void Student::setQuote(const char* quote)
{
	if (!quote || strlen(quote) > Constants::MAX_QUOTE_SIZE) return;

	strcpy(this->quote, quote);
}

Student::Student(const Student& other)
{
	copyFrom(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Student::~Student()
{
	free();
}
