#include "Tire.h"

void Tire::setWidth(double width) {
    if (width < MIN_TIRE_WIDTH || width > MAX_TIRE_WIDTH) {
        throw std::invalid_argument("Invalid tire width!");
    }

    this->width = width;
}

void Tire::setProfile(int profile) {
    if (profile < MIN_TIRE_PROFILE || profile > MAX_TIRE_PROFILE) {
        throw std::invalid_argument("Invalid tire profile!");
    }

    this->profile = profile;
}

void Tire::setDiameter(int diameter) {
    if (diameter < MIN_TIRE_DIAMETER || diameter > MAX_TIRE_DIAMETER) {
        throw std::invalid_argument("Invalid tire diameter!");
    }

    this->diameter = diameter;
}

double Tire::getWidth() const {
    return this->width;
}

int Tire::getProfile() const {
    return this->profile;
}

int Tire::getDiameter() const {
    return this->diameter;
}

void Tire::copyFrom(const Tire& other) {
    if (other.width < MIN_TIRE_WIDTH || other.width > MAX_TIRE_WIDTH) {
        throw std::invalid_argument("Invalid tire width!");
    }

    this->width = other.width;

    if (other.profile < MIN_TIRE_PROFILE || other.profile > MAX_TIRE_PROFILE) {
        throw std::invalid_argument("Invalid tire profile!");
    }

    this->profile = other.profile;

    if (other.diameter < MIN_TIRE_DIAMETER || other.diameter > MAX_TIRE_DIAMETER) {
        throw std::invalid_argument("Invalid tire diameter!");
    }

    this->diameter = other.diameter;
}

void Tire::moveFrom(Tire&& other) noexcept {
    this->width = other.width;
    this->profile = other.profile;
    this->diameter = other.diameter;

    other.width = 0;
    other.profile = 0;
    other.diameter = 0;
}

void Tire::freeTire() {
    this->width = 0;
    this->profile = 0;
    this->diameter = 0;
}

Tire::Tire(int id, const char* manufacturer, const char* description, double width, int profile, int diameter): CarPart(id,manufacturer,description) {
    setWidth(width);
    setProfile(profile);
    setDiameter(diameter);
}

Tire::Tire(): CarPart() {
    this->width = MIN_TIRE_WIDTH;
    this->profile = MIN_TIRE_PROFILE;
    this->diameter = MIN_TIRE_DIAMETER;
}

Tire::Tire(const Tire& other) : CarPart(other) {
    this->copyFrom(other);
}

Tire& Tire::operator=(const Tire& other) {
    if (this != &other) {
        CarPart::operator=(other);
        this->freeTire();
        this->copyFrom(other);
    }

    return *this;
}

Tire::Tire(Tire&& other) noexcept: CarPart(std::move(other)) {
    this->moveFrom(std::move(other));
}

Tire& Tire::operator=(Tire&& other) noexcept {
    if (this != &other) {
        CarPart::operator=(std::move(other));
        this->freeTire();
        this->moveFrom(std::move(other));
    }

    return *this;
}

Tire::~Tire() {
    this->freeTire();
}

std::ostream& operator<<(std::ostream& os, const Tire& tire) {
    const CarPart& base = tire;
    operator<<(os, base);

    os << " - " << tire.getWidth() << "mm / " << tire.getProfile() << " R" << tire.getDiameter() << " inches";
    return os;
}