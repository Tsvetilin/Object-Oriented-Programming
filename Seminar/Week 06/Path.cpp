#include "Path.h"
#include<iostream>

Path::Path(size_t size, size_t capacity, Town* towns) {
	setSize(size);
	setCapacity(capacity);

	if (size > capacity) {
		std::cerr << "Size exceeds capacity!" << std::endl;
		return;
	}

	setTowns(towns);
}

Path::Path() {
	this->size = 0;
	this->capacity = 0;
	this->towns = nullptr;
}

Path::Path(const Path& other){
	this->copyFrom(other);
}

Path& Path::operator=(const Path& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

Path::~Path() {
	this->free();
}

void Path::setSize(size_t size) {
	if (size < 0) {
		std::cerr << "Invalid size of towns!" << std::endl;
		return;
	}

	this->size = size;
}

void Path::setCapacity(size_t capacity) {
	if (capacity < 0) {
		std::cerr << "Invalid capacity of towns!" << std::endl;
		return;
	}

	this->capacity = capacity;
}

void Path::setTowns(const Town* towns) {
	if (towns == nullptr) {
		std::cerr << "Invalid town array!" << std::endl;
		return;
	}

	if (getSize() > getCapacity()) {
		std::cerr << "Size exceeds capacity!" << std::endl;
		return;
	}

	if (this->towns != nullptr) {
		this->free();
	}

	this->towns = new Town[getSize()];

	for (size_t i = 0; i < getSize(); ++i) {
		this->towns[i] = towns[i];
	}
}

size_t Path::getSize() const {
	return this->size;
}

size_t Path::getCapacity() const {
	return this->capacity;
}

const Town* Path::getTowns() const {
	return this->towns;
}

bool Path::townExists(size_t id) {
	for (size_t i = 0; i < this->size; ++i) {
		if (this->towns[i].getId() == id) {
			return true;
		}
	}

	return false;
}

void Path::addTown(const Town& newTown) {
	if (townExists(newTown.getId())) {
		std::cerr << "The operation wasn't successful - the town already exists!" << std::endl;
		return;
	}

	if (this->size + 1 == this->capacity) {
		resizePath();
	}

	this->towns[this->size] = newTown;
	++this->size;
}

size_t Path::getTownIndex(const Town& town) {
	size_t townIndex = -1;

	for (size_t i = 0; i < this->size; ++i) {
		if (this->towns[i].getId() == town.getId()) {
			townIndex = i;
		}
	}

	if (townIndex == -1) {
		return townIndex;
	}

	return townIndex;
}

void Path::removeTown(const Town& toBeRemoved) {
	if (!townExists(toBeRemoved.getId())) {
		std::cerr << "The operation wasn't successful - the town wasn't found!" << std::endl;
		return;
	}

	int townIndex = getTownIndex(toBeRemoved);

	for (size_t i = townIndex; i < this->size - 1; ++i) {
		this->towns[i] = this->towns[i + 1];
	}

	--this->size;
}

void Path::printPath() {
	std::cout << "Path: ";
	if (towns == nullptr || getSize() == 0) {
		std::cout << "(Empty Path)" << std::endl;
		return;
	}

	for (size_t i = 0; i < getSize(); ++i) {
		std::cout << towns[i].getId() << " < ";
	}
	std::cout << std::endl;
}

Path Path::unite(const Path& other) {
	Path unitedPath;

	size_t i = 0, j = 0;

	while (i < this->size && j < other.size) {
		if (this->towns[i].getId() < other.towns[j].getId()) {
			unitedPath.addTown(this->towns[i++]);
		}
		else if (this->towns[i].getId() > other.towns[j].getId()) {
			unitedPath.addTown(other.towns[j++]);
		}
		else {
			unitedPath.addTown(this->towns[i]);
			++i;
			++j;
		}
	}

	while (i < this->size) {
		unitedPath.addTown(this->towns[i++]);
	}
	while (j < other.size) {
		unitedPath.addTown(other.towns[j++]);
	}

	return unitedPath;
}

Path Path::intersect(const Path& other) {
	Path result;
	size_t i = 0, j = 0;

	while (i < this->size && j < other.size) {
		if (this->towns[i].getId() < other.towns[j].getId()) {
			++i;
		}
		else if (this->towns[i].getId() > other.towns[j].getId()) {
			++j;
		}
		else {
			if (!result.townExists(this->towns[i].getId())) {
				result.addTown(this->towns[i]);
			}
			++i;
			++j;
		}
	}

	return result;
}

bool Path::containSameTowns(const Path& path1, const Path& path2) const {
	size_t i = 0, j = 0;

	while (i < path1.size && j < path2.size) {
		if (path1.towns[i].getId() == path2.towns[j].getId()) {
			return true;
		}
		else if (path1.towns[i].getId() < path2.towns[j].getId()) {
			++i;
		}
		else {
			++j;
		}
	}
	return false;
}

bool Path::isPathEmpty(const Path& path) const {
	if (path.getSize() == 0) {
		return true;
	}

	return false;
}

size_t Path::countTownsInPath(const Path& path) const {
	return path.getSize();
}

bool Path::containsTown(size_t index) const {
	if (binarySearchAlgorithm(index) == -1) {
		return false;
	}

	return true;
}

size_t* Path::getIdsOfAllTownsInPath(const Path& path) const {
	size_t* indices = new size_t[path.size];

	for (size_t i = 0; i < path.size; ++i) {
		indices[i] = path.towns[i].getId();
	}

	return indices;
}

void Path::copyFrom(const Path& other) {
	if (this->towns == other.towns) {
		return;
	}

	if (other.size < 0 || other.capacity < 0 || other.size > other.capacity) {
		std::cerr << "Invalid map properties!" << std::endl;
		this->towns = nullptr;
		this->size = this->capacity = 0;
		return;
	}

	if (other.towns == nullptr || other.size == 0) {
		this->towns = nullptr;
		this->size = this->capacity = 0;
		return;
	}

	this->size = other.size;
	this->capacity = other.capacity;
	this->towns = new Town[this->capacity];

	for (size_t i = 0; i < this->size; ++i) {
		this->towns[i] = other.towns[i];
	}
}

void Path::free() {
	delete[] this->towns;
	this->towns = nullptr;
	this->size = 0;
	this->capacity = 0;
}

void Path::resizePath() {
	if (this->towns == nullptr) {
		this->towns = new Town[this->capacity * 2];
	}
	else {
		Town* temp = new Town[this->capacity * 2];
		for (size_t i = 0; i < this->size; ++i) {
			temp[i] = this->towns[i];
		}
		delete[] this->towns;
		this->towns = temp;
	}

	this->capacity *= 2;
}

size_t Path::binarySearchAlgorithm(int id) const {
	size_t low = 0;
	size_t high = this->size;

	while (low < high) {
		size_t mid = low + (high - low) / 2;

		if (this->towns[mid].getId() == id) {
			return mid;
		}
		else if (this->towns[mid].getId() < id) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	return -1;
}