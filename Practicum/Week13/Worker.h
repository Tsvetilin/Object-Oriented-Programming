#ifndef _WORKER_H
#define _WORKER_H

#include "Employee.h"

class Worker : virtual public Employee{
public:
	Worker(const char* name, size_t age, double salary, size_t monthsWorking);
	Worker();
	Worker(const Worker& other);
	Worker& operator=(const Worker& other);
	Worker(Worker&& other) noexcept;
	Worker& operator=(Worker&& other) noexcept;
	~Worker();

	void setMonthsWorking(size_t monthsWorking);
	size_t getMonthsWorking() const;

	Employee* clone() const override;

private:
	size_t monthsWorking;

	void copyFrom(const Worker& other);
	void moveFrom(Worker&& other) noexcept;
	void freeWorker();
};

#endif // !_WORKER_H