#include "Ticket.h"
#include <iostream>

Ticket::Ticket() : name(""), price(0) { }

Ticket::Ticket(MyString name, double price) : name(name),price(price) {}

void Ticket::getTicketInfo() const
{
	std::cout << "Play name: " << name.getAsChar() << ",price: " << price;
}
