#include "AirBnB.h"

AirBnB::AirBnB(Accommodation* accommodations, size_t size, size_t capacity) {
	setAccommodation(accommodations, size, capacity);
}

AirBnB::AirBnB() {
	this->accommodations = nullptr;
	this->size = 0;
	this->capacity = 0;
}

AirBnB::AirBnB(const AirBnB& other) {
	this->copyFrom(other);
}

AirBnB& AirBnB::operator=(const AirBnB& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

AirBnB::~AirBnB() {
	this->free();
}

void AirBnB::resize() {
	size_t newCapacity = this->capacity * 2;
	Accommodation* newAccommodations = new Accommodation[newCapacity];

	for (size_t i = 0; i < this->size; ++i) {
		newAccommodations[i] = this->accommodations[i];
	}

	delete[] this->accommodations;
	this->accommodations = newAccommodations;
	this->capacity = newCapacity;
}

void AirBnB::copyFrom(const AirBnB& other) {
	if (other.size < 0 || other.capacity < 0 || other.size > other.capacity) {
		throw std::invalid_argument("Invalid size or capacity!");
	}
	this->size = other.size;
	this->capacity = other.capacity;

	if (other.accommodations == nullptr) {
		throw std::invalid_argument("Invalid accommodation!");
	}

	if (this->accommodations == other.accommodations) {
		throw std::invalid_argument("The accommodations are already set!");
	}
	
	if (this->accommodations != nullptr) {
		this->freeAccommodations();
	}

	this->accommodations = new Accommodation[other.capacity];
	for (size_t i = 0; i < other.size; ++i) {
		this->accommodations[i] = other.accommodations[i];
	}
}

void AirBnB::freeAccommodations() {
	delete[] this->accommodations;
	this->accommodations = nullptr;
}

void AirBnB::free() {
	this->freeAccommodations();
	this->size = 0;
	this->capacity = 0;
	this->total = 0;
}

void AirBnB::setAccommodation(Accommodation* accommodations, size_t size, size_t capacity) {
	setSize(size);
	setCapacity(capacity);

	if (accommodations == nullptr || size == 0 || size > capacity) {
		throw std::invalid_argument("Invalid accommodation, size or capacity!");
	}

	this->freeAccommodations();
	this->accommodations = new Accommodation[capacity];
	for (size_t i = 0; i < size; ++i) {
		this->accommodations[i] = accommodations[i];
	}
}

void AirBnB::setSize(size_t size) {
	if (size < 0) {
		throw std::invalid_argument("Size is invalid!");
	}
	if (size > this->capacity) {
		throw std::invalid_argument("Size exceeds capacity!");
	}

	this->size = size;
}

void AirBnB::setCapacity(size_t capacity) {
	if (capacity < 0) {
		throw std::invalid_argument("Capacity is invalid!");
	}
	if (capacity < this->size) {
		throw std::invalid_argument("Size exceeds capacity!");
	}

	this->capacity = capacity;
}

const Accommodation* AirBnB::getAccommodation() const {
	return this->accommodations;
}

size_t AirBnB::getSize() const {
	return this->size;
}

size_t AirBnB::getCapacity() const {
	return this->capacity;
}

double AirBnB::getTotal() const {
	return this->total;
}

void AirBnB::addAccommodation(const Accommodation& accommodation) {
	if (this->size >= this->capacity) {
		this->resize();
	}

	this->accommodations[this->size] = accommodation;
}

void AirBnB::reserveById(size_t id, size_t days) {
	if (id < 0 || id >= this->size) {
		throw std::invalid_argument("Invalid id!");
	}

	this->accommodations[id].makeReservation(days);
}

void AirBnB::cancelReservationById(size_t id) {
	bool found = false;

	for (size_t i = 0; i < this->size; ++i) {
		if (accommodations[i].getId() == id) {
			found = true;

			if (!accommodations[i].getIfItIsAvailable()) {
				accommodations[i].cancelReservation();
			}
			else {
				throw std::logic_error("There is no reservation!");
			}

			break;
		}
	}

	if (!found) {
		throw std::invalid_argument("Invalid id!");
	}
}

double AirBnB::getTotalPriceForAllReservations() const {
	double sum = 0;
	for (size_t i = 0; i < this->size; ++i) {
		if (!accommodations[i].getIfItIsAvailable()) {
			sum += accommodations[i].getPricePerNight() * accommodations[i].getDaysToStay();
		}
	}
	return sum;
}

Accommodation AirBnB::findNearestAccommodation(double userX, double userY) const {
	if (this->size == 0) {
		throw std::logic_error("No accommodations available.");
	}

	double minDistance = std::numeric_limits<double>::max();
	size_t nearestIndex = 0;

	for (size_t i = 0; i < this->size; ++i) {
		double dx = accommodations[i].getLocation().getX() - userX;
		double dy = accommodations[i].getLocation().getY() - userY;
		double distance = std::sqrt(dx * dx + dy * dy);

		if (distance < minDistance) {
			minDistance = distance;
			nearestIndex = i;
		}
	}

	return accommodations[nearestIndex];
}

void AirBnB::removeAccommodationById(size_t id) {
	for (size_t i = 0; i < this->size; ++i) {
		if (accommodations[i].getId() == id) {
			if (!accommodations[i].getIfItIsAvailable()) {
				throw std::logic_error("Accommodation is currently reserved and cannot be removed.");
			}

			accommodations[i] = accommodations[this->size - 1];
			--this->size;
			return;
		}
	}

	throw std::invalid_argument("Invalid ID.");
}
