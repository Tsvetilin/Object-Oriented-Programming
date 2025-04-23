#include "Location.h"

Location::Location(int x, int y) {
	setX(x);
	setY(y);
}

Location::Location() {
	this->x = 0;
	this->y = 0;
}

void Location::setX(int x) {
	this->x = x;
}

void Location::setY(int y) {
	this->y = y;
}

int Location::getX() const {
	return x;
}

int Location::getY() const {
	return y;
}

void Location::printLocation() const {
	std::cout << "Location coordinates:" << std::endl;
	std::cout << "X: " << this->x << std::endl;
	std::cout << "Y: " << this->y << std::endl;
}
