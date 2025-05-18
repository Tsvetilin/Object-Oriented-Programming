#include "Minotaur.h"

Minotaur::Minotaur() : Monster(MINOTAUR) {}

MonsterType Minotaur::getType() const {
    return MonsterType::MINOTAUR;
}

bool Minotaur::canBeat(const Monster* other) const {
    return other->getType() == SPHYNX;
}

const char* Minotaur::getTypeName() const {
    return "Minotaur";
}