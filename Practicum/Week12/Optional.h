#ifndef _OPTIONAL_H
#define _OPTIONAL_H

#include<stdexcept>

template<typename T>
class Optional {
public:
	Optional();         
	Optional(const T& obj);
	Optional(const Optional<T>& other);
	Optional& operator=(const Optional<T>& other);

	T& operator*();
	const T& operator*() const;

	bool hasValue() const;
	T& getValue();
	const T& getValue() const;

	void setValue(const T& value);
	void reset();

private:
	T value;
	bool has_value;
};

#endif // !_OPTIONAL_H


template<typename T>
inline Optional<T>::Optional() {
	this->has_value = false;
}

template<typename T>
inline Optional<T>::Optional(const T& obj) {
	this->has_value = true;
	this->value = obj;
}


template<typename T>
inline Optional<T>::Optional(const Optional<T>& other) {
	this->has_value = other.has_value;
	if (other.has_value) {
		this->value = other.value;
	}
}


template<typename T>
inline Optional<T>& Optional<T>::operator=(const Optional<T>& other) {
	if (this != &other) {
		if (other.has_value) {
			this->value = other.value;
		}
		this->has_value = other.has_value;
	}
	return *this;
}

template<typename T>
inline bool Optional<T>::hasValue() const {
	return has_value;
}

template<typename T>
inline T& Optional<T>::getValue() {
	if (!has_value) {
		throw std::runtime_error("No value in Optional!");
	}
	return value;
}

template<typename T>
inline const T& Optional<T>::getValue() const {
	if (!has_value) {
		throw std::runtime_error("No value in Optional!");
	}
	return value;
}

template<typename T>
inline T& Optional<T>::operator*() {
	return getValue();
}

template<typename T>
const T& Optional<T>::operator*() const {
	return getValue();
}

template<typename T>
inline void Optional<T>::setValue(const T& value) {
	this->value = value;
	this->has_value = true;
}

template<typename T>
inline void Optional<T>::reset() {
	has_value = false;
}