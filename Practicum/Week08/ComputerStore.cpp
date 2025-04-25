#include "ComputerStore.h"
#include <iostream>
#pragma warning(disable:4996)

void ComputerStore::copyFrom(const ComputerStore& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	size = other.size;
	for (size_t i = 0; i < size; i++)
	{
		comps[i] = other.comps[i];
	}
}

void ComputerStore::free()
{
	delete[] name;
	delete[] comps;
	size = 0;
}

size_t ComputerStore::getIndex(const char* brand)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(comps[i].getBrand(), brand) == 0) {
			return i;
		}
	}
	return size;
}

ComputerStore::ComputerStore()
{
	name = new char[1];
	strcpy(name, "");
	size = 0;
	comps = nullptr;
}

ComputerStore::ComputerStore(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	size = 0;
	comps = nullptr;
}

ComputerStore::ComputerStore(const char* name, Computer* comps, size_t size)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->size = size;
	for (size_t i = 0; i < size; i++)
	{
		this->comps[i] = comps[i];
	}
}

ComputerStore::ComputerStore(const ComputerStore& other)
{
	copyFrom(other);
}

ComputerStore& ComputerStore::operator=(const ComputerStore& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

ComputerStore::~ComputerStore()
{
	free();
}

const char* ComputerStore::getName() const
{
	return name;
}

void ComputerStore::setName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void ComputerStore::addComputer(Computer comp)
{
	size_t index = getIndex(comp.getBrand());
	if (index < size)
	{
		comps[index].changeQuantity(1);
		return;
	}
	size++;
	Computer* res = new Computer[size];
	for (size_t i = 0; i < size-1; i++)
	{
		res[i] = comps[i];
	}
	res[size - 1] = comp;
	delete[] comps;
	comps = res;
}

void ComputerStore::printList() const
{
	std::cout << "\tStock:\n";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "Brand: " << comps[i].getBrand()
			<< ",Proccessor: " << comps[i].getProccessor()
			<< "\nVideo: " << comps[i].getVideo() << ",HDD: " << comps[i].getHDD()
			<< "\nBattery life: " << comps[i].getBatteryLife() << ",Price: " << comps[i].getPrice()
			<< ",Quantity: " << comps[i].getQuantity() <<std::endl;
	}
}

void ComputerStore::buyComp(const char* brand, double money)
{
	size_t index = getIndex(brand);
	if (money >= comps[index].getPrice() && comps[index].getQuantity())
	{
		comps[index].changeQuantity(-1);
		return;
	}
	throw std::invalid_argument("Not enough money");
}

void ComputerStore::printStock() const
{
	for (size_t i = 0; i < size; i++)
	{
		if (comps[i].getQuantity())
		{
			if (utils.isGoodForGaming(comps[i])) std::cout << "GOOD FOR GAMING:)";
			if (utils.isGoodForGaming(comps[i])) std::cout << "GOOD FOR TRAVEL:)";
			std::cout << "Brand: " << comps[i].getBrand()
				<< ",Proccessor: " << comps[i].getProccessor()
				<< "\nVideo: " << comps[i].getVideo() << ",HDD: " << comps[i].getHDD()
				<< "\nBattery life: " << comps[i].getBatteryLife() << ",Price: " << comps[i].getPrice()
				<< ",Quantity: " << comps[i].getQuantity() << std::endl;
		}
	}
}
