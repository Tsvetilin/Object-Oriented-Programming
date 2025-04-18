#include "Vector.h"

Vector::Vector() : Vector(4)
{
}

Vector::Vector(size_t newSize) : size(0)
{
	this->capacity = allocateCapacity(newSize);
	this->data = new Type[this->capacity];
}

size_t Vector::getSize() const
{
	return this->size;
}

size_t Vector::getCapacity() const
{
	return this->capacity;
}

Vector& Vector::push_back(const Type& data) {
	if (getSize() >= getCapacity()) 
	{
		resize(getCapacity() * 2);
	}

	this->data[size++] = data;

	return *this;
}

Vector& Vector::pop_back() 
{
	if (getSize())
	{
		this->size--;
	}
	else
	{
		return *this;
	}

	if ((getSize() * 4) <= getCapacity() && getCapacity() > 1)
	{
		resize(getCapacity() / 2);
	}

	return *this;
}

Vector& Vector::insert(const Type& data, size_t position)
{
	if (position > size) 
	{
		return *this;
	}

	if (getSize() >= getCapacity())
	{
		resize(getCapacity() * 2);
	}

	for (int i = size; i > position; i--) {
		this->data[i] = this->data[i - 1];
	}

	this->data[position] = data;
	this->size++;

	return *this;
}

Vector& Vector::remove(size_t position)
{
	if (position > size)
	{
		return *this;
	}

	for (size_t i = position + 1; i < getSize(); i++)
	{
		this->data[i - 1] = this->data[i];
	}

	this->size--;

	if ((getSize() * 4) <= getCapacity() && getCapacity() > 1)
	{
		resize(getCapacity() / 2);
	}

	return *this;
}

Type& Vector::operator[](size_t idx)
{
	return this->data[idx];
}

const Type& Vector::operator[](size_t idx) const
{
	return this->data[idx];
}

Vector& Vector::operator+=(const Vector& other)
{
	this->size = getSize() + other.getSize();
	resize(getNextPowerOfTwo(this->size));

	for (size_t i = getSize(); i < this->size; i++)
	{
		this->data[i] = other.data[i];
	}

	return *this;
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
	Vector toReturn(lhs.getSize() + rhs.getSize());

	toReturn += lhs;
	toReturn += rhs;

	return toReturn;
}

bool operator==(const Vector& lhs, const Vector& rhs)
{
	if (lhs.size != rhs.size) return false;

	for (int i = 0; i < lhs.size; i++)
	{
		if (lhs.data[i] != rhs.data[i])
		{
			return false;
		}
	}

	return true;
}

bool operator!=(const Vector& lhs, const Vector& rhs)
{
	return !(lhs == rhs);
}

std::istream& operator>>(std::istream& is, Vector& other)
{
	other.free();

	size_t size;
	is >> size;

	other.size = size;
	other.capacity = other.getNextPowerOfTwo(size);

	other.data = new Type[other.getCapacity()];
	for (size_t i = 0; i < other.getSize(); i++) 
	{
		is >> other.data[i];
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Vector& other)
{
	for (size_t i = 0; i < other.getSize(); i++) 
	{
		os << other.data[i] << " ";
	}

	os << std::endl;
	return os;
}

Vector::Vector(const Vector& other)
{
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Vector& Vector::clear()
{
	this->size = 0;

	return *this;
}

Vector::~Vector()
{
	free();
}

unsigned int Vector::getNextPowerOfTwo(unsigned int n) const
{
	if (n == 0) return 1;

	while (n & (n - 1))
	{
		n &= (n - 1);
	}

	return n << 1;
}

unsigned int Vector::allocateCapacity(unsigned int n) const
{
	return std::max(getNextPowerOfTwo(n + 1), 8u);
}

void Vector::resize(size_t newCapacity)
{
	Type* newData = new Type[newCapacity];

	for (size_t i = 0; i < getSize(); i++)
	{
		newData[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newData;

	this->capacity = newCapacity;
}

void Vector::copyFrom(const Vector& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->data = new Type[this->capacity];

	for (int i = 0; i < getCapacity(); i++)
	{
		this->data[i] = other.data[i];
	}
}

void Vector::free()
{
	delete[] this->data;

	this->data = nullptr;
	size = 0;
	capacity = 0;
}
