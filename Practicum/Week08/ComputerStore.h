#pragma once
#include "Computer.h"
#include "UtilityClass.h"

class ComputerStore
{
private:
	char* name;
	Computer* comps;
	size_t size;
	static UtilityClass utils;

	void copyFrom(const ComputerStore& other);
	void free();

	size_t getIndex(const char* brand);
public:
	ComputerStore();
	ComputerStore(const char* name);
	ComputerStore(const char* name, Computer* comps, size_t size);
	ComputerStore(const ComputerStore& other);
	ComputerStore& operator=(const ComputerStore& other);
	~ComputerStore();

	const char* getName() const;
	void setName(const char* name);

	void addComputer(Computer comp);
	void printList() const;
	void buyComp(const char* brand, double money);
	void printStock() const;
};

