#pragma once
#include  "Computer.h"


class UtilityClass
{
private:
	static bool isProcForGaming(const char* proc);
	static bool isVideoForGaming(int video);
	static bool isHddForGaming(size_t hdd);
	
	static bool isWeightForTravel(size_t weight);
	static bool isBatterryForTravel(size_t batterry);
public:
	static bool isGoodForGaming(Computer comp);
	static bool isGoodForTravel(Computer comp);
};

