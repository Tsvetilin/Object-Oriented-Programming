#include "BitSet.h"

BitSet::BitSet() : data(nullptr), N(0), bucketsCount(0)
{
}

BitSet::BitSet(size_t N) : N(N)
{
	this->bucketsCount = getBucketIndex(N) + 1;
	this->data = new uint8_t[this->bucketsCount]{ 0 };
}

void BitSet::add(size_t num)
{
	size_t currBucket = getBucketIndex(num);
	num %= Constants::BITS;

	uint8_t mask = powerTwo(num);

	this->data[currBucket] |= mask;
}

void BitSet::remove(size_t num)
{
	size_t currBucket = getBucketIndex(num);
	num %= Constants::BITS;

	uint8_t mask = ~powerTwo(num);

	this->data[currBucket] &= mask;
}

bool BitSet::contains(size_t num) const
{
	size_t currBucket = getBucketIndex(num);
	num %= Constants::BITS;

	uint8_t mask = powerTwo(num);

	return mask & this->data[currBucket];
}

void BitSet::print() const
{
	for (size_t i = 0; i <= this->N; i++)
	{
		if (contains(i))
		{
			std::cout << i << " ";
		}
	}

	std::cout << std::endl;
}

BitSet unify(const BitSet& lhs, const BitSet& rhs)
{
	BitSet toReturn(std::max(lhs.N, rhs.N));

	size_t minBuckets = std::min(lhs.bucketsCount, rhs.bucketsCount);

	for (size_t i = 0; i < minBuckets; i++)
	{
		toReturn.data[i] = lhs.data[i] | rhs.data[i];
	}

	const BitSet& biggerN = (lhs.N > rhs.N) ? lhs : rhs;

	for (size_t i = minBuckets; i < biggerN.bucketsCount; i++)
	{
		toReturn.data[i] = biggerN.data[i];
	}

	return toReturn;
}

BitSet intersect(const BitSet& lhs, const BitSet& rhs)
{
	BitSet toReturn(std::min(lhs.N, rhs.N));

	for (size_t i = 0; i < toReturn.bucketsCount; i++)
	{
		toReturn.data[i] = lhs.data[i] & rhs.data[i];
	}

	return toReturn;
}

BitSet::BitSet(const BitSet& other)
{
	copyFrom(other);
}

BitSet& BitSet::operator=(const BitSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

BitSet::~BitSet()
{
	free();
}

size_t BitSet::getBucketIndex(size_t num) const
{
	return num / Constants::BITS;
}

void BitSet::copyFrom(const BitSet& other)
{
	this->N = other.N;
	this->bucketsCount = other.bucketsCount;

	this->data = new uint8_t[this->bucketsCount];

	for (size_t i = 0; i < this->bucketsCount; i++)
	{
		this->data[i] = other.data[i];
	}
}

void BitSet::free()
{
	delete[] this->data;

	this->data = nullptr;
	this->bucketsCount = this->N = 0;
}
