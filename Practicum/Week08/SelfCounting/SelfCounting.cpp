#include "SelfCounting.h"

int SelfCounting::liveObjects = 0;
int SelfCounting::createdObjects = 0;

SelfCounting::SelfCounting() : SelfCounting(42)
{
}

SelfCounting::SelfCounting(int const_val) : const_val(const_val)
{
	liveObjects++;
	createdObjects++;
}

SelfCounting::SelfCounting(const SelfCounting& other) : const_val(other.const_val)
{
	liveObjects++;
	createdObjects++;
}

int SelfCounting::getLiveObjects()
{
	return liveObjects;
}

int SelfCounting::getCreatedObjects()
{
	return createdObjects;
}

SelfCounting::~SelfCounting()
{
	liveObjects--;
}
