#pragma once
#include "Ticket.h"

class GroupTicket : public Ticket
{
public:
	GroupTicket(MyString name, double price);
	void getTicketInfo() const;
};

