#include <iostream>

template <typename T>
class UniquePtr
{
private:
	T* ptr = nullptr;

	void moveFrom(UniquePtr&& other) noexcept;
	void free();

public:
	UniquePtr(T* ptr);

	UniquePtr(const UniquePtr& other) = delete;
	UniquePtr& operator=(const UniquePtr& other) = delete;

	UniquePtr(UniquePtr&& other) noexcept;
	UniquePtr& operator=(UniquePtr&& other) noexcept;

	const T* operator->() const;
	T* operator->();

	const T& operator*() const;
	T& operator*();

	const T* get() const;
	T* get();

	~UniquePtr() noexcept;
};

template <typename T>
UniquePtr<T>::UniquePtr(T* ptr) : ptr(ptr) {}

template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
const T* UniquePtr<T>::operator->() const
{
	return this->ptr;
}

template <typename T>
T* UniquePtr<T>::operator->()
{
	return this->ptr;
}

template <typename T>
const T& UniquePtr<T>::operator*() const
{
	if (!this->ptr)
		throw std::runtime_error("nullptr!");

	return *this->ptr;
}

template <typename T>
T& UniquePtr<T>::operator*()
{
	if (!this->ptr)
		throw std::runtime_error("nullptr!");

	return *this->ptr;
}

template <typename T>
const T* UniquePtr<T>::get() const
{
	return this->ptr;
}

template <typename T>
T* UniquePtr<T>::get()
{
	return this->ptr;
}

template <typename T>
UniquePtr<T>::~UniquePtr() noexcept
{
	free();
}

template <typename T>
void UniquePtr<T>::moveFrom(UniquePtr<T>&& other) noexcept
{
	this->ptr = other.ptr;
	other.ptr = nullptr;
}

template <typename T>
void UniquePtr<T>::free()
{
	delete this->ptr;
	this->ptr = nullptr;
}