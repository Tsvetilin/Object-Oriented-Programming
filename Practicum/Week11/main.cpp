#include <iostream>
#include "Player.h"
#include "Guest.h"
#include "LoggedPlayer.h"
#include "PremiumPlayer.h"

int main() {
    Player p1(100, Stars::TWO);
    std::cout << "Player ID: " << p1.getId() << ", Points: " << p1.getPoints() << ", Stars: " << (int)p1.getStars() << std::endl;
    p1.completeMission(200);
    std::cout << "After mission, Points: " << p1.getPoints() << std::endl;
    if (p1.levelUp()) {
        std::cout << "Player leveled up to stars: " << (int)p1.getStars() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    Guest guest(60);
    std::cout << "Guest play time: " << guest.getPlayTime() << " minutes" << std::endl;
    guest.decreasePlayTime(15);
    std::cout << "After playing, time left: " << guest.getPlayTime() << " minutes" << std::endl;

    guest.completeMission(300);
    std::cout << "Guest points: " << guest.getPoints() << std::endl;
    if (guest.levelUp()) {
        std::cout << "Guest leveled up to stars: " << (int)guest.getStars() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    LoggedPlayer lp("abc123");
    std::cout << "LoggedPlayer password: " << lp.getPassword() << std::endl;
    bool success = lp.login(lp.getId(), "abc123");
    std::cout << "Login " << (success ? "successful" : "failed") << std::endl;

    lp.completeMission(256);
    if (lp.levelUp()) {
        std::cout << "LoggedPlayer leveled up to stars: " << (int)lp.getStars() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    PremiumPlayer pp("pass789", "Alice");
    std::cout << "PremiumPlayer name: " << pp.getName() << std::endl;
    pp.sendMessage("Hello, world!");

    pp.completeMission(300);
    if (pp.levelUp()) {
        std::cout << "PremiumPlayer leveled up to stars: " << (int)pp.getStars() << std::endl;
    }

    return 0;
}