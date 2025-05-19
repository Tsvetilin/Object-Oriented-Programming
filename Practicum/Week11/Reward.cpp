#include "Reward.h"

Reward::Reward(double price, size_t points) {
	setPrice(price);
	setPoints(points);
}

Reward::Reward(size_t points) {
	setPoints(points);
	this->price = 0;
}

Reward::Reward() {
	this->price = 0;
	this->points = 0;
}

void Reward::setPrice(double price) {
	if (price < 0) {
		throw std::invalid_argument("Price cannot be negative");
	}

	this->price = price;
}

void Reward::setPoints(size_t points) {
	if (points < 0) {
		throw std::invalid_argument("Points cannot be negative");
	}

	this->points = points;
}

double Reward::getPrice() const {
	return this->price;
}

size_t Reward::getPoints() const {
	return this->points;
}
