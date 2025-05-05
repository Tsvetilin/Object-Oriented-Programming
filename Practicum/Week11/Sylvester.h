#ifndef _SYLVESTER_H
#define _SYLVESTER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "Reward.h"

class Sylvester : public Reward {
public:
	Sylvester();

	void visualize() const override;
};

#endif // !_SYLVESTER_H