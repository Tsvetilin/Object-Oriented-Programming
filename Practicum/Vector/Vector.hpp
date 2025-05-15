#pragma once

#include <iostream>
#include <fstream>

//#define TT template <typename T>

template <typename T>
class Vector
{
private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void resize(size_t newCapacity);

	unsigned int getNextPowerOfTwo(unsigned int n) const;
	unsigned int allocateCapacity(unsigned int n) const;

	void copyFrom(const Vector& other);
	void moveFrom(Vector&& other) noexcept;
	void free();

public:
	Vector();
	explicit Vector(size_t newSize);

	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);

	Vector(Vector<T>&& other) noexcept;
	Vector<T>& operator=(Vector<T>&& other) noexcept;

	size_t getSize() const;
	size_t getCapacity() const;

	Vector& push_back(const T& element);
	Vector& push_back(T&& element);

	Vector& pop_back();

	Vector& insert(const T& element, size_t position);
	Vector& insert(T&& element, size_t position);

	Vector& remove(size_t position);

	bool isEmpty() const;

	Vector& clear();

	const T& operator[](size_t index) const;
	T& operator[](size_t index);

	Vector& operator+=(const Vector<T>& other);

	template <typename D>
	friend Vector<D> operator+(const Vector<D>& lhs, const Vector<D>& rhs);

	template <typename D>
	friend bool operator==(const Vector<D>& lhs, const Vector<D>& rhs);

	template <typename D>
	friend bool operator!=(const Vector<D>& lhs, const Vector<D>& rhs);

	template <typename D>
	friend std::istream& operator>>(std::istream& is, Vector<D>& vector);

	template <typename D>
	friend std::ostream& operator<<(std::ostream& os, const Vector<D>& vector);

	~Vector() noexcept;
};

template <typename T>
inline Vector<T>::Vector() : Vector(4) {}

template <typename T>
inline Vector<T>::Vector(size_t newSize) : size(0)
{
	this->capacity = allocateCapacity(newSize);
	this->data = new T[this->capacity]{ };
}

template <typename T>
inline Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}

template <typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
inline Vector<T>::Vector(Vector<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T>
inline Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
inline size_t Vector<T>::getSize() const
{
	return this->size;
}

template <typename T>
inline size_t Vector<T>::getCapacity() const
{
	return this->capacity;
}

template <typename T>
inline Vector<T>& Vector<T>::push_back(const T& element)
{
	if (getSize() >= getCapacity())
	{
		resize(getCapacity() * 2);
	}

	this->data[size++] = element;

	return *this;
}

template <typename T>
inline Vector<T>& Vector<T>::push_back(T&& element)
{
	if (getSize() >= getCapacity())
	{
		resize(getCapacity() * 2);
	}

	this->data[size++] = std::move(element);

	return *this;
}

template <typename T>
inline Vector<T>& Vector<T>::pop_back()
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

template <typename T>
inline Vector<T>& Vector<T>::insert(const T& element, size_t position)
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

	this->data[position] = element;
	this->size++;

	return *this;
}

template <typename T>
inline Vector<T>& Vector<T>::insert(T&& element, size_t position)
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

	this->data[position] = std::move(element);
	this->size++;

	return *this;
}

template <typename T>
inline Vector<T>& Vector<T>::remove(size_t position)
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

template <typename T>
inline bool Vector<T>::isEmpty() const
{
	return getSize() == 0;
}

template <typename T>
inline Vector<T>& Vector<T>::clear()
{
	this->size = 0;
	return *this;
}

template <typename T>
inline const T& Vector<T>::operator[](size_t index) const
{
	return this->data[index];
}

template <typename T>
inline T& Vector<T>::operator[](size_t index)
{
	return this->data[index];
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other)
{
	size_t newSize = getSize() + other.getSize();

	if (getCapacity() < newSize)
	{
		resize(getNextPowerOfTwo(newSize));
	}

	for (size_t i = 0; i < other.getSize(); i++)
	{
		this->data[getSize() + i] = other.data[i];
	}

	this->size = newSize;

	return *this;
}

template <typename D>
Vector<D> operator+(const Vector<D>& lhs, const Vector<D>& rhs)
{
	Vector<D> toReturn(lhs.getSize() + rhs.getSize());

	toReturn += lhs;
	toReturn += rhs;

	return toReturn;
}

template <typename D>
bool operator==(const Vector<D>& lhs, const Vector<D>& rhs)
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

template <typename D>
bool operator!=(const Vector<D>& lhs, const Vector<D>& rhs)
{
	return !(lhs == rhs);
}

template <typename D>
inline std::istream& operator>>(std::istream& is, Vector<D>& vector)
{
	is >> vector.size;
	vector.resize(vector.allocateCapacity(vector.getSize()));

	for (size_t i = 0; i < vector.getSize(); i++)
	{
		is >> vector.data[i];
	}

	return is;
}

template <typename D>
inline std::ostream& operator<<(std::ostream& os, const Vector<D>& vector)
{
	for (size_t i = 0; i < vector.getSize(); i++)
	{
		os << vector.data[i] << " ";
	}

	os << std::endl;
	return os;
}

template <typename T>
inline Vector<T>::~Vector() noexcept
{
	free();
}

template <typename T>
inline void Vector<T>::resize(size_t newCapacity)
{
	T* newData = new T[newCapacity];
	for (size_t i = 0; i < getSize(); i++)
	{
		newData[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newData;
	this->capacity = newCapacity;
}

template <typename T>
inline void Vector<T>::copyFrom(const Vector<T>& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->data = new T[this->capacity];
	for (size_t i = 0; i < this->capacity; i++)
	{
		this->data[i] = other.data[i];
	}
}

template <typename T>
inline void Vector<T>::moveFrom(Vector<T>&& other) noexcept
{
	this->data = other.data;
	this->size = other.size;
	this->capacity = other.capacity;

	other.data = nullptr;
	other.size = other.capacity = 0;
}

template <typename T>
inline void Vector<T>::free()
{
	delete[] this->data;

	this->data = nullptr;
	this->size = this->capacity = 0;
}

template <typename T>
inline unsigned int Vector<T>::getNextPowerOfTwo(unsigned int n) const
{
	if (n == 0) return 1;

	while (n & (n - 1))
	{
		n &= (n - 1);
	}

	return n << 1;
}

template <typename T>
inline unsigned int Vector<T>::allocateCapacity(unsigned int n) const
{
	return std::max(getNextPowerOfTwo(n + 1), 8u);
}
