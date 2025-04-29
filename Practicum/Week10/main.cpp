#include "MyString.h"
#include "Ticket.h"
#include "StudentTicket.h"
#include "GroupTicket.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        MyString play1("The Phantom of the Opera");
        MyString play2("Hamlet");
        MyString play3("Les Misérables");

        Ticket ticket1(play1, 50.00);
        Ticket ticket2(play2, 40.00);

        std::cout << "Ticket 1 Information:" << std::endl;
        ticket1.printTicketInfo();
        std::cout << "Ticket 2 Information:" << std::endl;
        ticket2.printTicketInfo();

        StudentTicket studentTicket1(play1, 50.00);
        StudentTicket studentTicket2(play3, 60.00);

        std::cout << std::endl;

        std::cout << "Student Ticket 1 Information:" << std::endl;
        studentTicket1.printStudentTicketInfo();
        std::cout << "Student Ticket 2 Information:" << std::endl;
        studentTicket2.printStudentTicketInfo();

        GroupTicket groupTicket1(play2, 40.00);
        GroupTicket groupTicket2(play3, 60.00);

        std::cout << std::endl;

        std::cout << "Group Ticket 1 Information:" << std::endl;
        groupTicket1.printGroupTicketInfo();
        std::cout << "Group Ticket 2 Information:" << std::endl;
        groupTicket2.printGroupTicketInfo();

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
