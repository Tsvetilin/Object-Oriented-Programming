#include "ComplexNumber.h"

ComplexNumber::ComplexNumber() : real(0), imaginary(0)
{
}

ComplexNumber::ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary)
{
}

double ComplexNumber::getReal() const
{
	return this->real;
}

double ComplexNumber::getImaginary() const
{
	return this->imaginary;
}

void ComplexNumber::setReal(double real)
{
	this->real = real;
}

void ComplexNumber::setImaginary(double imaginary)
{
	this->imaginary = imaginary;
}

ComplexNumber ComplexNumber::getConjugated() const
{
	return ComplexNumber(this->real, -this->imaginary);
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other)
{
	this->real += other.real;
	this->imaginary += other.imaginary;

	return *this;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other)
{
	this->real -= other.real;
	this->imaginary -= other.imaginary;

	return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other)
{
	double oldReal = this->real;

	this->real = this->real * other.real - this->imaginary * other.imaginary;
	this->imaginary = oldReal * other.imaginary + this->imaginary * oldReal;

	return *this;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& other)
{
	ComplexNumber conjugated = other.getConjugated();

	ComplexNumber otherCopy(other);

	*this *= conjugated;
	otherCopy *= conjugated;

	if (otherCopy.real != 0)
	{
		this->real /= otherCopy.real;
		this->imaginary /= otherCopy.real;
	}

	return *this;
}

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	ComplexNumber toReturn(lhs);
	toReturn += rhs;
	return toReturn;
}

ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	ComplexNumber toReturn(lhs);
	toReturn -= rhs;
	return toReturn;
}

ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	ComplexNumber toReturn(lhs);
	toReturn *= rhs;
	return toReturn;
}

ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	ComplexNumber toReturn(lhs);
	toReturn /= rhs;
	return toReturn;
}

bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return std::abs(lhs.real - rhs.real) <= Constants::EPS &&
		std::abs(lhs.imaginary - rhs.imaginary) <= Constants::EPS;
}

bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return !(lhs == rhs);
}

std::istream& operator>>(std::istream& is, ComplexNumber& other)
{
	return is >> other.real >> other.imaginary;
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& other)
{
	return os << other.real << " " << other.imaginary << std::endl;
}
