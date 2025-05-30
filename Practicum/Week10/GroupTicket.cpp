#include "GroupTicket.h"
#include <iostream>

GroupTicket::GroupTicket(MyString name, double price){
	this->name = name;
	this->price = 0.8 * price;
}

void GroupTicket::getTicketInfo() const
{
	std::cout << "Play name: " << name.getAsChar() << ",price: " << price;
}
