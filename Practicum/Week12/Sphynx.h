#ifndef SPHYNX_H
#define SPHYNX_H

#include "Monster.h"

class Sphynx : public Monster {
public:
    Sphynx();
    MonsterType getType() const override;
    bool canBeat(const Monster* other) const override;
    const char* getTypeName() const override;
};

#endif //!_SPHYNX_H