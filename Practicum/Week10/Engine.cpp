#include "Engine.h"
#include <iostream>
#pragma warning(disable:4996)

Engine::Engine(size_t id, const char* manifacturer, const char* description, size_t hp) :
		CarPart(id,manifacturer,description)
{
	this->hp = hp;
}

std::ostream& operator<<(std::ostream& os, const Engine& other)
{
	os << CarPart(other) << other.hp << " hp" << std::endl;
	return os;
}
