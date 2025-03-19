#pragma once

// The implementation is agnostic to the type of the elements in the array
// The type is defined as ArrayType to make the implementation more generic
// Later implementation will use class templates
typedef int ArrayType;

class Array
{
	ArrayType* arr;
	size_t count;
	size_t capacity;

public:
	Array();
	explicit Array(size_t capacity);
	Array(const Array&);
	Array& operator=(const Array&);
	~Array();

	ArrayType& at(size_t index);
	const ArrayType& at(size_t index) const;
	void push_back(ArrayType element);
	size_t getCount()const;

private:
	void free();
	void copyFrom(const Array&);

	void resize();
};