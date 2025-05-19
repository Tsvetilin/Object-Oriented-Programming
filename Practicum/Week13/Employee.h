#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include<cstring>
#include<stdexcept>

class Employee {
public:
	Employee(const char* name, size_t age, double salary);
	Employee();
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	Employee(Employee&& other) noexcept;
	Employee& operator=(Employee&& other) noexcept;
	virtual ~Employee();

	void setEmployeeName(const char* name);
	void setEmployeeAge(size_t age);
	void setEmployeeSalary(double salary);

	const char* getEmployeeName() const;
	size_t getEmployeeAge() const;
	double getEmployeeSalary() const;

	virtual Employee* clone() const = 0;

private:
	char* name;
	size_t age;
	double salary;

	void copyFrom(const Employee& other);
	void moveFrom(Employee&& other) noexcept;
	void freeName();
	void freeEmployee();
};

#endif // !_EMPLOYEE_H