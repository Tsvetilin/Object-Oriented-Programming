#pragma once
#include "CarPart.h"

class Engine : public CarPart
{
protected:
	size_t hp;
public:
	Engine(size_t id, const char* manifacturer, const char* description, size_t hp);
	friend std::ostream& operator<<(std::ostream& os, const Engine& other);
};

