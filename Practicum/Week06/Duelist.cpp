#include "Duelist.h"
#include<iostream>
#include<cstring>

#pragma warning(disable:4996)

Duelist::Duelist(const char* newName, Deck newDeck) {
	setName(newName);
	setDeck(newDeck);
}

Duelist::Duelist(const char* newName) {
	setName(newName);
}

Duelist::Duelist() {
	this->name = nullptr;
	this->deck = Deck();
}

Duelist::Duelist(const Duelist& other) {
	this->copyFrom(other);
}

Duelist& Duelist::operator=(const Duelist& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

Duelist::~Duelist() {
	this->free();
}

void Duelist::setName(const char* newName) {
	if (newName == nullptr) {
		std::cerr << "You new duelist name is invalid!" << std::endl;
		return;
	}

	if (this->name == newName) {
		std::cerr << "The name of your duelist is the same as the previous one!" << std::endl;
		return;
	}

	if (this->name != nullptr) {
		this->freeName();
	}

	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
}

void Duelist::setDeck(Deck newDeck) {
	this->deck = newDeck;
}

void Duelist::nameSetterForObj(const Duelist& other) {
	if (other.name == nullptr) {
		std::cerr << "You new duelist name is invalid!" << std::endl;
		return;
	}

	if (this->name == other.name) {
		std::cerr << "The name of your duelist is the same as the previous one!" << std::endl;
		return;
	}

	if (this->name != nullptr) {
		this->freeName();
	}

	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}

void Duelist::deckSetterForObj(const Duelist& other) {
	this->deck = other.deck;
}

const char* Duelist::getName() const {
	return this->name;
}

Deck Duelist::getDeck() const {
	return this->deck;
}

void Duelist::addMagicCardToDeck(const MagicCard& newCard) {
	this->deck.addMagicCard(newCard);
}

void Duelist::addMonsterCardToDeck(const MonsterCard& newCard) {
	this->deck.addMonsterCard(newCard);
}

void Duelist::changeMagicCardFromDeck(size_t index, const MagicCard& newCard) {
	this->deck.changeMagicCard(index, newCard);
}

void Duelist::changeMonsterCardFromDeck(size_t index, const MonsterCard& newCard) {
	this->deck.changeMonsterCard(index, newCard);
}

void Duelist::removeMagicCardFromDeck(size_t index) {
	this->deck.removeMagicCardAt(index);
}

void Duelist::removeMonsterCardFromDeck(size_t index) {
	this->deck.removeMonsterCardAt(index);
}

void Duelist::copyFrom(const Duelist& other) {
	nameSetterForObj(other);
	deckSetterForObj(other);
}

void Duelist::freeName() {
	delete[] this->name;
	this->name = nullptr;
}

void Duelist::free() {
	this->freeName();
}