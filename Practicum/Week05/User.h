#pragma once
#include "States.h"

class User
{
public:
	User();
	void copyFrom(const User& other);
	void free();
	User(size_t id, const char* name, double balance);
	User& operator=(const User& other);
	User(const User& other);
	~User();

	size_t getId() const;
	State updateMoney(double factor);
	bool hasMoney(double arg);


private:
	size_t id;
	char* name;
	double balance;
};