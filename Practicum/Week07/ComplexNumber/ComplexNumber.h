#pragma once

#include <iostream>

namespace Constants
{
	constexpr double EPS = 1e-10;
}

class ComplexNumber
{
private:
	double real;
	double imaginary;

public:
	ComplexNumber();
	ComplexNumber(double real, double imaginary);

	double getReal() const;
	double getImaginary() const;

	void setReal(double real);
	void setImaginary(double imaginary);

	ComplexNumber getConjugated() const;

	ComplexNumber& operator+=(const ComplexNumber& other);
	friend ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);

	ComplexNumber& operator-=(const ComplexNumber& other);
	friend ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs);

	ComplexNumber& operator*=(const ComplexNumber& other);
	friend ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs);

	ComplexNumber& operator/=(const ComplexNumber& other);
	friend ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs);

	friend bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs);
	friend bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs);

	friend std::istream& operator>>(std::istream& is, ComplexNumber& other);
	friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& other);
};
