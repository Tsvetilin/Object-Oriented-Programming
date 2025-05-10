#include "Student.h"

Student::Student(const MyString& name, unsigned facultyNumber, unsigned year) {
	setStudentName(name);
	setFacultyNumber(facultyNumber);
	setYear(year);
}

Student::Student() {
	this->name = MyString();
	this->facultyNumber = 0;
	this->year = 0;
}

void Student::setStudentName(const MyString& name) {
	if (name.getString() == nullptr) {
		throw std::invalid_argument("Student name cannot be null!");
	}

	this->name = name;
}

void Student::setFacultyNumber(unsigned facultyNumber) {
	this->facultyNumber = facultyNumber;
}

void Student::setYear(unsigned year) {
	this->year = year;
}

const MyString& Student::getStudentName() const {
	return this->name;
}

unsigned Student::getFacultyNumber() const {
	return this->facultyNumber;
}

unsigned Student::getYear() const {
	return this->year;
}