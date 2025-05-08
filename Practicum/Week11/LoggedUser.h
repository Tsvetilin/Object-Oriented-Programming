#pragma once
#include "Player.h"

static const size_t PASS_LEN = 8;
static const size_t BUFF_LEN = 1024;

class LoggedUser : public Player
{
private:
	char pass[PASS_LEN+1];
	bool isLoged;
public:
	LoggedUser(const char* pass);
	void login();
	void logout();
	void setNewPass(const char* pass);
};

