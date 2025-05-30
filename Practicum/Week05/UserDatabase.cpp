#include <iostream>
#include "UserDatabase.h"

UserDatabase::UserDatabase()
{
	users = new User[0];
	size = 0;
}
void UserDatabase::copyFrom(const UserDatabase& other)
{
	users = new User[other.size];
	size = other.size;
	for (size_t i = 0; i < size; i++)
	{
		users[i] = other.users[i];
	}
}
void UserDatabase::free()
{
	delete[] users;
	users = nullptr;
	size = 0;
}
UserDatabase::UserDatabase(User* users, size_t size)
{
	this->users = new User[size];
	this->size = size;
	for (size_t i = 0; i < size; i++)
	{
		this->users[i] = users[i];
	}
}
UserDatabase::UserDatabase(const UserDatabase& other)
{
	copyFrom(other);
}
UserDatabase& UserDatabase::operator=(const UserDatabase& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
UserDatabase::~UserDatabase()
{
	free();
}

State UserDatabase::addUser(User user)
{
	if (size + 1 >= maxUsers) return State::UserFull;
	size++;
	User* res = new User[size];
	for (size_t i = 0; i < size-1; i++)
	{
		res[i] = users[i];
	}
	delete[] users;
	res[size - 1] = user;
	users = res;
	return State::OK;
}

bool UserDatabase::hasEnoughMoney(size_t id, double money)
{
	for (size_t i = 0; i < size; i++)
	{
		if (users[i].getId() == id) 
		{
			return users[i].hasMoney(money);
		}
	}
	std::cout << "Such users doesnt exist in the database!";
	return false;
}

State UserDatabase::existUser(size_t id)
{
	for (size_t i = 0; i < size; i++)
	{
		if (users[i].getId() == id) return State::OK;
	}
	return State::UserNotFound;
}

State UserDatabase::update(size_t id,double money)
{
	for (size_t i = 0; i < size; i++)
	{
		if (users->getId() == id)
		{
			users[i].updateMoney(money);
			return State::OK;
		}
	}
	return State::UserNotFound;
}




