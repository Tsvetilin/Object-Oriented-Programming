#ifndef _SPECIALCUSTOMFUNCTION_H
#define _SPECIALCUSTOMFUNCTION_H

#include <stdexcept>

class SpecialCustomFunction {
public:
	SpecialCustomFunction(int (*func)(int), const int* specialSymbols, size_t specialSymbolsSize);
	SpecialCustomFunction();
	SpecialCustomFunction(const SpecialCustomFunction& other);
	SpecialCustomFunction& operator=(const SpecialCustomFunction& other);
	~SpecialCustomFunction();

	void setFunction(int (*func)(int));
	void setSpecialSymbols(const int* specialSymbols, size_t specialSymbolsSize);

	int getFunction(int x) const;
	const int* getSpecialSymbols() const;
	size_t getSpecialSymbolsSize() const;

	int operator()(int value);

	SpecialCustomFunction& operator++();
	SpecialCustomFunction& operator--();

	SpecialCustomFunction operator!() const;

private:
	int (*func)(int);
	int* specialSymbols;
	size_t specialSymbolsSize;

	void copyFrom(const SpecialCustomFunction& other);
	void free();
};

#endif // !_SPECIALCUSTOMFUNCTION_H
