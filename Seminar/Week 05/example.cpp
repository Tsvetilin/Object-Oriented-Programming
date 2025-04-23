// TODO: Should include .h files instead of .cpp file
#include "Student.cpp"

int main()
{
    Student student;

    student.setName("Ivan");
    student.setAge(20);

    student.whoAmI();

    String nameCopy = student.getName(); // copy constructor invoked -> different object here
    const String& nameReadonlyReference = student.getName();  // no copy constructor invoked -> same object here
}