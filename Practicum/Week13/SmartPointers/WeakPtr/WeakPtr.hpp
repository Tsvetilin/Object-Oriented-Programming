#pragma once

#include "SharedPtr.hpp"

template <typename T>
class WeakPtr
{
private:
	T* ptr;
	Counter* counter;

	void copyFrom(const WeakPtr<T>& other);
	void moveFrom(WeakPtr<T>&& other) noexcept;
	void free();

public:
	WeakPtr();
	WeakPtr(const SharedPtr<T>& ptr);

	WeakPtr(const WeakPtr<T>& other);
	WeakPtr& operator=(const WeakPtr<T>& other);

	WeakPtr(WeakPtr<T>&& other) noexcept;
	WeakPtr& operator=(WeakPtr<T>&& other) noexcept;

	SharedPtr<T> lock() const;

	bool expired() const;

	~WeakPtr() noexcept;
};

template <typename T>
WeakPtr<T>::WeakPtr() : ptr(nullptr), counter(nullptr)
{
}

template <typename T>
WeakPtr<T>::WeakPtr(const SharedPtr<T>& other)
{
	this->ptr = other.ptr;
	this->counter = other.counter;

	if (this->counter)
		counter->addWeakPtr();
}

template <typename T>
WeakPtr<T>::WeakPtr(const WeakPtr<T>& other)
{
	copyFrom(other);
}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(const WeakPtr<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
WeakPtr<T>::WeakPtr(WeakPtr<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(WeakPtr<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
bool WeakPtr<T>::expired() const
{
	return !this->counter || counter->useCount == 0;
}

template <typename T>
SharedPtr<T> WeakPtr<T>::lock() const
{
	if (expired())
		return SharedPtr<T>();
	else
		return SharedPtr<T>(this->ptr);
}

template <typename T>
WeakPtr<T>::~WeakPtr() noexcept
{
	free();
}

template <typename T>
void WeakPtr<T>::copyFrom(const WeakPtr<T>& other)
{
	this->ptr = other.ptr;
	this->counter = other.counter;

	if (counter)
		counter->addWeakPtr();
}

template <typename T>
void WeakPtr<T>::moveFrom(WeakPtr<T>&& other) noexcept
{
	this->ptr = other.ptr;
	this->counter = other.counter;

	other.ptr = nullptr;
	other.counter = nullptr;
}

template <typename T>
void WeakPtr<T>::free()
{
	if (!this->ptr && !this->counter)
		return;

	counter->removeWeakPtr();

	// weak_count = weak_ptr + 1 / 0
	// 1 => use_count >= 1
	// 0 => use_count = 0

	if (counter->weakCount == 0 && counter->useCount == 0) // useCount = 0
	{
		delete counter;
		this->ptr = nullptr;
		this->counter = nullptr;
	}
}
