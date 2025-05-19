#include "Employee.h"
#pragma warning(disable: 4996)

Employee::Employee(const char* name, size_t age, double salary) {
	setEmployeeName(name);
	setEmployeeAge(age);
	setEmployeeSalary(salary);
}

Employee::Employee() {
	this->name = nullptr;
	this->age = 0;
	this->salary = 0;
}

Employee::Employee(const Employee& other) {
	this->copyFrom(other);
}

Employee& Employee::operator=(const Employee& other) {
	if (this != &other) {
		this->freeEmployee();
		this->copyFrom(other);
	}

	return *this;
}

Employee::Employee(Employee&& other) noexcept {
	this->moveFrom(std::move(other));
}

Employee& Employee::operator=(Employee&& other) noexcept {
	if (this != &other) {
		this->freeEmployee();
		this->moveFrom(std::move(other));
	}

	return *this;
}

Employee::~Employee() {
	this->freeEmployee();
}

void Employee::setEmployeeName(const char* name) {
	if (name == nullptr) {
		throw std::invalid_argument("Employee name cannot be null!");
	}

	this->freeName();

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Employee::setEmployeeAge(size_t age) {
	this->age = age;
}

void Employee::setEmployeeSalary(double salary) {
	if (salary < 0) {
		throw std::invalid_argument("Employee salary cannot be negative number!");
	}

	this->salary = salary;
}

const char* Employee::getEmployeeName() const {
	return this->name;
}

size_t Employee::getEmployeeAge() const {
	return this->age;
}

double Employee::getEmployeeSalary() const {
	return this->salary;
}

void Employee::copyFrom(const Employee& other) {
	if (other.name == nullptr) {
		throw std::invalid_argument("Employee name cannot be null!");
	}

	this->freeName();

	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);


	this->age = age;


	if (other.salary < 0) {
		throw std::invalid_argument("Employee salary cannot be negative number!");
	}

	this->salary = other.salary;
}

void Employee::moveFrom(Employee&& other) noexcept {
	this->name = other.name;
	this->age = other.age;
	this->salary = other.salary;

	other.name = nullptr;
	other.age = 0;
	other.salary = 0;
}

void Employee::freeName() {
	delete[] this->name;
	this->name = nullptr;
}

void Employee::freeEmployee() {
	this->freeName();
	this->age = 0;
	this->salary = 0;
}