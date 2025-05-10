#ifndef _STUDENT_H
#define _STUDENT_H

#include<iostream>
#include<stdexcept>
#include "MyString.h"

class Student {
public:
	Student(const MyString& name, unsigned facultyNumber, unsigned year);
	Student();

	void setStudentName(const MyString& name);
	void setFacultyNumber(unsigned facultyNumber);
	void setYear(unsigned year);

	const MyString& getStudentName() const;
	unsigned getFacultyNumber() const;
	unsigned getYear() const;

private:
	MyString name;
	unsigned facultyNumber;
	unsigned year;
};

#endif // !_STUDENT_H
