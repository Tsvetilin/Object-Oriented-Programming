#include "PremiumPlayer.h"
#pragma warning(disable : 4996)

PremiumPlayer::PremiumPlayer(const char* password, const char* name) : LoggedPlayer(password) {
	if (name == nullptr) {
		throw std::invalid_argument("Name cannot be null");
	}

	this->freeName();

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

PremiumPlayer::PremiumPlayer(const PremiumPlayer& other) : LoggedPlayer(other) {
	this->copyFrom(other);
}

PremiumPlayer& PremiumPlayer::operator=(const PremiumPlayer& other) {
	if (this != &other) {
		this->freeName();
		this->copyFrom(other);
	}

	return *this;
}

PremiumPlayer::PremiumPlayer(PremiumPlayer&& other) noexcept : LoggedPlayer(std::move(other)) {
	this->moveFrom(std::move(other));
}

PremiumPlayer& PremiumPlayer::operator=(PremiumPlayer&& other) noexcept {
	if (this != &other) {
		this->freeName();
		this->moveFrom(std::move(other));
	}

	return *this;
}

PremiumPlayer::~PremiumPlayer() {
	this->freeName();
}

const char* PremiumPlayer::getName() const {
	return this->name;
}

void PremiumPlayer::sendMessage(const char* message) const {
	if (message == nullptr) {
		throw std::invalid_argument("Message cannot be null");
	}

	std::cout << "Message from " << this->name << ": " << message << std::endl;
}

bool PremiumPlayer::levelUp() {
	if (getStars() == Stars::FIVE) {
		return false;
	}

	if (getPoints() >= 256) {
		completeMission(-256);

		Stars newStars = (Stars)((int)(getStars()) + 1);
		setStars(newStars);

		return true;
	}

	return false;
}

void PremiumPlayer::copyFrom(const PremiumPlayer& other) {
	if (other.name == nullptr) {
		throw std::invalid_argument("Name cannot be null");
	}

	this->freeName();

	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}

void PremiumPlayer::moveFrom(PremiumPlayer&& other) noexcept {
	this->name = other.name;
	other.name = nullptr;
}

void PremiumPlayer::freeName() {
	delete[] this->name;
	this->name = nullptr;
}