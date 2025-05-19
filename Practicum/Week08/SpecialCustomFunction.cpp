#include "SpecialCustomFunction.h"

SpecialCustomFunction::SpecialCustomFunction(int(*func)(int), const int* specialSymbols, size_t specialSymbolsSize) {
	setFunction(func);
	setSpecialSymbols(specialSymbols, specialSymbolsSize);
}

SpecialCustomFunction::SpecialCustomFunction() {
	this->func = nullptr;
	this->specialSymbols = nullptr;
	this->specialSymbolsSize = 0;
}

SpecialCustomFunction::SpecialCustomFunction(const SpecialCustomFunction& other) {
	this->copyFrom(other);
}

SpecialCustomFunction& SpecialCustomFunction::operator=(const SpecialCustomFunction& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

SpecialCustomFunction::~SpecialCustomFunction() {
	this->free();
}

void SpecialCustomFunction::setFunction(int(*func)(int)) {
	if (func == nullptr) {
		throw std::invalid_argument("Function pointer cannot be null!");
	}

	this->func = func;
}

void SpecialCustomFunction::setSpecialSymbols(const int* specialSymbols, size_t specialSymbolsSize) {
	if (specialSymbols == nullptr) {
		throw std::invalid_argument("Special symbols array cannot be null!");
	}

	if (this->specialSymbols == specialSymbols) {
		throw std::invalid_argument("The special symbols are already set!");
	}

	if (this->specialSymbols != nullptr) {
		this->free();
	}

	if (specialSymbolsSize < 0) {
		throw std::invalid_argument("Special symbols size cannot be negative!");
	}

	this->specialSymbolsSize = specialSymbolsSize;
	this->specialSymbols = new int[specialSymbolsSize];
	for (size_t i = 0; i < specialSymbolsSize; ++i) {
		this->specialSymbols[i] = specialSymbols[i];
	}
}

int SpecialCustomFunction::getFunction(int x) const {
	return func(x);
}

const int* SpecialCustomFunction::getSpecialSymbols() const {
	return this->specialSymbols;
}

size_t SpecialCustomFunction::getSpecialSymbolsSize() const {
	return this->specialSymbolsSize;
}

int SpecialCustomFunction::operator()(int value) {
	for (size_t i = 0; i < this->specialSymbolsSize; ++i) {
		if (this->specialSymbols[i] == value) {
			return value * value;
		}
	}

	return this->func(value);
}

SpecialCustomFunction& SpecialCustomFunction::operator++() {
	for (size_t i = 0; i < this->specialSymbolsSize; ++i) {
		++this->specialSymbols[i];
	}

	return *this;
}

SpecialCustomFunction& SpecialCustomFunction::operator--() {
	for (size_t i = 0; i < this->specialSymbolsSize; ++i) {
		--this->specialSymbols[i];
	}

	return *this;
}

SpecialCustomFunction SpecialCustomFunction::operator!() const {
	SpecialCustomFunction result;

	result.func = this->func;

	result.specialSymbolsSize = specialSymbolsSize;
	result.specialSymbols = new int[specialSymbolsSize];

	for (size_t i = 0; i < specialSymbolsSize; ++i) {
		result.specialSymbols[i] = -specialSymbols[i];
	}

	return result;
}

void SpecialCustomFunction::copyFrom(const SpecialCustomFunction& other) {
	this->func = other.func;

	if (other.specialSymbols == nullptr) {
		throw std::invalid_argument("Special symbols array cannot be null!");
	}

	if (this->specialSymbols == other.specialSymbols) {
		throw std::invalid_argument("The special symbols are already set!");
	}

	if (this->specialSymbols != nullptr) {
		this->free();
	}

	this->specialSymbolsSize = other.specialSymbolsSize;
	this->specialSymbols = new int[other.specialSymbolsSize];
	for (size_t i = 0; i < other.specialSymbolsSize; ++i) {
		this->specialSymbols[i] = other.specialSymbols[i];
	}
}

void SpecialCustomFunction::free() {
	delete[] this->specialSymbols;
	this->specialSymbols = nullptr;
	this->specialSymbolsSize = 0;
	this->func = nullptr;
}