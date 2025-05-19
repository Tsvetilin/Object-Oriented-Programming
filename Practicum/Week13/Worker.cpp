#include "Worker.h"

void Worker::setMonthsWorking(size_t monthsWorking) {
	this->monthsWorking = monthsWorking;
}

size_t Worker::getMonthsWorking() const {
	return this->monthsWorking;
}

Employee* Worker::clone() const {
	return new Worker(*this);
}

void Worker::copyFrom(const Worker& other) {
	this->monthsWorking = other.monthsWorking;
}

void Worker::moveFrom(Worker&& other) noexcept {
	this->monthsWorking = other.monthsWorking;

	other.monthsWorking = 0;
}

void Worker::freeWorker() {
	this->monthsWorking = 0;
}

Worker::Worker(const char* name, size_t age, double salary, size_t monthsWorking): Employee(name, age, salary) {
	setMonthsWorking(monthsWorking);
}

Worker::Worker(): Employee() {
	this->monthsWorking = 0;
}

Worker::Worker(const Worker& other): Employee(other) {
	this->copyFrom(other);
}

Worker& Worker::operator=(const Worker& other) {
	if (this != &other) {
		Employee::operator=(other);
		this->freeWorker();
		this->copyFrom(other);
	}

	return *this;
}

Worker::Worker(Worker&& other) noexcept: Employee(std::move(other)) {
	this->moveFrom(std::move(other));
}

Worker& Worker::operator=(Worker&& other) noexcept {
	if (this != &other) {
		Employee::operator=(std::move(other));
		this->freeWorker();
		this->moveFrom(std::move(other));
	}

	return *this;
}

Worker::~Worker() {
	this->freeWorker();
}