#include <iostream>
#include "User.h"
#pragma warning (disable:4996)

User::User()
{
	id = 0;
	name = new char[1];
	strcpy(name, "");
	balance = 0;
}

void User::copyFrom(const User& other)
{
	id = other.id;
	balance = other.balance;
	delete[] name;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

void User::free()
{
	delete[] name;
	name = nullptr;
	balance = 0;
	id = 0;
}

User::User(size_t id, const char* name, double balance)
{
	if (name == nullptr || id == 0)
	{
		std::cout << "Invalid input(name or id)";
		this->balance = 0;
		this->name = nullptr;
		this->id = 0;
		return;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->id = id;
	this->balance = balance;
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

User::User(const User& other)
{
	copyFrom(other);
}

User::~User()
{
	free();
}

size_t User::getId() const{ return id; }
State User::updateMoney(double factor)
{
	if (balance + factor < 0) return State::NegativeBalance;
	balance += factor;
	return State::OK;
}
bool User::hasMoney(double arg){ return balance - arg >= 0; }


