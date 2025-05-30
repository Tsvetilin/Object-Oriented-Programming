#include "PremiumPlayer.h"
#include <iostream>
#pragma warning(disable:4996)

size_t PremiumPlayer::getPointsForNextStar() const
{
    return 256;
}

void PremiumPlayer::free()
{
    delete[] name;
    name = nullptr;
}

void PremiumPlayer::copyFrom(const PremiumPlayer& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

void PremiumPlayer::moveFrom(PremiumPlayer&& other)
{
    name = other.name;
    other.name = nullptr;
}

PremiumPlayer::PremiumPlayer()
{
    name = new char[1];
    strcpy(name, "");
}

PremiumPlayer::PremiumPlayer(const char* name)
{
    if (!name) PremiumPlayer();
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

PremiumPlayer::PremiumPlayer(const PremiumPlayer& other)
{
    copyFrom(other);
}

PremiumPlayer& PremiumPlayer::operator=(const PremiumPlayer& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

PremiumPlayer::PremiumPlayer(PremiumPlayer&& other)
{
    moveFrom(std::move(other));
}

PremiumPlayer& PremiumPlayer::operator=(PremiumPlayer&& other)
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

PremiumPlayer::~PremiumPlayer()
{
    free();
}

