#pragma once

#include <iostream>

struct Counter
{
	size_t useCount = 0;
	size_t weakCount = 0;

	void addSharedPtr()
	{
		useCount++;

		if (useCount == 1)
			weakCount++;
	}

	void removeSharedPtr()
	{
		useCount--;

		if (useCount == 0)
			weakCount--;
	}

	void addWeakPtr()
	{
		weakCount++;
	}

	void removeWeakPtr()
	{
		weakCount--;
	}
};

template <typename T>
class SharedPtr
{
private:
	template <typename T>
	friend class WeakPtr;

	T* ptr;
	Counter* counter;

	void copyFrom(const SharedPtr<T>& other);
	void moveFrom(SharedPtr<T>&& other) noexcept;
	void free();

public:
	SharedPtr();
	SharedPtr(T* ptr);

	SharedPtr(const SharedPtr<T>& other);
	SharedPtr& operator=(const SharedPtr<T>& other);

	SharedPtr(SharedPtr<T>&& other) noexcept;
	SharedPtr& operator=(SharedPtr<T>&& other) noexcept;

	const T* operator->() const;
	T* operator->();

	const T& operator*() const;
	T& operator*();

	bool isInitialized() const;
	operator bool() const;

	~SharedPtr() noexcept;
};

template <typename T>
SharedPtr<T>::SharedPtr() : ptr(nullptr), counter(nullptr)
{
}

template <typename T>
SharedPtr<T>::SharedPtr(T* ptr)
{
	this->ptr = ptr;

	if (this->ptr)
	{
		this->counter = new Counter();
		counter->addSharedPtr();
	}
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& other)
{
	copyFrom(other);
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
const T* SharedPtr<T>::operator->() const
{
	return this->ptr;
}

template <typename T>
T* SharedPtr<T>::operator->()
{
	return this->ptr;
}

template <typename T>
const T& SharedPtr<T>::operator*() const
{
	if (this->ptr == nullptr)
		throw std::runtime_error("nullptr!"); // !!! IMPORTANT !!!

	return *this->ptr;
}

template <typename T>
T& SharedPtr<T>::operator*()
{
	if (this->ptr == nullptr)
		throw std::runtime_error("nullptr!"); // !!! IMPORTANT !!!

	return *this->ptr;
}

template <typename T>
bool SharedPtr<T>::isInitialized() const
{
	return this->ptr != nullptr;
}

template <typename T>
SharedPtr<T>::operator bool() const
{
	return this->ptr != nullptr;
}

template <typename T>
SharedPtr<T>::~SharedPtr() noexcept
{
	free();
}

template <typename T>
void SharedPtr<T>::copyFrom(const SharedPtr<T>& other)
{
	this->ptr = other.ptr;
	this->counter = other.counter;

	if (this->counter)
		counter->addSharedPtr();
}

template <typename T>
void SharedPtr<T>::moveFrom(SharedPtr<T>&& other) noexcept
{
	this->ptr = other.ptr;
	this->counter = other.counter;

	other.ptr = nullptr;
	other.counter = nullptr;
}

template <typename T>
void SharedPtr<T>::free()
{
	if (!this->ptr && !this->counter)
		return;

	counter->removeSharedPtr();

	if (counter->useCount == 0)
	{
		delete this->ptr;
		this->ptr = nullptr;
	}

	if (counter->weakCount == 0)
	{
		delete this->counter;
		this->counter = nullptr;
	}
}
