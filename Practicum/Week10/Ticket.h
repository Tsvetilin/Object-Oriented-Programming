#pragma once
#include "MyString.h"


class Ticket
{
protected:
	MyString name;
	double price;
public:
	Ticket();
	Ticket(MyString name, double price);
	void getTicketInfo() const;
};

