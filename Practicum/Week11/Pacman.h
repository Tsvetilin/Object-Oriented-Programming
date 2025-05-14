#ifndef _PACMAN_H
#define _PACMAN_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "Reward.h"

class Pacman : public Reward {
public:
	Pacman();

	void visualize() const override;
};
#endif // !_PACMAN_H
