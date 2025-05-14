#include "Point.h"

Point::Point(double x, double y) {
	setCoordX(x);
	setCoordY(y);
}

Point::Point() {
	this->x = 0;
	this->y = 0;
}

void Point::setCoordX(double x) {
	this->x = x;
}

void Point::setCoordY(double y) {
	this->y = y;
}

double Point::getX() const {
	return this->x;
}

double Point::getY() const {
	return this->y;
}

void Point::printPoint() const {
	std::cout << "Point(" << this->x << ", " << this->y << ")" << std::endl;
}