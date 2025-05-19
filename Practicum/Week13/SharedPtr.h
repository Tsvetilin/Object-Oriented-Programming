#ifndef _SHAREDPTR_H
#define _SHAREDPTR_H

#include <iostream>
#include <stdexcept>

template <typename T>
struct ControlBlock {
	T* ptr = nullptr;
	size_t strongCount = 0;

	ControlBlock(T* p) : ptr(p), strongCount(1) {}
	~ControlBlock() {
		delete ptr;
	}
};

template <typename T, size_t N>
class SharedPtr {
private:
	ControlBlock<T>* control = nullptr;

	void copyFrom(const SharedPtr& other) {
		if (other.control) {
			if (other.control->strongCount >= N) {
				throw std::runtime_error("Maximum number of shared references exceeded!");
			}
			control = other.control;
			++control->strongCount;
		}
	}

	void moveFrom(SharedPtr&& other) noexcept {
		control = other.control;
		other.control = nullptr;
	}

	void free() {
		if (control) {
			if (--control->strongCount == 0) {
				delete control;
			}
			control = nullptr;
		}
	}

public:
	SharedPtr() = default;

	explicit SharedPtr(T* ptr) {
		if (ptr)
			control = new ControlBlock<T>(ptr);
	}

	SharedPtr(const SharedPtr& other) {
		copyFrom(other);
	}

	SharedPtr& operator=(const SharedPtr& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}

	SharedPtr(SharedPtr&& other) noexcept {
		moveFrom(std::move(other));
	}

	SharedPtr& operator=(SharedPtr&& other) noexcept {
		if (this != &other) {
			free();
			moveFrom(std::move(other));
		}
		return *this;
	}

	~SharedPtr() {
		free();
	}

	T* operator->() const {
		return control ? control->ptr : nullptr;
	}

	T& operator*() const {
		if (!control || !control->ptr)
			throw std::runtime_error("Dereferencing null pointer!");
		return *control->ptr;
	}

	size_t use_count() const {
		return control ? control->strongCount : 0;
	}

	bool unique() const {
		return use_count() == 1;
	}

	T* get() const {
		return control ? control->ptr : nullptr;
	}
};

#endif // !_SHAREDPTR_H