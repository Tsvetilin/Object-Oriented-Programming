#include "IdGenerator.h"

IdGenerator::IdGenerator(const String &seed) : seed(seed), lastGeneratedIndex(0) {}

String IdGenerator::generateId() const
{
    return String::of(seed.hash() + ++lastGeneratedIndex);
}