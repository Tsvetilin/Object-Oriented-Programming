#pragma once
#include "Ticket.h"

class StudentTicket : public Ticket
{
public:
	StudentTicket(MyString name, double price);
	void getTicketInfo() const;
};

