#include "GroupTicket.h"

GroupTicket::GroupTicket(const MyString& playName, double price): Ticket(playName,price) {
}

GroupTicket::GroupTicket(): Ticket() {
}

double GroupTicket::getGroupTicketPrice() const {
	return this->getPlayPrice() * 0.8;
}

void GroupTicket::printGroupTicketInfo() {
	std::cout << "Play: ";
	this->getPlayName().print();
	std::cout << "Group ticket price: " << getGroupTicketPrice() << std::endl;
}
