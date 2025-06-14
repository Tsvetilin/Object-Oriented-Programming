#ifndef _PAIDTRAINEE_H
#define _PAIDTRAINEE_H

#include "Employee.h"
#include "Worker.h"
#include "Trainee.h"
#include<stdexcept>

const double MIN_RATING = 0;
const double MAX_RATING = 100;

class PaidTrainee : public Worker, public Trainee {
public:
	PaidTrainee(const char* name, size_t age, double salary, size_t monthsWorking,size_t daysTillInternshipEnd, double rating);
	PaidTrainee();
	PaidTrainee(const PaidTrainee& other);
	PaidTrainee& operator=(const PaidTrainee& other);
	PaidTrainee(PaidTrainee&& other) noexcept;
	PaidTrainee& operator=(PaidTrainee&& other) noexcept;
	~PaidTrainee();

	void setRating(double rating);
	double getRating() const;

	Employee* clone() const override;

private:
	double rating;

	void copyFrom(const PaidTrainee& other);
	void moveFrom(PaidTrainee&& other) noexcept;
	void freePaidTrainee();
};

#endif // !_PAIDTRAINEE_H