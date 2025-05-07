#include "Computer.h"

#pragma warning(disable: 4996)

int Computer::serialNumber = 0;

Computer::Computer(const char* brand, const char* processor, int video, int hardDrive, int weight, int batteryLife, double price, int quantity) {
    ++serialNumber;

    if (!brand || !processor) {
        throw std::invalid_argument("Brand or processor cannot be null!");
    }
    if (video < 0 || hardDrive < 0 || weight < 0 || batteryLife < 0 || price < 0 || quantity < 0) {
        throw std::invalid_argument("Numerical attributes must be non-negative!");
    }

    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);

    this->processor = new char[strlen(processor) + 1];
    strcpy(this->processor, processor);

    this->video = video;
    this->hardDrive = hardDrive;
    this->weight = weight;
    this->batteryLife = batteryLife;
    this->price = price;
    this->quantity = quantity;
}

Computer::Computer() {
    ++serialNumber;
    this->brand = nullptr;
    this->processor = nullptr;
    this->video = 0;
    this->hardDrive = 0;
    this->weight = 0;
    this->batteryLife = 0;
    this->price = 0.0;
    this->quantity = 0;
}

Computer::Computer(const Computer& other) {
    copyFrom(other);
}

Computer& Computer::operator=(const Computer& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }

    return *this;
}

Computer::~Computer() {
    this->free();
}

void Computer::setQuantity(int quantity) {
    if (quantity < 0) {
        throw std::invalid_argument("Quantity cannot be negative!");
    }

    this->quantity = quantity;
}

int Computer::getSerialNumber() {
    return serialNumber;
}

const char* Computer::getBrand() const { 
    return this->brand; 
}

const char* Computer::getProcessor() const {
    return this->processor; 
}

int Computer::getVideo() const { 
    return this->video; 
}

int Computer::getHardDrive() const {
    return this->hardDrive;
}

int Computer::getWeight() const { 
    return this->weight;
}

int Computer::getBatteryLife() const { 
    return this->batteryLife; 
}
double Computer::getPrice() const { 
    return this->price;
}
int Computer::getQuantity() const { 
    return this->quantity; 
}

void Computer::print() const {
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Processor: " << processor << std::endl;
    std::cout << "Video: " << video << " GB" << std::endl;
    std::cout << "Hard Drive: " << hardDrive << " GB" << std::endl;
    std::cout << "Weight: " << weight << " kg" << std::endl;
    std::cout << "Battery Life: " << batteryLife << " hrs" << std::endl;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;

    std::cout << std::endl;
}

void Computer::copyFrom(const Computer& other) {
    this->brand = new char[strlen(other.brand) + 1];
    strcpy(this->brand, other.brand);

    this->processor = new char[strlen(other.processor) + 1];
    strcpy(this->processor, other.processor);

    this->video = other.video;
    this->hardDrive = other.hardDrive;
    this->weight = other.weight;
    this->batteryLife = other.batteryLife;
    this->price = other.price;
    this->quantity = other.quantity;
}

void Computer::freeBrand() {
    delete[] this->brand;
    this->brand = nullptr;
}

void Computer::freeProcessor() {
    delete[] this->processor;
    this->processor = nullptr;
}

void Computer::free() {
    this->freeBrand();
    this->freeProcessor();
    this->video = 0;
    this->hardDrive = 0;
    this->weight = 0;
    this->batteryLife = 0;
    this->price = 0;
    this->quantity = 0;
}