#include "School.h"
#include "Student.h"
#include<iostream>
#include<fstream>

void School::setStudentsCount(size_t newStudentsCount) {
	this->studentsCount = newStudentsCount;
}

void School::setStudents(Student* newStudents, size_t newStudentsCount) {
	setStudentsCount(newStudentsCount);

	if (newStudents == nullptr) {
		return;
	}

	if (this->students == newStudents) {
		return;
	}

	if (this->students != nullptr) {
		this->free();
	}

	this->students = new Student[newStudentsCount];
	for (size_t i = 0; i < newStudentsCount; ++i) {
		this->students[i] = newStudents[i];
	}
}

void School::studentsCountSetterForObj(const School& other) {
	this->studentsCount = other.studentsCount;
}

void School::studentsSetterForObj(const School& other) {
	if (other.students == nullptr) {
		return;
	}

	if (this->students = other.students) {
		return;
	}

	if (this->students != nullptr) {
		this->free();
	}

	studentsCountSetterForObj(other);

	for (size_t i = 0; i < other.studentsCount; ++i) {
		this->students[i] = other.students[i];
	}
}

size_t School::getStudentsCount() const {
	return this->studentsCount;
}

const Student* School::getStudent() const {
	return this->students;
}

School School::readSchool(std::ifstream& ifs) {
	School toReturn;

	size_t studentsCount;
	ifs.read((char*)&studentsCount, sizeof(studentsCount));

	toReturn.students = new Student[studentsCount];

	for (size_t i = 0; i < studentsCount; ++i) {
		Student tempStudent;
		tempStudent.readStudent(ifs);
		toReturn.students[i] = tempStudent;
	}

	toReturn.setStudentsCount(studentsCount);

	return toReturn;
}

void School::writeSchool(std::ofstream& ofs, const School& other) {
	ofs.write((char*)&other.studentsCount, sizeof(other.studentsCount));

	for (size_t i = 0; i < other.studentsCount; ++i) {
		other.students[i].writeStudent(ofs, other.students[i]);
	}
}

School School::readSchool(const char* filename) {
	if (!filename) {
		return School();
	}

	std::ifstream ifs(filename, std::ios::in | std::ios::binary);

	if (!ifs.is_open()) {
		std::cerr << "Couldn't open file!" << std::endl;
		return School();
	}

	return readSchool(ifs);
}

void School::writeSchool(const char* filename, const School& other) {
	if (!filename) {
		return;
	}

	std::ofstream ofs(filename, std::ios::out | std::ios::binary);

	if (!ofs.is_open()) {
		std::cerr << "Couldn't open file!" << std::endl;
		return;
	}

	return writeSchool(ofs, other);
}

const void School::printSchoolInfo() {
	std::cout << "School: " << std::endl;
	std::cout << "Number of students in school: " << this->getStudentsCount() << std::endl;
	for (size_t i = 0; i < this->getStudentsCount(); ++i) {
		std::cout << "Student " << i + 1 << ": " << std::endl;
		this->students[i].printStudent();
	}
}

void School::copyFrom(const School& other) {
	this->setStudentsCount(studentsCount);
	this->setStudents(students, studentsCount);
}

void School::free() {
	delete[] this->students;
	this->students = nullptr;
	this->studentsCount = 0;
}

School::School(size_t studentsCount, Student* students) {
	this->setStudentsCount(studentsCount);
	this->setStudents(students, studentsCount);
}

School::School() {
	this->studentsCount = 0;
	this->students = nullptr;
}

School::School(const School& other) {
	this->copyFrom(other);
}

School& School::operator=(const School& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

School::~School() {
	this->free();
}
