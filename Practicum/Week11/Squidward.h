#ifndef _SQUIDWARD_H
#define _SQUIDWARD_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "Reward.h"

class Squidward : public Reward {
public:
	Squidward();

	void visualize() const override;
};

#endif // !_SQUIDWARD_H