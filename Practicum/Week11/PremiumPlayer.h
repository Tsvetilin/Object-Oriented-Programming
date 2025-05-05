#ifndef _PREMIUMPLAYER_H
#define _PREMIUMPLAYER_H

#include <iostream>
#include "Player.h"
#include "LoggedPlayer.h"
#include <stdexcept>
#include<cstring>

class PremiumPlayer : public LoggedPlayer {
public:
    PremiumPlayer(const char* password, const char* name);
    PremiumPlayer(const PremiumPlayer& other);
    PremiumPlayer& operator=(const PremiumPlayer& other);
	PremiumPlayer(PremiumPlayer&& other) noexcept;
	PremiumPlayer& operator=(PremiumPlayer&& other) noexcept;
    ~PremiumPlayer();

    const char* getName() const;
    void sendMessage(const char* message) const;
    bool levelUp() override;

private:
    char* name;

    void copyFrom(const PremiumPlayer& other);
    void moveFrom(PremiumPlayer&& other) noexcept;
	void freeName();
};
#endif // !_PREMIUMPLAYER_H