#include "Student.h"

const char* Student::getName() const
{
    return name.getAsChar();
}

unsigned Student::getFN() const
{
    return fn;
}

unsigned Student::getYear() const
{
    return year;
}

void Student::setName(MyString name)
{
    this->name = name;
}

void Student::setFN(unsigned fn)
{
    this->fn = fn;
}

void Student::setYear(unsigned year)
{
    this->year = year;
}
