#pragma once

#include <iostream>

#define TT template <typename T>

TT
class Queue
{
private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	size_t get = 0;
	size_t put = 0;

	explicit Queue(size_t newSize);

	void resize(size_t newCapacity);

	unsigned int getNextPowerOfTwo(unsigned int n) const;
	unsigned int allocateCapacity(unsigned int n) const;

	void copyFrom(const Queue& other);
	void moveFrom(Queue&& other) noexcept;
	void free();

public:
	Queue();

	Queue(const Queue& other);
	Queue& operator=(const Queue& other);

	Queue(Queue&& other) noexcept;
	Queue& operator=(Queue&& other) noexcept;

	size_t getSize() const;
	size_t getCapacity() const;

	Queue& push(const T& elem);
	Queue& push(T&& elem);

	Queue& pop();

	const T& front() const;

	bool empty() const;

	~Queue() noexcept;
};

TT
inline Queue<T>::Queue() : Queue(4)
{
}

TT
inline Queue<T>::Queue(size_t newSize) : size(0)
{
	this->capacity = allocateCapacity(newSize);
	this->data = new T[this->capacity];
}

TT
inline void Queue<T>::resize(size_t newCapacity)
{
	T* newData = new T[newCapacity];

	for (size_t i = 0; i < getSize(); i++)
	{
		newData[i] = this->data[get];
		(++get) %= getCapacity();
	}

	delete[] this->data;
	this->data = newData;

	this->capacity = newCapacity;
	this->get = 0;
	this->put = this->size;
}

TT
inline size_t Queue<T>::getSize() const
{
	return this->size;
}

TT
inline size_t Queue<T>::getCapacity() const
{
	return this->capacity;
}

TT
inline Queue<T>& Queue<T>::push(const T& elem)
{
	if (getSize() >= getCapacity())
	{
		resize(getCapacity() * 2);
	}

	this->data[put] = elem;
	(++put) %= getCapacity();
	this->size++;

	return *this;
}

TT
inline Queue<T>& Queue<T>::push(T&& elem)
{
	if (getSize() >= getCapacity())
	{
		resize(getCapacity() * 2);
	}

	this->data[put] = std::move(elem);
	(++put) %= getCapacity();
	this->size++;

	return *this;
}

TT
inline Queue<T>& Queue<T>::pop()
{
	if (empty())
	{
		throw std::runtime_error("Empty!");
	}

	(++get) %= getCapacity();
	this->size--;

	if (getSize() * 4 <= getCapacity() && getCapacity() > 1)
	{
		resize(getCapacity() / 2);
	}

	return *this;
}

TT
inline const T& Queue<T>::front() const
{
	return this->data[get];
}

TT
inline bool Queue<T>::empty() const
{
	return this->size == 0;
}

TT
inline Queue<T>::Queue(const Queue& other)
{
	copyFrom(other);
}

TT
inline Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

TT
inline Queue<T>::Queue(Queue&& other) noexcept
{
	moveFrom(std::move(other));
}

TT
inline Queue<T>& Queue<T>::operator=(Queue&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

TT
inline Queue<T>::~Queue() noexcept
{
	free();
}

TT
inline unsigned int Queue<T>::getNextPowerOfTwo(unsigned int n) const
{
	if (n == 0) return 1;

	while (n & (n - 1))
	{
		n &= (n - 1);
	}

	return n << 1;
}

TT
inline unsigned int Queue<T>::allocateCapacity(unsigned int n) const
{
	return std::max(getNextPowerOfTwo(n + 1), 8u);
}

TT
inline void Queue<T>::copyFrom(const Queue& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->get = other.get;
	this->put = other.put;

	this->data = new T[this->capacity];
	for (size_t i = 0; i < this->capacity; i++)
	{
		this->data[i] = other.data[i];
	}
}

TT
inline void Queue<T>::moveFrom(Queue&& other) noexcept
{
	this->data = other.data;

	this->size = other.size;
	this->capacity = other.capacity;

	this->get = other.get;
	this->put = other.put;

	other.data = nullptr;
	other.size = other.capacity = other.get = other.put = 0;
}

TT
inline void Queue<T>::free()
{
	delete[] this->data;

	this->data = nullptr;
	this->size = this->capacity = this->get = this->put = 0;
}
