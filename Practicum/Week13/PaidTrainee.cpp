#include "PaidTrainee.h"

void PaidTrainee::setRating(double rating) {
	if (rating < MIN_RATING || rating > MAX_RATING) {
		throw std::invalid_argument("Paid trainee rating should be between 0 and 100!");
	}

	this->rating = rating;
}

double PaidTrainee::getRating() const {
	return this->rating;
}

Employee* PaidTrainee::clone() const {
	return new PaidTrainee(*this);
}

void PaidTrainee::copyFrom(const PaidTrainee& other) {
	if (other.rating < MIN_RATING || other.rating > MAX_RATING) {
		throw std::invalid_argument("Paid trainee rating should be between 0 and 100!");
	}

	this->rating = other.rating;
}

void PaidTrainee::moveFrom(PaidTrainee&& other) noexcept {
	this->rating = other.rating;

	other.rating = 0;
}

void PaidTrainee::freePaidTrainee() {
	this->rating = 0;
}

PaidTrainee::PaidTrainee(const char* name, size_t age, double salary, size_t monthsWorking, size_t daysTillInternshipEnd, double rating): Employee(name, age, salary), Worker(name, age, salary, monthsWorking), Trainee(name, age, salary, daysTillInternshipEnd) {
	setRating(rating);
}

PaidTrainee::PaidTrainee(): Employee(), Worker(), Trainee() {
	this->rating = 0;
}

PaidTrainee::PaidTrainee(const PaidTrainee& other): Employee(other), Worker(other), Trainee(other) {
	copyFrom(other);
}

PaidTrainee& PaidTrainee::operator=(const PaidTrainee& other) {
	if (this != &other) {
		Employee::operator=(other);
		Worker::operator=(other);
		Trainee::operator=(other);
		this->freePaidTrainee();
		this->copyFrom(other);
	}

	return *this;
}

PaidTrainee::PaidTrainee(PaidTrainee&& other) noexcept: Employee(std::move(other)), Worker(std::move(other)), Trainee(std::move(other)) {
	this->moveFrom(std::move(other));
}

PaidTrainee& PaidTrainee::operator=(PaidTrainee&& other) noexcept {
	if (this != &other) {
		Employee::operator=(std::move(other));
		Worker::operator=(std::move(other));
		Trainee::operator=(std::move(other));
		this->freePaidTrainee();
		this->moveFrom(std::move(other));
	}

	return *this;
}

PaidTrainee::~PaidTrainee() {
	this->freePaidTrainee();
}