#include "Sphynx.h"

Sphynx::Sphynx() : Monster(SPHYNX) {}

MonsterType Sphynx::getType() const {
    return SPHYNX;
}

bool Sphynx::canBeat(const Monster* other) const {
    return other->getType() == CENTAUR;
}

const char* Sphynx::getTypeName() const {
    return "Sphynx";
}