#include "CarPart.h"
#pragma warning(disable: 4996)

void CarPart::setId(int id) {
    if (id <= 0) {
        throw std::invalid_argument("Invalid id number!");
    }

    this->id = id;
}

void CarPart::setManufacturer(const char* manufacturer) {
    if (manufacturer == nullptr) {
        throw std::invalid_argument("Manufacturer cannot be null!");
    }

    delete[] this->manufacturer;

    this->manufacturer = new char[strlen(manufacturer) + 1];
    strcpy(this->manufacturer, manufacturer);
}

void CarPart::setDescription(const char* description) {
    if (description == nullptr) {
        throw std::invalid_argument("Description cannot be null!");
    }

    delete[] this->description;

    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

int CarPart::getId() const {
    return this->id;
}

const char* CarPart::getDescription() const {
    return this->description;
}

const char* CarPart::getManufacturer() const {
    return this->manufacturer;
}

void CarPart::copyFrom(const CarPart& other) {
    if (other.id <= 0) {
        throw std::invalid_argument("Invalid id number!");
    }

    this->id = other.id;

    this->freeManufacturer();

    this->manufacturer = new char[strlen(other.manufacturer) + 1];
    strcpy(this->manufacturer, other.manufacturer);

    this->freeDescription();

    this->description = new char[strlen(other.description) + 1];
    strcpy(this->description, other.description);
}

void CarPart::moveFrom(CarPart&& other) noexcept {
    this->id = other.id;
    this->manufacturer = other.manufacturer;
    this->description = other.description;

    other.id = 0;
    other.manufacturer = nullptr;
    other.description = nullptr;
}

void CarPart::freeManufacturer() {
    delete[] this->manufacturer;
    this->manufacturer = nullptr;
}

void CarPart::freeDescription() {
    delete[] this->description;
    this->description = nullptr;
}

void CarPart::free() {
    this->id = 0;
    this->freeManufacturer();
    this->freeDescription();
}

CarPart::CarPart(int id, const char* manufacturer, const char* description) {
    this->manufacturer = nullptr;
    this->description = nullptr;

    setId(id);
    setManufacturer(manufacturer);
    setDescription(description);
}

CarPart::CarPart() {
    this->id = 1;
    this->manufacturer = nullptr;
    this->description = nullptr;
}

CarPart::CarPart(const CarPart& other) {
    this->copyFrom(other);
}

CarPart& CarPart::operator=(const CarPart& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }

    return *this;
}

CarPart::CarPart(CarPart&& other) noexcept {
    this->moveFrom(std::move(other));
}

CarPart& CarPart::operator=(CarPart&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveFrom(std::move(other));
    }

    return *this;
}

CarPart::~CarPart() {
    this->free();
}

std::ostream& operator<<(std::ostream& os, const CarPart& carPart) {
    os << "(" << carPart.getId() << ") by '";
    if (carPart.getManufacturer() != nullptr) {
        os << carPart.getManufacturer();
    }
    else {
        os << "N/A";
    }
    os << "' - ";
    if (carPart.getDescription() != nullptr)
        os << carPart.getDescription();
    else {
        os << "N/A";
    }
        
    return os;
}