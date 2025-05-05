#include "Guest.h"

Guest::Guest(size_t playTimeMinutes): Player() {
	this->playTimeMinutes = playTimeMinutes;
}

unsigned Guest::getPlayTime() const {
	return this->playTimeMinutes;
}

void Guest::decreasePlayTime(size_t minutes) {
	if (minutes >= playTimeMinutes) {
		playTimeMinutes = 0;
	}
	else {
		playTimeMinutes -= minutes;
	}
}

bool Guest::levelUp() {
	return false;
}