#pragma once

#include <iostream>

namespace Constants
{
	constexpr double EPS = 1e-10;
}

class MathVector
{
private:
	int* data;
	size_t size;

	void copyFrom(const MathVector& other);
	void free();

public:
	MathVector(size_t size);

	MathVector& operator+=(const MathVector& other);
	friend MathVector operator+(const MathVector& lhs, const MathVector& rhs);

	MathVector& operator-=(const MathVector& other);
	friend MathVector operator-(const MathVector& lhs, const MathVector& rhs);

	MathVector& operator*=(int scalar);

	friend MathVector operator*(const MathVector& other, int scalar);
	friend MathVector operator*(int scalar, const MathVector& other);

	const int& operator[](size_t idx) const;
	int& operator[](size_t idx);

	size_t operator~() const;

	friend bool operator||(const MathVector& lhs, const MathVector& rhs);
	friend bool operator|=(const MathVector& lhs, const MathVector& rhs);

	friend int operator%(const MathVector& lhs, const MathVector& rhs);

	friend std::istream& operator>>(std::istream& is, MathVector& other);
	friend std::ostream& operator<<(std::ostream& os, const MathVector& other);

	MathVector(const MathVector& other);
	MathVector& operator=(const MathVector& other);

	~MathVector();
};
