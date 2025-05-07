#include "ComputerStore.h"
#pragma warning(disable: 4996)

ComputerStore::ComputerStore(const char* storeName) {
	setStoreName(storeName);
	this->computers = nullptr;
	this->size = 0;
}

ComputerStore::ComputerStore(const char* storeName, const Computer* computers, size_t size) {
	setStoreName(storeName);
	setComputers(computers, size);
}

ComputerStore::ComputerStore() {
	this->storeName = nullptr;
	this->computers = nullptr;
	this->size = 0;
}

ComputerStore::ComputerStore(const ComputerStore& other) {
	this->copyFrom(other);
}

ComputerStore& ComputerStore::operator=(const ComputerStore& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

ComputerStore::~ComputerStore() {
	this->free();
}

void ComputerStore::setStoreName(const char* storeName) {
	if (storeName == nullptr) {
		throw std::invalid_argument("Store name cannot be null!");
	}

	if (this->storeName == storeName) {
		throw std::invalid_argument("Store name already set!");
	}

	if (this->storeName != nullptr) {
		this->freeStoreName();
	}

	this->storeName = new char[strlen(storeName) + 1];
	strcpy(this->storeName, storeName);
}

void ComputerStore::setComputers(const Computer* computers, size_t size) {
	if (size < 0) {
		throw std::invalid_argument("Size cannot be negative!");
	}

	if (capacity < 0) {
		throw std::invalid_argument("Capacity cannot be negative!");
	}

	if (computers == nullptr) {
		throw std::invalid_argument("Computers cannot be null!");
	}

	if (this->computers == computers) {
		throw std::invalid_argument("Computers already set!");
	}

	if (this->computers != nullptr) {
		this->freeComputers();
	}

	this->capacity = capacity;
	this->size = size;
	this->computers = new Computer[capacity];
	for (size_t i = 0; i < size; ++i) {
		this->computers[i] = computers[i];
	}
}

const char* ComputerStore::getStoreName() const {
	return this->storeName;
}

const Computer* ComputerStore::getComputers() const {
	return this->computers;
}

size_t ComputerStore::getSize() const {
	return this->size;
}

void ComputerStore::addComputer(const Computer& computer) {
	if (this->size >= this->capacity) {
		this->resize();
	}

	this->computers[this->size] = computer;
	this->size++;
}

void ComputerStore::printAll() const {
	for (size_t i = 0; i < this->size; ++i) {
		this->computers[i].print();
		std::cout << std::endl;
	}
}

void ComputerStore::buy(const char* brand, double money) {
	if (brand == nullptr) {
		throw std::invalid_argument("Brand cannot be null!");
	}

	if (money < 0) {
		throw std::invalid_argument("Money cannot be negative!");
	}

	for (size_t i = 0; i < this->size; ++i) {
		if (strcmp(this->computers[i].getBrand(), brand) == 0 && this->computers[i].getPrice() <= money) {
			this->computers[i].setQuantity(this->computers[i].getQuantity() - 1);
			std::cout << "You bought a " << brand << " computer!" << std::endl;
			return;
		}
	}

	std::cout << "No computer found with the specified brand and price!" << std::endl;
}

void ComputerStore::printAvailable(bool travel, bool gaming) const {
	for (int i = 0; i < size; ++i) {
		if (computers[i].getQuantity() > 0) {
			if (travel && !ConsultantUtils::isGoodForTravel(computers[i])) {
				continue;
			}
			if (gaming && !ConsultantUtils::isGoodForGaming(computers[i])) {
				continue;
			}
			computers[i].print();
		}
	}
}

void ComputerStore::resize() {
	Computer* newComputers = new Computer[this->capacity];
	for (size_t i = 0; i < this->size; ++i) {
		newComputers[i] = this->computers[i];
	}

	delete[] this->computers;
	this->computers = newComputers;
}

void ComputerStore::copyFrom(const ComputerStore& other) {
	if (other.storeName == nullptr) {
		throw std::invalid_argument("Store name cannot be null!");
	}

	if (this->storeName == other.storeName) {
		throw std::invalid_argument("Store name already set!");
	}

	if (this->storeName != nullptr) {
		this->freeStoreName();
	}

	this->storeName = new char[strlen(other.storeName) + 1];
	strcpy(this->storeName, other.storeName);


	if (other.size < 0) {
		throw std::invalid_argument("Size cannot be negative!");
	}

	if (other.capacity < 0) {
		throw std::invalid_argument("Capacity cannot be negative!");
	}

	if (other.computers == nullptr) {
		throw std::invalid_argument("Computers cannot be null!");
	}

	if (this->computers == other.computers) {
		throw std::invalid_argument("Computers already set!");
	}

	if (this->computers != nullptr) {
		this->freeComputers();
	}

	this->capacity = other.capacity;
	this->size = other.size;
	this->computers = new Computer[other.capacity];
	for (size_t i = 0; i < other.size; ++i) {
		this->computers[i] = other.computers[i];
	}
}

void ComputerStore::freeComputers() {
	delete[] this->computers;
	this->computers = nullptr;
	this->size = 0;
	this->capacity = 0;
}

void ComputerStore::freeStoreName() {
	delete[] this->storeName;
	this->storeName = nullptr;
}

void ComputerStore::free() {
	this->freeStoreName();
	this->freeComputers();
}
