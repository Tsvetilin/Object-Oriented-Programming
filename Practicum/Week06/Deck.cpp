#include "Deck.h"
#include<iostream>

Deck::Deck(MonsterCard* newMonsterCards, size_t newMonsterCardsSize, MagicCard* newMagicCards, size_t newMagicCardsSize) {
    setMonsterCards(newMonsterCards, newMonsterCardsSize);
    setMagicCards(newMagicCards, newMagicCardsSize);
}

Deck::Deck() {
    this->monsterCardsSize = 0;
    this->magicCardsSize = 0;
}

Deck::Deck(const Deck& other) {
    this->copyFrom(other);
}

Deck& Deck::operator=(const Deck& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }

    return *this;
}

Deck::~Deck() {
    this->free();
}

void Deck::setMonsterCards(MonsterCard* newMonsterCards, size_t newMonsterCardsSize) {
    if (newMonsterCardsSize > MAX_MONSTER_CARDS_IN_DECK || newMonsterCards == nullptr) {
        std::cerr << "Invalid size!" << std::endl;
        return;
    }

    this->monsterCardsSize = newMonsterCardsSize;

    for (size_t i = 0; i < newMonsterCardsSize; ++i) {
        this->monsterCards[i] = newMonsterCards[i];
    }
}

void Deck::setMagicCards(MagicCard* newMagicCards, size_t newMagicCardsSize) {
    if (newMagicCardsSize > MAX_MAGIC_CARDS_IN_DECK || newMagicCards == nullptr) {
        std::cerr << "Invalid input!" << std::endl;
        return;
    }

    this->magicCardsSize = newMagicCardsSize;

    for (size_t i = 0; i < newMagicCardsSize; ++i) {
        this->magicCards[i] = newMagicCards[i];
    }
}

const MonsterCard* Deck::getMonsterCards() const {
    return this->monsterCards;
}

const MagicCard* Deck::getMagicCards() const {
    return this->magicCards;
}

size_t Deck::getMonsterCardsSize() const {
    return this->monsterCardsSize;
}

size_t Deck::getMagicCardsSize() {
    return this->magicCardsSize;
}

void Deck::addMagicCard(const MagicCard& newCard) {
    if (this->magicCardsSize < MAX_MAGIC_CARDS_IN_DECK) {
        this->magicCards[this->magicCardsSize] = newCard;
        ++this->magicCardsSize;
    }
    else {
        std::cerr << "No more magic cards can be included!" << std::endl;
        return;
    }
}

void Deck::addMonsterCard(const MonsterCard& newCard) {
    if (this->monsterCardsSize < MAX_MONSTER_CARDS_IN_DECK) {
        this->monsterCards[this->monsterCardsSize] = newCard;
        ++this->monsterCardsSize;
    }
    else {
        std::cerr << "No more monster cards can be included!" << std::endl;
        return;
    }
}

void Deck::changeMagicCard(size_t index, const MagicCard& newCard) {
    if (index > MAX_MAGIC_CARDS_IN_DECK) {
        std::cerr << "Invalid index!" << std::endl;
        return;
    }
    
    this->magicCards[index] = newCard;
}

void Deck::changeMonsterCard(size_t index, const MonsterCard& newCard) {
    if (index >= this->monsterCardsSize) {
        std::cerr << "Invalid index!" << std::endl;
        return;
    }

    this->monsterCards[index] = newCard;
}

void Deck::removeMagicCardAt(size_t index) {
    if (index > this->magicCardsSize) {
        std::cerr << "Invalid index!" << std::endl;
        return;
    }

    for (size_t i = index; i < this->magicCardsSize - 1; ++i) {
        this->magicCards[i] = this->magicCards[i + 1];
    }
    --this->magicCardsSize;
}

void Deck::removeMonsterCardAt(size_t index) {
    if (index > this->monsterCardsSize) {
        std::cerr << "Invalid index!" << std::endl;
        return;
    }

    for (size_t i = index; i < this->monsterCardsSize - 1; ++i) {
        this->monsterCards[i] = this->monsterCards[i + 1];
    }
    --this->monsterCardsSize;
}

void Deck::printDeckInfo() const {
    std::cout << "Monster Cards:" << std::endl;
    for (int i = 0; i < this->monsterCardsSize; ++i) {
        std::cout << i + 1 << ". " << monsterCards[i].getName() << " (ATK: " << monsterCards[i].getAttackPoints() << ", DEF: " << monsterCards[i].getProtectPoints() << ")" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Magic Cards:" << std::endl;
    for (int i = 0; i < magicCardsSize; ++i) {
        std::cout << i + 1 << ". " << magicCards[i].getName() << " - " << magicCards[i].getEffect() << std::endl;
    }
    
    std::cout << std::endl;
}

void Deck::copyFrom(const Deck& other) {
    if (other.monsterCardsSize > MAX_MONSTER_CARDS_IN_DECK || other.monsterCards == nullptr) {
        std::cerr << "Invalid input!" << std::endl;
        return;
    }

    this->monsterCardsSize = other.monsterCardsSize;

    for (size_t i = 0; i < other.monsterCardsSize; ++i) {
        this->monsterCards[i] = other.monsterCards[i];
    }

    if (other.magicCardsSize > MAX_MAGIC_CARDS_IN_DECK || other.magicCards == nullptr) {
        std::cerr << "Invalid input!" << std::endl;
        return;
    }

    this->magicCardsSize = other.magicCardsSize;

    for (size_t i = 0; i < other.magicCardsSize; ++i) {
        this->magicCards[i] = other.magicCards[i];
    }
}

void Deck::free() {
    delete[] this->monsterCards;
}
