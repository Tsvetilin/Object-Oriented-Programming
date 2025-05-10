#ifndef _ENGINE_H
#define _ENGINE_H

#include "CarPart.h"
#include<stdexcept>
#include<iostream>

class Engine : public CarPart {
public:
	Engine(int id, const char* manufacturer, const char* description, int horsePower);
	Engine();
	Engine(const Engine& other);
	Engine& operator=(const Engine& other);
	Engine(Engine&& other) noexcept;
	Engine& operator=(Engine&& other) noexcept;
	~Engine();

	void setHorsePower(int horsePower);

	int getHorsePower() const;

	friend std::ostream& operator<<(std::ostream& os, const Engine& engine);

private:
	int horsePower;

	void copyFrom(const Engine& other);
	void moveFrom(Engine&& other) noexcept;
	void freeEngine();
};

#endif // !_ENGINE_H
