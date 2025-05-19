#ifndef _COMPANY_H
#define _COMPANY_H

#include "Employee.h"
#include "Worker.h"
#include "Trainee.h"
#include "PaidTrainee.h"
#include<stdexcept>

const double EPS = 0.00001;

class Company {
public:
	Company(const Employee& employees, size_t capacity, size_t size);
	Company();
	Company(const Company& other);
	Company& operator=(const Company& other);
	Company(Company&& other) noexcept;
	Company& operator=(Company&& other) noexcept;
	~Company();

	void setCompany(const Employee& employees, size_t capacity, size_t size);
	const Employee& getCompanyEmployees(size_t index) const;
	size_t getCompanyCapacity() const;
	size_t getCompanySize() const;

	void addWorker(const Worker& w);
	void addTrainee(const Trainee& t);
	void addPaidTrainee(const PaidTrainee& pt);

	double getAverageSalary() const;
	bool twoSum(double val) const;


private:
	Employee** employees;
	size_t capacity;
	size_t size;

	void insertSorted(Employee* e);
	void resizeCompany(size_t newCapacity);
	void copyFrom(const Company& other);
	void moveFrom(Company&& other) noexcept;
	void freeCompany();
};

#endif // !_COMPANY_H