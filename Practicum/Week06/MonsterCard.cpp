#include "MonsterCard.h"
#include<iostream>
#include<cstring>

#pragma warning(disable:4996)

void MonsterCard::copyFrom(const MonsterCard& other) {
	if (other.name == nullptr) {
		std::cerr << "You new card name is invalid!" << std::endl;
		return;
	}

	if (this->name == other.name) {
		std::cerr << "The name of your card is the same as the previous one!" << std::endl;
		return;
	}

	if (this->name != nullptr) {
		this->freeName();
	}

	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	if (other.attackPoints < 0) {
		std::cerr << "Invalid attack points!" << std::endl;
		return;
	}

	this->attackPoints = other.attackPoints;

	if (other.protectPoints < 0) {
		std::cerr << "Invalid protect points!" << std::endl;
		return;
	}

	this->protectPoints = other.protectPoints;
}

void MonsterCard::freeName() {
	delete[] this->name;
	this->name = nullptr;
}

void MonsterCard::free() {
	this->freeName();
}

MonsterCard::MonsterCard(const char* newName, unsigned int newAttackPoints, unsigned int newProtectPoints) {
	setName(newName);
	setAttackPoints(newAttackPoints);
	setProtectPoints(newProtectPoints);
}

MonsterCard::MonsterCard() {
	this->name = nullptr;
	this->attackPoints = 0;
	this->protectPoints = 0;
}

MonsterCard::MonsterCard(const MonsterCard& other) {
	this->copyFrom(other);
}

MonsterCard& MonsterCard::operator=(const MonsterCard& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

MonsterCard::~MonsterCard() {
	this->free();
}

void MonsterCard::setName(const char* newName) {
	if (newName == nullptr) {
		std::cerr << "You new card name is invalid!" << std::endl;
		return;
	}

	if (this->name == newName) {
		std::cerr << "The name of your card is the same as the previous one!" << std::endl;
		return;
	}

	if (this->name != nullptr) {
		this->freeName();
	}

	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
}

void MonsterCard::setAttackPoints(unsigned int newAttackPoints) {
	if (newAttackPoints < 0) {
		std::cerr << "Invalid attack points!" << std::endl;
		return;
	}

	this->attackPoints = newAttackPoints;
}

void MonsterCard::setProtectPoints(unsigned int newProtectPoints) {
	if (newProtectPoints < 0) {
		std::cerr << "Invalid protect points!" << std::endl;
		return;
	}

	this->protectPoints = newProtectPoints;
}

const char* MonsterCard::getName() const {
	return this->name;
}

unsigned int MonsterCard::getAttackPoints() const {
	return this->attackPoints;
}

unsigned int MonsterCard::getProtectPoints() const {
	return this->protectPoints;
}

void MonsterCard::printMonsterCardInfo() const {
	std::cout << "Monster card:" << std::endl;
	std::cout << "Name: " << this->name;
	std::cout << "Attack points: " << this->attackPoints;
	std::cout << "Protect points: " << this->protectPoints;

	std::cout << std::endl;
}
