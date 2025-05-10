#include "Car.h"

 FuelTank& Car::getFuelTank() {
    return this->fuelTank;
}

const Engine& Car::getEngine() const {
    return this->engine;
}

const Tire* Car::getTires() const {
    return this->tires;
}

const Battery& Car::getBattery() const {
    return this->battery;
}

double Car::getMileage() const {
    return this->mileage;
}

double Car::getWeight() const {
    return this->weight;
}

void Car::drive(double km) {
    if (km < 0) {
        throw std::invalid_argument("Distance cannot be negative!");
    }

    double fuelNeeded = km * 1.0;

    if (fuelTank.getCurrentFuelTankCapacity() < fuelNeeded) {
        throw insufficient_fuel_error("Not enough fuel to drive the requested distance!");
    }

    mileage += km;
    fuelTank.useFuel(fuelNeeded);
}

void Car::printCarInfo() const {
    std::cout << "Car Information: " << std::endl;
    std::cout << "Mileage: " << mileage << " km" << std::endl;
    std::cout << "Weight: " << weight << " kg" << std::endl;

    std::cout << "Fuel Tank:" << std::endl;
    std::cout << fuelTank << std::endl;

    std::cout << "Engine: ";
    std::cout << engine << std::endl;

    std::cout << "Tires: " << std::endl;
    for (size_t i = 0; i < MAX_NUMBER_OF_TIRES; ++i) {
        std::cout << "Tire " << i + 1 << ": " << tires[i] << std::endl;
    }

    std::cout << "Battery:" << std::endl;
    std::cout << battery << std::endl;
}

void Car::copyFrom(const Car& other) {
    this->fuelTank = other.fuelTank;
    this->engine = other.engine;

    if (other.tires == nullptr) {
        throw std::invalid_argument("Tires cannot be null!");
    }

    for (size_t i = 0; i < MAX_NUMBER_OF_TIRES; ++i) {
        this->tires[i] = other.tires[i];
    }

    this->battery = other.battery;

    if (other.mileage < 0) {
        throw std::invalid_argument("Mileage cannot be negative number!");
    }

    this->mileage = other.mileage;

    if (other.weight < 0) {
        throw std::invalid_argument("Weight cannot be negative number!");
    }

    this->weight = other.weight;
}

void Car::moveFrom(Car&& other) noexcept {
    this->fuelTank = other.fuelTank;
    this->engine = other.engine;
    for (int i = 0; i < MAX_NUMBER_OF_TIRES; ++i) {
        this->tires[i] = other.tires[i];
    }
    this->battery = other.battery;
    this->mileage = other.mileage;
    this->weight = other.weight;

    other.fuelTank = FuelTank();
    other.engine = Engine();
    for (int i = 0; i < 4; ++i) {
        other.tires[i] = Tire();
    }
    other.battery = Battery();
    other.mileage = 0;
    other.weight = 0;
}

void Car::freeCar() {
    this->mileage = 0;
    this->weight = 0;

    this->fuelTank = FuelTank();
    this->engine = Engine();
    this->battery = Battery();

    for (int i = 0; i < MAX_NUMBER_OF_TIRES; ++i) {
        this->tires[i] = Tire();
    }
}

void Car::setFuelTank(const FuelTank& fuelTank) {
    this->fuelTank = fuelTank;
}

void Car::setEngine(const Engine& engine) {
    this->engine = engine;
}

void Car::setTires(const Tire* tires) {
    if (tires == nullptr) {
        throw std::invalid_argument("Tires cannot be null!");
    }

    for (size_t i = 0; i < MAX_NUMBER_OF_TIRES; ++i) {
        this->tires[i] = tires[i];
    }
}

void Car::setBattery(const Battery& battery) {
    this->battery = battery;
}

void Car::setMileage(double mileage) {
    if (mileage < 0) {
        throw std::invalid_argument("Mileage cannot be negative number!");
    }

    this->mileage = mileage;
}

void Car::setWeight(double weight) {
    if (weight < 0) {
        throw std::invalid_argument("Weight cannot be negative number!");
    }

    this->weight = weight;
}

Car::Car(const FuelTank& fuelTank, const Engine& engine, const Tire* tires, const Battery& battery, double mileage, double weight) {
    setFuelTank(fuelTank);
    setEngine(engine);
    setTires(tires);
    setBattery(battery);
    setMileage(mileage);
    setWeight(weight);
}

Car::Car() {
    this->fuelTank = FuelTank();
    this->engine = Engine();
    for (int i = 0; i < 4; ++i) {
        this->tires[i] = Tire();
    }
    this->battery = Battery();
    this->mileage = 0;
    this->weight = 0;
}

Car::Car(const Car& other) {
    this->copyFrom(other);
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        this->freeCar();
        this->copyFrom(other);
    }

    return *this;
}

Car::Car(Car&& other) noexcept {
    this->moveFrom(std::move(other));
}

Car& Car::operator=(Car&& other) noexcept {
    if (this != &other) {
        this->freeCar();
        this->moveFrom(std::move(other));
    }

    return *this;
}

Car::~Car() {
    this->freeCar();
}

Car* dragRace(Car* car1, Car* car2) {
    double raceMileage = 0.4;
    double fuelNeeded = raceMileage * 1.0;

    bool car1HasFuel = car1->getFuelTank().getCurrentFuelTankCapacity() >= fuelNeeded;
    bool car2HasFuel = car2->getFuelTank().getCurrentFuelTankCapacity() >= fuelNeeded;

    if (car1HasFuel && !car2HasFuel) {
        return car1;
    }
    else if (!car1HasFuel && car2HasFuel) {
        return car2;
    }
    else if (!car1HasFuel && !car2HasFuel) {
        return nullptr;
    }

    double propCar1 = car1->getWeight() / car1->getEngine().getHorsePower();
    double propCar2 = car2->getWeight() / car2->getEngine().getHorsePower();


    if (propCar1 - propCar2 > EPSILON) {
        return car1;
    }
    else if (propCar2 - propCar1 > EPSILON) {
        return car2;
    }
    else {
        return nullptr;
    }
}