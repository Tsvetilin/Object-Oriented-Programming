#pragma once
#pragma warning (disable: 4996)

#include <iostream>

namespace Constants
{
	constexpr size_t MAX_QUOTE_SIZE = 30;
}

class Student
{
private:
	char* name;
	int* grades;
	size_t gradesCount;
	char quote[Constants::MAX_QUOTE_SIZE + 1];

	void copyFrom(const Student& other);
	void free();

public:
	Student();
	Student(const char* name, const int* grades, size_t gradesCount, const char* quote);

	const char* getName() const;
	const int* getGrades() const;
	size_t getGradesCount() const;
	const char* getQuote() const;

	void setName(const char* name);
	void setGrades(const int* grades, size_t gradesCount);
	void setQuote(const char* quote);

	Student(const Student& other);
	Student& operator=(const Student& other);

	~Student();
};
