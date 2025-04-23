#include "String.h"
#include "Array.h"
#include <iostream>

// TODO: Should be split to header + source file
class Student
{
	int age;
	String name;
	Array grades;

public:
	Student() : age(0), name(nullptr), grades(5) //2
	{
		//3
	}

	Student(const char* name) : Student() //1
	{
		//4
		setName(name);
	}

	const String& getName() const
	{
		return name;
	}

	int getAge() const
	{
		return age;
	}

	void setName(const String& name)
	{
		if (!isValidName(name))
		{
			return;
		}
		
		this->name = name;
	}

	void setAge(int age)
	{
		if (age < 0 || age > 150)
		{
			return;
		}

		this->age = age;
	}

	void addGrade(int grade)
	{
		if (grade < 2 || grade > 6)
		{
			return;
		}

		grades.push_back(grade);
	}

	double getAverageGrade() const
	{
		double gradesSum = 0;
		size_t gradesCount = grades.getCount();
		for (size_t i = 0; i < gradesCount; i++)
		{
			gradesSum += grades.at(i);
		}

		return gradesSum / gradesCount;
	}

	void whoAmI()
	{
		std::cout << "Name: " << name.c_str() << std::endl;
		// OR
		//std::cout << "Name: ";
		//name.print(std::cout);
		//std::cout << std::endl;

		std::cout << "Age: " << age << std::endl;
	}

private:
	bool isValidName(const String& name)
	{
		return name.getLength() < 60;
	}
};