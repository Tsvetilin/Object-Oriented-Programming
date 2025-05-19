#include "Computer.h"
#pragma warning(disable: 4996)

Computer::Computer(double processorPower, const char* videoCardModel, int supplyPower, int RAM) {
	setProcessorPower(processorPower);
	setVideoCardModel(videoCardModel);
	setSupplyPower(supplyPower);
	setRAM(RAM);
}

Computer::Computer(const Computer& other) {
	copyFrom(other);
}

Computer& Computer::operator=(const Computer& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Computer::Computer(Computer&& other) noexcept {
	this->moveFrom(std::move(other));
}

Computer& Computer::operator=(Computer&& other) noexcept {
	if (this != &other) {
		this->free();
		this->moveFrom(std::move(other));
	}

	return *this;
}

Computer::~Computer() {
	this->free();
}

void Computer::setProcessorPower(double processorPower) {
	if (processorPower < 0) {
		throw std::invalid_argument("Processor power cannot be negative");
	}

	this->processorPower = processorPower;
}

void Computer::setVideoCardModel(const char* videoCardModel) {
	if (videoCardModel == nullptr) {
		throw std::invalid_argument("Video card model cannot be null");
	}

	this->freeVideoCardModel();

	this->videoCardModel = new char[strlen(videoCardModel) + 1];
	strcpy(this->videoCardModel, videoCardModel);
}

void Computer::setSupplyPower(int supplyPower) {
	if (supplyPower < 0) {
		throw std::invalid_argument("Supply power cannot be negative");
	}

	this->supplyPower = supplyPower;
}

void Computer::setRAM(int RAM) {
	if (RAM < 0) {
		throw std::invalid_argument("RAM cannot be negative");
	}

	this->RAM = RAM;
}

double Computer::getProcessorPower() const {
	return this->processorPower;
}

const char* Computer::getVideoCardModel() const {
	return this->videoCardModel;
}

int Computer::getSupplyPower() const {
	return this->supplyPower;
}

int Computer::getRAM() const {
	return this->RAM;
}

void Computer::copyFrom(const Computer& other) {
	if (other.processorPower < 0) {
		throw std::invalid_argument("Processor power cannot be negative");
	}

	this->processorPower = other.processorPower;


	if (other.videoCardModel == nullptr) {
		throw std::invalid_argument("Video card model cannot be null");
	}

	this->freeVideoCardModel();

	this->videoCardModel = new char[strlen(other.videoCardModel) + 1];
	strcpy(this->videoCardModel, other.videoCardModel);


	if (other.supplyPower < 0) {
		throw std::invalid_argument("Supply power cannot be negative");
	}

	this->supplyPower = other.supplyPower;


	if (other.RAM < 0) {
		throw std::invalid_argument("RAM cannot be negative");
	}

	this->RAM = other.RAM;
}

void Computer::moveFrom(Computer&& other) noexcept {
	this->processorPower = other.processorPower;
	this->videoCardModel = other.videoCardModel;
	this->supplyPower = other.supplyPower;
	this->RAM = other.RAM;

	other.processorPower = 0;
	other.videoCardModel = nullptr;
	other.supplyPower = 0;
	other.RAM = 0;
}

void Computer::freeVideoCardModel() {
	delete[] this->videoCardModel;
	this->videoCardModel = nullptr;
}

void Computer::free() {
	this->freeVideoCardModel();
	this->processorPower = 0;
	this->supplyPower = 0;
	this->RAM = 0;
}