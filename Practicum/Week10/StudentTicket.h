#ifndef _STUDENTTICKET_H
#define _STUDENTTICKET_H

#include "MyString.h"
#include "Ticket.h"

class StudentTicket : Ticket {
public:
	StudentTicket(const MyString& playName, double price);
	StudentTicket();

	double getNewTicketPrice() const;

	void printStudentTicketInfo() const;

private:
	
};

#endif // !_STUDENTTICKET_H
