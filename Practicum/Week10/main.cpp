#include <iostream>
#include "MyString.h"
#include "Student.h"
#include "StudentDB.h"

int main() {
    MyString str1("John Doe");
    MyString str2("Alice Smith");
    MyString str3("Bob Johnson");

    Student student1(str1, 12345, 2);
    Student student2(str2, 67890, 3);
    Student student3(str3, 11223, 1);

    StudentDB studentDB;
    studentDB.add(student1);
    studentDB.add(student2);
    studentDB.add(student3);

    std::cout << "Student database contents:" << std::endl;
    studentDB.display();

    unsigned searchId = 67890;
    try {
        Student* foundStudent = studentDB.find(searchId);
        std::cout << "Found student: " << foundStudent->getStudentName().getString() << ", Faculty Number: " << foundStudent->getFacultyNumber() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    unsigned removeId = 12345;
    try {
        studentDB.remove(removeId);
        std::cout << "Student with Faculty Number " << removeId << " has been removed." << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Updated student database:" << std::endl;
    studentDB.display();


    return 0;
}
