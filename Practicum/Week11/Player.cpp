#include "Player.h"

int Player::id = 0;

Player::Player(size_t points, Stars stars) {
    setPoints(points);
    setStars(stars);
    ++this->id;
}

Player::Player() {
	this->points = 0;
	this->stars = Stars::ONE;
	++this->id;
}

int Player::getId() const {
	return this->id;
}

size_t Player::getPoints() const {
	return this->points;
}

Stars Player::getStars() const {
	return this->stars;
}

void Player::setPoints(size_t points) {
	this->points = points;
}

void Player::setStars(Stars stars) {
	if (stars < Stars::ONE || stars > Stars::FIVE) {
		throw std::invalid_argument("Invalid star level");
	}

	this->stars = stars;
}

void Player::completeMission(unsigned earnedPoints) {
	this->points += earnedPoints;
}

bool Player::levelUp() {
    int currentStars = (int)(stars);

    if (currentStars >= 5) {
        return false;
    }

    size_t neededPoints = 0;

    switch (currentStars) {
    case 1: neededPoints = 256; break;
    case 2: neededPoints = 512; break;
    case 3: neededPoints = 1024; break;
    case 4: neededPoints = 2048; break;
    default: return false;
    }

    if (points >= neededPoints) {
        points -= neededPoints;
        stars = (Stars)(currentStars + 1);
        return true;
    }

    return false;
}