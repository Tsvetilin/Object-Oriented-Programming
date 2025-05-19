#pragma once

#include <iostream>

template <typename T>
class SharedPtr
{
private:
	T* ptr;
	size_t* refCount;

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

	~SharedPtr() noexcept;
};

template <typename T>
SharedPtr<T>::SharedPtr() : ptr(nullptr), refCount(nullptr)
{
}

template <typename T>
SharedPtr<T>::SharedPtr(T* ptr) : ptr(ptr)
{
	if (this->ptr)
		this->refCount = new size_t(1);
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
	if (!this->ptr)
		throw std::runtime_error("nullptr!");

	return *this->ptr;
}

template <typename T>
T& SharedPtr<T>::operator*()
{
	if (!this->ptr)
		throw std::runtime_error("nullptr!");

	return *this->ptr;
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
	this->refCount = other.refCount;

	if (this->refCount)
		(*refCount)++;
}

template <typename T>
void SharedPtr<T>::moveFrom(SharedPtr<T>&& other) noexcept
{
	this->ptr = other.ptr;
	this->refCount = other.refCount;

	other.ptr = nullptr;
	other.refCount = nullptr;
}

template <typename T>
void SharedPtr<T>::free()
{
	if (this->ptr = nullptr && this->refCount == nullptr)
		return;

	if (*refCount == 1)
	{
		delete this->ptr;
		delete this->refCount;
	}
	else
	{
		(*refCount)--;
	}
}
