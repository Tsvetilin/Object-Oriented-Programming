#include "Company.h"

void Company::setCompany(const Employee& employee, size_t capacity, size_t size) {
	if (capacity < size) {
		throw std::invalid_argument("Size of company cannot be more than its capacity!");
	}

	this->capacity = capacity;
	this->size = size;

	this->employees = new Employee * [capacity];
	for (size_t i = 0; i < size; ++i) {
		this->employees[i] = employee.clone();
	}
}

const Employee& Company::getCompanyEmployees(size_t index) const {
	if (index >= this->size) {
		throw std::out_of_range("Invalid employee index!");
	}
	return *this->employees[index];
}

size_t Company::getCompanyCapacity() const {
	return this->capacity;
}

size_t Company::getCompanySize() const {
	return this->size;
}

void Company::addWorker(const Worker& w) {
	insertSorted(w.clone());
}

void Company::addTrainee(const Trainee& t) {
	insertSorted(t.clone());
}

void Company::addPaidTrainee(const PaidTrainee& pt) {
	insertSorted(pt.clone());
}

double Company::getAverageSalary() const {
	double sum = 0;

	for (size_t i = 0; i < this->size; ++i) {
		sum += this->employees[i]->getEmployeeSalary();
	}

	return sum / this->size;
}

bool Company::twoSum(double val) const {
	const double EPS = 1e-6;

	for (size_t i = 0; i < size; ++i) {
		for (size_t j = i + 1; j < size; ++j) {
			if (std::abs(employees[i]->getEmployeeSalary() + employees[j]->getEmployeeSalary() - val) < EPS) {
				return true;
			}
		}
	}
	return false;
}

Company::Company(const Employee& employee, size_t capacity, size_t size) {
	this->employees = nullptr;
	setCompany(employee, capacity, size);
}

Company::Company() {
	this->size = 0;
	this->capacity = 0;
	this->employees = nullptr;
}

Company::Company(const Company& other) {
	this->copyFrom(other);
}

Company& Company::operator=(const Company& other) {
	if (this != &other) {
		this->freeCompany();
		this->copyFrom(other);
	}
	return *this;
}

Company::Company(Company&& other) noexcept {
	this->moveFrom(std::move(other));
}

Company& Company::operator=(Company&& other) noexcept {
	if (this != &other) {
		this->freeCompany();
		this->moveFrom(std::move(other));
	}
	return *this;
}

Company::~Company() {
	this->freeCompany();
}

void Company::insertSorted(Employee* e) {
	if (this->size >= this->capacity) {
		resizeCompany(this->capacity == 0 ? 1 : this->capacity * 2);
	}

	size_t insertIndex = 0;
	while (insertIndex < this->size && this->employees[insertIndex]->getEmployeeSalary() < e->getEmployeeSalary()) {
		++insertIndex;
	}

	for (size_t i = this->size; i > insertIndex; --i) {
		this->employees[i] = this->employees[i - 1];
	}

	this->employees[insertIndex] = e;
	++this->size;
}

void Company::resizeCompany(size_t newCapacity) {
	Employee** newEmployees = new Employee * [newCapacity];

	for (size_t i = 0; i < this->size; ++i) {
		newEmployees[i] = this->employees[i];
	}

	delete[] this->employees;
	this->employees = newEmployees;
	this->capacity = newCapacity;
}

void Company::copyFrom(const Company& other) {
	this->capacity = other.capacity;
	this->size = other.size;
	this->employees = new Employee * [capacity];

	for (size_t i = 0; i < size; ++i) {
		this->employees[i] = other.employees[i]->clone();
	}
}

void Company::moveFrom(Company&& other) noexcept {
	this->employees = other.employees;
	this->capacity = other.capacity;
	this->size = other.size;

	other.employees = nullptr;
	other.capacity = 0;
	other.size = 0;
}

void Company::freeCompany() {
	for (size_t i = 0; i < size; ++i) {
		delete this->employees[i];
	}
	delete[] this->employees;
}