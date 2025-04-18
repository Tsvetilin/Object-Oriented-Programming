#pragma once
#include <iostream>

#define powerTwo(x) (1 << x)

namespace Constants {
	constexpr size_t BITS = 8;
}

class BitSet
{
private:
	uint8_t* data;
	size_t N;
	size_t bucketsCount;

	size_t getBucketIndex(size_t num) const;

	void copyFrom(const BitSet& other);
	void free();

public:
	BitSet();
	explicit BitSet(size_t N);

	void add(size_t num);
	void remove(size_t num);
	bool contains(size_t num) const;

	void print() const;

	friend BitSet unify(const BitSet& lhs, const BitSet& rhs);
	friend BitSet intersect(const BitSet& lhs, const BitSet& rhs);

	BitSet(const BitSet& other);
	BitSet& operator=(const BitSet& other);

	~BitSet();
};
