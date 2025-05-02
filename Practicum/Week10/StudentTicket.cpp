#include "StudentTicket.h"
#include <iostream>

StudentTicket::StudentTicket(MyString name, double price) {
	this->name = name;
	this->price = price / 2;
}

void StudentTicket::getTicketInfo() const
{
	std::cout << "Play name: " << name.getAsChar() << ",price: " << price;
}
