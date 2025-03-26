#include "Student.h"
#include<iostream>
#include<cstring>
#include<fstream>

#pragma warning(disable:4996)

Student::Student(const char* name, size_t gradesCount, int* grades, const char* motto) {
	setName(name);
	setGrades(grades, gradesCount);
	setMotto(motto);
}

Student::Student() {
	this->name = nullptr;
	this->gradesCount = 0;
	this->grades = nullptr;
	motto[0] = '\n';
}

Student::Student(const Student& other) {
	this->copyFrom(other);
}

Student& Student::operator=(const Student& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

Student::~Student() {
	this->free();
}

void Student::setName(const char* newName) {
	if (newName == nullptr) {
		return;
	}

	if (this->name == newName) {
		return;
	}

	if (this->name != nullptr) {
		this->freeName();
	}

	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
}

void Student::setGrades(int* newGrades, size_t newGradesCount) {
	if (newGrades == nullptr) {
		return;
	}

	if (this->grades == newGrades) {
		return;
	}

	if (this->grades != nullptr) {
		this->freeGrades();
	}

	this->gradesCount = newGradesCount;
	this->grades = new int[newGradesCount];
	for (size_t i = 0; i < newGradesCount; ++i) {
		this->grades[i] = newGrades[i];
	}
}

void Student::setMotto(const char* newMotto) {
	if (strlen(newMotto) > MAX_MOTTO_LEN) {
		std::cerr << "Invalid input!" << std::endl;
		return;
	}

	strcpy(this->motto, newMotto);
}

void Student::nameSetterForObj(const Student& other) {
	if (other.name == nullptr) {
		return;
	}

	if (this->name == other.name) {
		return;
	}

	if (this->name != nullptr) {
		this->freeName();
	}

	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}

void Student::gradesSetterForObj(const Student& other) {
	if (other.grades == nullptr) {
		return;
	}

	if (this->grades == other.grades) {
		return;
	}

	if (this->grades == nullptr) {
		this->freeGrades();
	}

	this->gradesCount = other.gradesCount;
	this->grades = new int[other.gradesCount];
	for (size_t i = 0; i < other.gradesCount; ++i) {
		this->grades[i] = other.grades[i];
	}
}

void Student::mottoSetterForObj(const Student& other) {
	if (strlen(other.motto) > MAX_MOTTO_LEN) {
		std::cerr << "Invalid input!" << std::endl;
		return;
	}

	strcpy(this->motto, other.motto);
}

const char* Student::getName() const {
	return this->name;
}

const int* Student::getGrades() const {
	return this->grades;
}

int Student::getGradesCount() const {
	return this->gradesCount;
}

const char* Student::getMotto() const {
	return this->motto;
}

Student Student::readStudent(std::ifstream& ifs) {
	Student toReturn;
	
	size_t nameLen;
	ifs.read((char*)&nameLen, sizeof(nameLen));

	if (nameLen > 0) {
		toReturn.name = new char[nameLen + 1];
		ifs.read(toReturn.name, nameLen);
	}

	ifs.read((char*)&toReturn.gradesCount, sizeof(toReturn.gradesCount));

	if (toReturn.gradesCount > 0) {
		toReturn.grades = new int[toReturn.gradesCount];
		ifs.read((char*)toReturn.grades, toReturn.gradesCount * sizeof(int));
	}

	return toReturn;
}

void Student::writeStudent(std::ofstream& ofs, const Student& other) {
	size_t nameLength = strlen(other.name) + 1;
	ofs.write((char*)&nameLength, sizeof(nameLength));
	ofs.write(other.name, nameLength);

	ofs.write((char*)&other.gradesCount, sizeof(other.gradesCount));
	ofs.write((char*)other.grades, other.gradesCount * sizeof(int));
}

Student Student::readStudent(const char* filename) {
	if (!filename) {
		return Student();
	}

	std::ifstream ifs(filename, std::ios::in | std::ios::binary);

	if (!ifs.is_open()) {
		std::cerr << "Couldn't open file!" << std::endl;
		return Student();
	}

	return readStudent(ifs);
}

void Student::writeStudent(const char* filename, const Student& student) {
	if (!filename) {
		return;
	}

	std::ofstream ofs(filename, std::ios::out | std::ios::binary);

	if (!ofs.is_open()) {
		std::cerr << "Couldn't open file!" << std::endl;
		return;
	}

	writeStudent(ofs, student);
}

const void Student::printStudent() {
	std::cout << "Student: " << std::endl;
	std::cout << "Student name: " << this->name << std::endl;
	std::cout << "Grades: ";
	for (size_t i = 0; i < this->gradesCount; ++i) {
		std::cout << this->grades[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Motto: " << this->motto << std::endl;

	std::cout << std::endl;
}

void Student::copyFrom(const Student& other) {
	this->nameSetterForObj(other);
	this->gradesSetterForObj(other);
	this->mottoSetterForObj(other);
}

void Student::freeName() {
	delete[] this->name;
	this->name = nullptr;
}

void Student::freeGrades() {
	delete[] this->grades;
	this->grades = nullptr;
	this->gradesCount = 0;
}

void Student::free() {
	this->freeName();
	this->freeGrades();
}
