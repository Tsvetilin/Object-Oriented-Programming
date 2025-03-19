#include "Array.h"

Array::Array() : Array(10)
{
}

explicit Array::Array(size_t capacity) : capacity(capacity), count(0), arr(nullptr)
{
	this->arr = new ArrayType[capacity];
}

Array::Array(const Array& other)
{
	copyFrom(other);
}

Array& Array::operator=(const Array& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Array::~Array()
{
	free();
}

ArrayType& Array::at(size_t index)
{
	// TODO: Check for index over count
	return this->arr[index];
}

const ArrayType& Array::at(size_t index) const
{
	return this->arr[index];
}

void Array::push_back(ArrayType element)
{
	if (count == capacity)
	{
		resize();
	}

	arr[count++] = element;
}

void Array::free()
{
	delete[] arr;
}

void Array::copyFrom(const Array& other)
{
	this->capacity = other.capacity;
	this->count = other.count;
	this->arr = new ArrayType[other.capacity];
	for (size_t i = 0; i < other.count; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

void Array::resize()
{
	ArrayType* newArr = new ArrayType[this->capacity *= 2];
	for (size_t i = 0; i < count; i++)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;
	arr = newArr;
}

size_t Array::getCount()const
{
	return count;
}