#ifndef _TRAINEE_H
#define _TRAINEE_H

#include "Employee.h"
#include "Worker.h"

class Trainee : virtual public Employee {
public:
	Trainee(const char* name, size_t age, double salary, size_t daysTillInternshipEnd);
	Trainee();
	Trainee(const Trainee& other);
	Trainee& operator=(const Trainee& other);
	Trainee(Trainee&& other) noexcept;
	Trainee& operator=(Trainee&& other) noexcept;
	~Trainee();

	void setDaysTillInternshipEnd(size_t daysTillInternshipEnd);
	size_t getDaysTillInternshipEnd() const;

	Employee* clone() const override;

private:
	size_t daysTillIntershipEnd;

	void copyFrom(const Trainee& other);
	void moveFrom(Trainee&& other) noexcept;
	void freeTrainee();
};

#endif // !_TRAINEE_H