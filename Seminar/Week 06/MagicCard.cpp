#include "MagicCard.h"
#include<iostream>
#include<cstring>

#pragma warning(disable:4996)

MagicCard::MagicCard(const char* newName, CardType newType, const char* newEffect) {
	setName(newName);
	setCardType(newType);
	setEffect(newEffect);
}

MagicCard::MagicCard() {
	this->name[0] = '\0';
	this->type = CardType::trap;
	this->effect[0] = '\0';
}

void MagicCard::setName(const char* newName) {
	if (strlen(newName) > MAX_CARD_NAME_LEN) {
		std::cerr << "The length of the name is out of array bounds!" << std::endl;
		return;
	}

	strcpy(this->name, newName);
}

void MagicCard::setCardType(CardType newType) {
	this->type = newType;
}

void MagicCard::setEffect(const char* newEffect) {
	if (strlen(newEffect) > MAX_EFFECT_LEN) {
		std::cerr << "The length of the effects is out of array bounds!" << std::endl;
		return;
	}

	strcpy(this->effect, newEffect);
}

const char* MagicCard::getName() const {
	return this->name;
}

CardType MagicCard::getType() const {
	return this->type;
}

const char* MagicCard::getEffect() const {
	return this->effect;
}

const void MagicCard::printMagicCardInfo() {
	std::cout << "Magic card: " << std::endl;
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Type: ";
	switch (this->type) {
	case CardType::trap:
		std::cout << "trap" << std::endl;
		break;
	case CardType::buff:
		std::cout << "buff" << std::endl;
		break;
	case CardType::spell:
		std::cout << "spell" << std::endl;
		break;
	}

	std::cout << "Effect: " << this->effect << std::endl;

	std::cout << std::endl;
}
