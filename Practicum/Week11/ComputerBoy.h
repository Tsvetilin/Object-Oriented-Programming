#ifndef _COMPUTERBOY_H
#define _COMPUTERBOY_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "Reward.h"

class ComputerBoy : public Reward {
public:
	ComputerBoy();

	void visualize() const override;
};
#endif // !_COMPUTERBOY_H
