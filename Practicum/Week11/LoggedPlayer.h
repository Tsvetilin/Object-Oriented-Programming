#ifndef _LOGGEDPLAYER_H
#define _LOGGEDPLAYER_H

#include <iostream>
#include "Player.h"
#include <stdexcept>
#include<cstring>

const size_t MAX_PASSWORD_CHARACTERS = 8;

class LoggedPlayer : public Player {
public:
    LoggedPlayer(const char* password);

    bool login(int id, const char* password) const;
    const char* getPassword() const;

private:
    char password[MAX_PASSWORD_CHARACTERS + 1];
};

#endif // !_LOGGEDPLAYER_H