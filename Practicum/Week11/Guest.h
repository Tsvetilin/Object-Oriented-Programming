#ifndef _GUEST_H
#define _GUEST_H

#include <iostream>
#include "Player.h"

class Guest : public Player {
public:
    Guest(size_t playTimeMinutes);

    unsigned getPlayTime() const;
    void decreasePlayTime(size_t minutes);
    bool levelUp() override;

private:
    size_t playTimeMinutes;
};

#endif // !_GUEST_H