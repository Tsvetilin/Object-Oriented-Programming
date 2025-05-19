#include "Trainee.h"

void Trainee::setDaysTillInternshipEnd(size_t daysTillInternshipEnd) {
	this->daysTillIntershipEnd = daysTillInternshipEnd;
}

size_t Trainee::getDaysTillInternshipEnd() const {
	return this->daysTillIntershipEnd;
}

Employee* Trainee::clone() const {
	return new Trainee(*this);
}

void Trainee::copyFrom(const Trainee& other) {
	this->daysTillIntershipEnd = other.daysTillIntershipEnd;
}

void Trainee::moveFrom(Trainee&& other) noexcept {
	this->daysTillIntershipEnd = other.daysTillIntershipEnd;

	other.daysTillIntershipEnd = 0;
}

void Trainee::freeTrainee() {
	this->daysTillIntershipEnd = 0;
}

Trainee::Trainee(const char* name, size_t age, double salary, size_t daysTillInternshipEnd): Employee(name, age, salary) {
	setDaysTillInternshipEnd(daysTillInternshipEnd);
}

Trainee::Trainee(): Employee() {
	this->daysTillIntershipEnd = 0;
}

Trainee::Trainee(const Trainee& other): Employee(other) {
	this->copyFrom(other);
}

Trainee& Trainee::operator=(const Trainee& other) {
	if (this != &other) {
		Employee::operator=(other);
		this->freeTrainee();
		this->copyFrom(other);
	}

	return *this;
}

Trainee::Trainee(Trainee&& other) noexcept: Employee(std::move(other)) {
	this->moveFrom(std::move(other));
}

Trainee& Trainee::operator=(Trainee&& other) noexcept {
	if (this != &other) {
		Employee::operator=(std::move(other));
		this->freeTrainee();
		this->moveFrom(std::move(other));
	}

	return *this;
}

Trainee::~Trainee() {
	this->freeTrainee();
}