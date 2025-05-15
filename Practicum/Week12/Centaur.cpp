#include "Centaur.h"

Centaur::Centaur() : Monster(CENTAUR) {}

MonsterType Centaur::getType() const {
    return CENTAUR;
}

bool Centaur::canBeat(const Monster* other) const {
    return other->getType() == MINOTAUR;
}

const char* Centaur::getTypeName() const {
    return "Centaur";
}