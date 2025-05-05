#include "LoggedPlayer.h"
#pragma warning(disable : 4996)

LoggedPlayer::LoggedPlayer(const char* password) : Player() {
	if (strlen(password) > MAX_PASSWORD_CHARACTERS) {
		throw std::invalid_argument("Password is too long");
	}

	strcpy(this->password, password);
}

bool LoggedPlayer::login(int id, const char* password) const {
	return (this->getId() == id && std::strcmp(this->password, password) == 0);
}

const char* LoggedPlayer::getPassword() const {
	return this->password;
}