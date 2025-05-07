#include "Accommodation.h"

#pragma warning(disable:4996)

size_t Accommodation::id = 0;

size_t Accommodation::getId() const {
    return this->id;
}

const char* Accommodation::getName() const {
    return this->name;
}

Type Accommodation::getType() const {
    return this->type;
}

Location Accommodation::getLocation() const {
    return this->location;
}

double Accommodation::getPricePerNight() const {
    return this->pricePerNight;
}

bool Accommodation::getIfItIsAvailable() const {
    return this->isAvailable;
}

size_t Accommodation::getDaysToStay() const {
    return this->daysToStay;
}

void Accommodation::makeReservation(size_t daysToStay) {
	if (daysToStay < 0) {
		throw std::invalid_argument("The number of days is invalid!");
	}

	this->daysToStay = daysToStay;

	if (this->isAvailable) {
		this->isAvailable = false;
	}
	else {
		throw std::invalid_argument("The accommodation is not available!");
	}
}

void Accommodation::cancelReservation() {
	this->daysToStay = 0;
    this->isAvailable = true;
}

double Accommodation::getPriceForStay() const {
    if (isAvailable) {
        return 0;
    }

	return this->daysToStay * this->pricePerNight;
}

void Accommodation::copyFrom(const Accommodation& other) {
    if (other.name == nullptr) {
		throw std::invalid_argument("Name cannot be null!");
    }

    if (this->name == other.name) {
        throw std::invalid_argument("The name is already set!");
    }

	if (this->name != nullptr) {
		this->freeName();
	}

	this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->type = other.type;
    this->location = other.location;

	if (other.pricePerNight < 0) {
		throw std::invalid_argument("The prices are invalid!");
	}
    this->pricePerNight = other.pricePerNight;

    this->isAvailable = other.isAvailable;

    if (other.daysToStay < 0) {
		throw std::invalid_argument("The number of days is invalid!");
    }
	this->daysToStay = other.daysToStay;
}

void Accommodation::freeName() {
    delete[] this->name;
    this->name = nullptr;
}

void Accommodation::free() {
    this->freeName();
	this->type = Type::Apartment;
	this->location = Location(0, 0);
	this->pricePerNight = 0.0;
	this->isAvailable = false;
	this->daysToStay = 0;
}

Accommodation::Accommodation(size_t id, const char* name, Type type, Location location, double pricePerNight, bool isAvailable, size_t daysToStay) {
    ++this->id;
    setName(name);
	setType(type);
	setLocation(location);
	setPricePerNight(pricePerNight);
	setIsAvailable(isAvailable);
	setDaysToStay(daysToStay);
}

Accommodation::Accommodation() {
    ++this->id;
	this->name = nullptr;
	this->type = Type::Apartment;
	this->location = Location(0, 0);
	this->pricePerNight = 0.0;
	this->isAvailable = false;
	this->daysToStay = 0;
}

Accommodation::Accommodation(const Accommodation& other) {
    this->copyFrom(other);
}

Accommodation& Accommodation::operator=(const Accommodation& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }

    return *this;
}

Accommodation::~Accommodation() {
    this->free();
}

void Accommodation::setName(const char* name) {
    if (name == nullptr) {
        throw std::invalid_argument("Name cannot be null!");
    }

    if (this->name == name) {
        throw std::invalid_argument("The name is already set!");
    }

    if (this->name != nullptr) {
        this->freeName();
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Accommodation::setType(Type type) {
    this->type = type;
}

void Accommodation::setLocation(Location location) {
	this->location = location;
}

void Accommodation::setPricePerNight(double pricePerNight) {
    if (pricePerNight < 0) {
        throw std::invalid_argument("The prices are invalid!");
    }

    this->pricePerNight = pricePerNight;
}

void Accommodation::setIsAvailable(bool isAvailable) {
    this->isAvailable = isAvailable;
}

void Accommodation::setDaysToStay(size_t daysToStay) {
    if (daysToStay < 0) {
        throw std::invalid_argument("The number of days is invalid!");
    }

    this->daysToStay = daysToStay;
}