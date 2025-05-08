#pragma once
#include "User.h"
#include "States.h"

class UserDatabase
{
	const size_t maxUsers = 100;
public:
	UserDatabase();
	void copyFrom(const UserDatabase& other);
	void free();
	UserDatabase(User* users,size_t size);
	UserDatabase(const UserDatabase& other);
	UserDatabase& operator=(const UserDatabase& other);
	~UserDatabase();

	State addUser(User user);
	bool hasEnoughMoney(size_t id,double money);
	State existUser(size_t id);
	State update(size_t id,double money);

private:
	User* users;
	size_t size;
};