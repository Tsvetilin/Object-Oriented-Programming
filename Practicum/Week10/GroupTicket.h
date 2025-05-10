#ifndef _GROUPTICKET_H
#define _GROUPTICKET_H

#include "MyString.h"
#include "Ticket.h"
#include<iostream>

class GroupTicket : Ticket {
public:
	GroupTicket(const MyString& playName, double price);
	GroupTicket();

	double getGroupTicketPrice() const;

	void printGroupTicketInfo();
private:
};

#endif // !_GROUPTICKET_H
