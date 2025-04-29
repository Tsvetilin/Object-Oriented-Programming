#include "StudentTicket.h"

StudentTicket::StudentTicket(const MyString& playName, double price): Ticket(playName,price) {
	
}

StudentTicket::StudentTicket() {
}

double StudentTicket::getNewTicketPrice() const {
	return this->getPlayPrice() / 2;
}

void StudentTicket::printStudentTicketInfo() const {
	std::cout << "Play: ";
	this->getPlayName().print();
	std::cout << "Student ticket price: " << getNewTicketPrice() << std::endl;
}
