#pragma once

#include <iostream>
#include <utility>

// LIFO
// Last-In First-Out

template <typename T>
class Stack
{
private:
	T* data;
	size_t size;
	size_t capacity;

	void resize(size_t newCapacity);

	unsigned int getNextPowerOfTwo(unsigned int n) const;
	unsigned int allocateCapacity(unsigned int n) const;

	void copyFrom(const Stack& other);
	void moveFrom(Stack&& other) noexcept;
	void free() noexcept;

public:
	Stack();
	explicit Stack(size_t N);

	Stack(const Stack& other);
	Stack& operator=(const Stack& other);

	Stack(Stack&& other) noexcept;
	Stack& operator=(Stack&& other) noexcept;

	size_t getSize() const;
	size_t getCapacity() const;

	Stack& push(const T& elem);
	Stack& push(T&& elem);

	Stack& pop();

	const T& top() const;

	~Stack() noexcept;
};

template<typename T>
inline Stack<T>::Stack() : Stack(4)
{
}

template<typename T>
inline Stack<T>::Stack(size_t N) : size(0)
{
	this->capacity = allocateCapacity(N);
	this->data = new T[this->capacity]{ };
}

template<typename T>
inline Stack<T>::Stack(const Stack& other)
{
	copyFrom(other);
}

template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
inline Stack<T>::Stack(Stack&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline Stack<T>& Stack<T>::operator=(Stack&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
inline size_t Stack<T>::getSize() const
{
	return this->size;
}

template<typename T>
inline size_t Stack<T>::getCapacity() const
{
	return this->capacity;
}

template<typename T>
inline Stack<T>& Stack<T>::push(const T& elem)
{
	if (getSize() >= getCapacity())
	{
		resize(getCapacity() * 2);
	}

	this->data[this->size++] = elem;

	return *this;
}

template<typename T>
inline Stack<T>& Stack<T>::push(T&& elem)
{
	if (getSize() >= getCapacity())
	{
		resize(getCapacity() * 2);
	}

	this->data[this->size++] = std::move(elem);

	return *this;
}

template<typename T>
inline Stack<T>& Stack<T>::pop()
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

template<typename T>
inline const T& Stack<T>::top() const
{
	return this->data[this->size - 1];
}

template<typename T>
inline Stack<T>::~Stack() noexcept
{
	free();
}

template<typename T>
inline void Stack<T>::resize(size_t newCapacity)
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

template<typename T>
inline unsigned int Stack<T>::getNextPowerOfTwo(unsigned int n) const
{
	if (n == 0) return 1;

	while (n & (n - 1))
	{
		n &= (n - 1);
	}

	return n << 1;
}

template<typename T>
inline unsigned int Stack<T>::allocateCapacity(unsigned int n) const
{
	return std::max(getNextPowerOfTwo(n + 1), 8u);
}

template<typename T>
inline void Stack<T>::copyFrom(const Stack& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->data = new T[this->capacity];
	for (size_t i = 0; i < this->capacity; i++)
	{
		this->data[i] = other.data[i];
	}
}

template<typename T>
inline void Stack<T>::moveFrom(Stack&& other) noexcept
{
	this->data = other.data;
	this->size = other.size;
	this->capacity = other.capacity;

	other.data = nullptr;
	other.size = other.capacity = 0;
}

template<typename T>
inline void Stack<T>::free()
{
	delete[] this->data;

	this->data = nullptr;
	this->size = this->capacity = 0;

}
