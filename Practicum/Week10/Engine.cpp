#include "Engine.h"

void Engine::setHorsePower(int horsePower) {
	if (horsePower < 0) {
		throw std::invalid_argument("Invalid horse power!");
	}

	this->horsePower = horsePower;
}

int Engine::getHorsePower() const {
	return this->horsePower;
}

void Engine::copyFrom(const Engine& other) {
	if (other.horsePower < 0) {
		throw std::invalid_argument("Invalid horse power!");
	}

	this->horsePower = other.horsePower;
}

void Engine::moveFrom(Engine&& other) noexcept {
	this->horsePower = other.horsePower;

	other.horsePower = 0;
}

void Engine::freeEngine() {
	this->horsePower = 0;
}

Engine::Engine(int id, const char* manufacturer, const char* description, int horsePower): CarPart(id,manufacturer,description) {
	setHorsePower(horsePower);
}

Engine::Engine(): CarPart() {
	this->horsePower = 0;
}

Engine::Engine(const Engine& other): CarPart(other) {
	this->copyFrom(other);
}

Engine& Engine::operator=(const Engine& other) {
	if (this != &other) {
		CarPart::operator=(other);
		this->freeEngine();
		this->copyFrom(other);
	}

	return *this;
}

Engine::Engine(Engine&& other) noexcept: CarPart(std::move(other)) {
	this->moveFrom(std::move(other));
}

Engine& Engine::operator=(Engine&& other) noexcept {
	if (this != &other) {
		CarPart::operator=(std::move(other));
		this->freeEngine();
		this->moveFrom(std::move(other));
	}

	return *this;
}

Engine::~Engine() {
	this->freeEngine();
}

std::ostream& operator<<(std::ostream& os, const Engine& engine) {
	const CarPart& base = engine;
	operator<<(os, base);
	os << " - " << engine.getHorsePower() << " HP";
	return os;
}