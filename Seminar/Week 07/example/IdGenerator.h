#pragma once
#include "String.h"

class IdGenerator
{
    const String seed;
    mutable size_t lastGeneratedIndex; // In order to use it in const generateId() function

public:
    IdGenerator(const String& seed);
    String generateId() const;
};