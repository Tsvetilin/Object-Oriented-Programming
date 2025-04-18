#include "MathVector.h"

MathVector::MathVector(size_t size) : size(size)
{
	this->data = new int[size] { 0 };
}

MathVector& MathVector::operator+=(const MathVector& other)
{
	if (this->size != other.size)
	{
		throw std::runtime_error("Different sizes!");
	}

	for (size_t i = 0; i < this->size; i++)
	{
		this->data[i] += other.data[i];
	}

	return *this;
}

MathVector& MathVector::operator-=(const MathVector& other)
{
	if (this->size != other.size)
	{
		throw std::runtime_error("Different sizes!");
	}

	for (size_t i = 0; i < this->size; i++)
	{
		this->data[i] -= other.data[i];
	}

	return *this;
}

MathVector& MathVector::operator*=(int scalar)
{
	for (size_t i = 0; i < this->size; i++)
	{
		this->data[i] *= scalar;
	}

	return *this;
}

const int& MathVector::operator[](size_t idx) const
{
	return this->data[idx];
}

int& MathVector::operator[](size_t idx)
{
	return this->data[idx];
}

size_t MathVector::operator~() const
{
	return this->size;
}

MathVector operator+(const MathVector& lhs, const MathVector& rhs)
{
	MathVector toReturn(lhs);
	toReturn += rhs;
	return toReturn;
}

MathVector operator-(const MathVector& lhs, const MathVector& rhs)
{
	MathVector toReturn(lhs);
	toReturn -= rhs;
	return toReturn;
}

MathVector operator*(const MathVector& other, int scalar)
{
	MathVector toReturn(other);
	toReturn *= scalar;
	return toReturn;
}

MathVector operator*(int scalar, const MathVector& other)
{
	return other * scalar;
}

bool operator||(const MathVector& lhs, const MathVector& rhs)
{
	if (~lhs != ~rhs)
	{
		throw std::runtime_error("Different sizes!");
	}

	double ratio = 0.0;
	bool ratioSet = false;

	for (size_t i = 0; i < ~lhs; i++)
	{
		if (lhs[i] == 0 && rhs[i] == 0)
		{
			continue;
		}

		if (lhs[i] == 0 || rhs[i] == 0)
		{
			return false;
		}

		double currentRatio = (double)lhs[i] / rhs[i];

		if (!ratioSet)
		{
			ratio = currentRatio;
			ratioSet = true;
		}
		else if (std::abs(ratio - currentRatio) > Constants::EPS)
		{
			return false;
		}
	}

	return true;
}

bool operator|=(const MathVector& lhs, const MathVector& rhs)
{
	return lhs % rhs == 0;
}

int operator%(const MathVector& lhs, const MathVector& rhs)
{
	if (~lhs != ~rhs)
	{
		throw std::runtime_error("Different sizes!");
	}

	int res = 0;

	for (int i = 0; i < ~lhs; i++)
	{
		res += lhs[i] * rhs[i];
	}

	return res;
}

std::istream& operator>>(std::istream& is, MathVector& other)
{
	size_t size = 0;
	is >> size;

	other.data = new int[size] { 0 };

	for (size_t i = 0; i < size; i++)
	{
		is >> other.data[i];
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const MathVector& other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		os << other.data[i] << " ";
	}

	return os;
}

void MathVector::copyFrom(const MathVector& other)
{
	this->size = other.size;
	this->data = new int[this->size] { 0 };

	for (size_t i = 0; i < this->size; i++)
	{
		this->data[i] = other.data[i];
	}
}

void MathVector::free()
{
	delete[] this->data;

	this->data = nullptr;
	this->size = 0;
}

MathVector::MathVector(const MathVector& other)
{
	copyFrom(other);
}

MathVector& MathVector::operator=(const MathVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MathVector::~MathVector()
{
	free();
}
