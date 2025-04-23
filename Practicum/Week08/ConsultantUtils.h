#ifndef _CONSULTANTUTILS_H
#define _CONSULTANTUTILS_H

#include "Computer.h"
#include <cstring>

class Computer;

class ConsultantUtils {
public:
	static bool isGoodForGaming(const Computer& comp);
	static bool isGoodForTravel(const Computer& comp);
};

#endif // !_CONSULTANTUTILS_H