#include "Circle.h"

Circle::Circle(Point& center, double radius) {
	setCenter(center);
	setRadius(radius);
}

Circle::Circle() {
	this->center = Point();
	this->radius = 1.0;
}

void Circle::setCenter(Point& center) {
	this->center = center;
}

void Circle::setRadius(double radius) {
	if (radius <= 0) {
		throw std::invalid_argument("Radius must be positive");
	}

	this->radius = radius;
}

Point Circle::getCenter() const {
	return this->center;
}

double Circle::getRadius() const {
	return this->radius;
}

double Circle::getPerimeter() const {
	return 2 * PI * this->radius;
}

double Circle::getArea() const {
	return PI * pow(this->radius, 2);
}

bool Circle::isPointInside(const Point& P) const {
	double distance = sqrt(pow(P.getX() - this->center.getX(), 2) + pow(P.getY() - this->center.getY(), 2));
	if (distance < this->radius) {
		return true;
	}

	return false;
}