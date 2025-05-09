#include "UtilityClass.h"
#include <iostream>


bool UtilityClass::isProcForGaming(const char* proc)
{
    return (strcmp(proc, "i5") == 0 || strcmp(proc, "i7") == 0);
}

bool UtilityClass::isVideoForGaming(int video)
{
    return (video == 3060 || video == 3070 || video == 3080 || video == 3090);
}

bool UtilityClass::isHddForGaming(size_t hdd)
{
    return hdd >= 512;
}

bool UtilityClass::isWeightForTravel(size_t weight)
{
    return weight <= 2500;
}

bool UtilityClass::isBatterryForTravel(size_t batterry)
{
    return batterry > 6;
}

bool UtilityClass::isGoodForGaming(Computer comp)
{
    if (isProcForGaming(comp.getProccessor()) && isVideoForGaming(comp.getVideo()) && isHddForGaming(comp.getHDD()))
    {
        return true;
    }
    return false;
}

bool UtilityClass::isGoodForTravel(Computer comp)
{
    return isBatterryForTravel(comp.getBatteryLife()) && isWeightForTravel(comp.getWeight());
}
