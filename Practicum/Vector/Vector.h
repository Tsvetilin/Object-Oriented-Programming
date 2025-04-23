#pragma once
#include<iostream>

using Type = int;

class Vector
{
private:
	Type* data;
	size_t size;
	size_t capacity;

	void resize(size_t newCapacity);

	unsigned int getNextPowerOfTwo(unsigned int n) const;
	unsigned int allocateCapacity(unsigned int n) const;

	void free();
	void copyFrom(const Vector& other);

public:
	Vector();
	explicit Vector(size_t newSize);

	size_t getSize() const;
	size_t getCapacity() const;

	Vector& push_back(const Type& data);
	Vector& pop_back();

	Vector& insert(const Type& data, size_t position);
	Vector& remove(size_t position);

	Type& operator[](size_t n);
	const Type& operator[](size_t n) const;

	Vector& operator+=(const Vector& other);
	friend Vector operator+(const Vector& lhs, const Vector& rhs);

	friend bool operator==(const Vector& lhs, const Vector& rhs);
	friend bool operator!=(const Vector& lhs, const Vector& rhs);

	friend std::istream& operator>>(std::istream& is, Vector& vector);
	friend std::ostream& operator<<(std::ostream& os, const Vector& vector);

	Vector(const Vector& other);
	Vector& operator=(const Vector& other);

	Vector& clear();

	~Vector();
};
