#include "Battery.h"
#pragma warning(disable: 4996)

void Battery::setCapacity(int capacity) {
    if (capacity < 0) {
        throw std::invalid_argument("Invalid battery capacity!");
    }

    this->capacity = capacity;
}

void Battery::setBatteryId(const char* batteryId) {
    if (batteryId == nullptr) {
        throw std::invalid_argument("Battery ID cannot be null!");
    }

    this->freeBatteryId();

    this->batteryId = new char[strlen(batteryId) + 1];
    strcpy(this->batteryId, batteryId);
}

int Battery::getCapacity() const {
    return this->capacity;
}

const char* Battery::getBatteryId() const {
    return this->batteryId;
}

void Battery::copyFrom(const Battery& other) {
    if (other.capacity < 0) {
        throw std::invalid_argument("Invalid battery capacity!");
    }

    this->capacity = other.capacity;

    if (other.batteryId == nullptr) {
        throw std::invalid_argument("Battery ID cannot be null!");
    }

    this->freeBatteryId();

    this->batteryId = new char[strlen(other.batteryId) + 1];
    strcpy(this->batteryId, other.batteryId);
}

void Battery::moveFrom(Battery&& other) noexcept {
    this->capacity = other.capacity;
    this->batteryId = other.batteryId;

    other.capacity = 0;
    other.batteryId = nullptr;
}

void Battery::freeBatteryId() {
    delete[] this->batteryId;
    this->batteryId = nullptr;
}

void Battery::freeBattery() {
    this->capacity = 0;
    this->freeBatteryId();
}

Battery::Battery(int id, const char* manufacturer, const char* description, int capacity, const char* batteryId): CarPart(id,manufacturer,description) {
    setCapacity(capacity);
    setBatteryId(batteryId);
}

Battery::Battery(): CarPart() {
    this->capacity = 0;
    this->batteryId = nullptr;
}

Battery::Battery(const Battery& other): CarPart(other) {
    this->copyFrom(other);
}

Battery& Battery::operator=(const Battery& other) {
    if (this != &other) {
        CarPart::operator=(other);
        this->freeBattery();
        this->copyFrom(other);
    }

    return *this;
}

Battery::Battery(Battery&& other) noexcept: CarPart(std::move(other)) {
    this->moveFrom(std::move(other));
}

Battery& Battery::operator=(Battery&& other) noexcept {
    if (this != &other) {
        CarPart::operator=(std::move(other));
        this->freeBattery();
        this->moveFrom(std::move(other));
    }

    return *this;
}

Battery::~Battery() {
    this->freeBattery();
}

std::ostream& operator<<(std::ostream& os, const Battery& battery) {
    const CarPart& base = battery;
    operator<<(os, base);
    os << " - " << battery.getCapacity() << " Ah";
    if (battery.batteryId != nullptr) {
        os << " - Battery ID:" << battery.getBatteryId();
    }
    else {
        os << " - Battery ID: N/A";
    }

    return os;
}