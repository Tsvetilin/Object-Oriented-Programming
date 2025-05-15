#ifndef _PAIR_H
#define _PAIR_H

#include<iostream>

template<typename K, typename V>
class Pair {
public:
	Pair() = default;
	Pair(const K& key, const V& value);

	const K& getKey() const;
	const V& getValue() const;

	void setKey(const K& key);
	void setKey(K&& key);

	void setValue(const V& value);
	void setValue(V&& value);

private:
	K key;
	V value;
};
#endif // !_PAIR_H

template<typename K, typename V>
inline Pair<K, V>::Pair(const K& key, const V& value) {
	setKey(key);
	setValue(value);
}

template<typename K, typename V>
inline const K& Pair<K, V>::getKey() const {
	return this->key;
}

template<typename K, typename V>
inline const V& Pair<K, V>::getValue() const {
	return this->value;
}

template<typename K, typename V>
inline void Pair<K, V>::setKey(const K& key) {
	this->key = key;
}

template<typename K, typename V>
inline void Pair<K, V>::setKey(K&& key) {
	this->key = std::move(key);
}

template<typename K, typename V>
inline void Pair<K, V>::setValue(const V& value) {
	this->value = value;
}

template<typename K, typename V>
inline void Pair<K, V>::setValue(V&& value) {
	this->value = std::move(value);
}