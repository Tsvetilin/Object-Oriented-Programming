#ifndef _PENGUIN_H
#define _PENGUIN_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "Reward.h"

class Penguin : public Reward {
public:
    Penguin();

    void visualize() const override;
};
#endif // !_PENGUIN_H
