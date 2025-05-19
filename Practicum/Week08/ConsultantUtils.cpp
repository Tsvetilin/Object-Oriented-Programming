#include "ConsultantUtils.h"
#pragma warning(disable: 4996)

bool ConsultantUtils::isGoodForGaming(const Computer& comp) {
	if (strcmp(comp.getProcessor(), "i5") == 0 || strcmp(comp.getProcessor(), "i7") == 0) {
		if (comp.getVideo() == 3060 || comp.getVideo() == 3070 || comp.getVideo() == 3080 || comp.getVideo() == 3090) {
			if (comp.getHardDrive() >= 512) {
				return true;
			}
		}
	}

	return false;
}

bool ConsultantUtils::isGoodForTravel(const Computer& comp) {
	if (comp.getWeight() <= 2.5) {
		if (comp.getBatteryLife() > 6) {
			return true;
		}
	}

	return false;
}
