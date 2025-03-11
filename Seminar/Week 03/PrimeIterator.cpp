#include <climits>
#include <cmath>
#include <iostream>

class Interval
{
	size_t start;
	size_t end;

public:
	Interval() : Interval(0, ULLONG_MAX) {}
	Interval(size_t start) : Interval(start, ULLONG_MAX) {}
	Interval(size_t start, size_t end) : start(start), end(end)
    {
		if (end < start)
		{
			end = ULLONG_MAX;
		}
	}

    size_t getEnd() const
	{
		return end;
	}

	size_t getStart() const
	{
		return start;
	}
};


class PrimeIterator
{
	Interval interval;
	size_t currentPrime = 0;

	mutable size_t calculatedNextPrime = 0;

public:
	PrimeIterator() : PrimeIterator(Interval()) {}
	//PrimeIterator(size_t start) : interval(Interval(start, ULLONG_MAX)){}
	PrimeIterator(const Interval& interval) : interval(interval), currentPrime(0)
	{
		// Advance to the first prime number
        currentPrime = interval.getStart() - 1;
		next();
	}

	bool hasNext() const
	{
		if (calculatedNextPrime != 0)
		{
			return true;
		}

		for (size_t i = currentPrime + 1; i <= interval.getEnd(); i++)
		{
			if (this->isPrime(i))
			{
				calculatedNextPrime = i;
				return true;
			}

            if(i == ULLONG_MAX)
            {
                break;    
            }
		}

		return false;
	}

	size_t next()
	{
		if (hasNext())
		{
			currentPrime = calculatedNextPrime;
			calculatedNextPrime = 0;
		}

		return currentPrime;
	}

	size_t current() const
	{
		return currentPrime;
	}

private:
	bool isPrime(size_t num) const
	{
		if (num < 2) return false;
		if (num == 2) return true;

		size_t root = sqrt(num);
		for (size_t i = 3; i <= root; i += 2)
		{
			if (num % i == 0)
			{
				return false;
			}
		}

		return true;
	}
};

int main()
{
    PrimeIterator it(Interval(ULLONG_MAX - 100));

    while (it.hasNext())
    {
        std::cout << it.next() << std::endl;
    }
}