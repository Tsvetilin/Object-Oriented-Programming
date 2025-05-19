#ifndef _COMPUTERSTORE_H
#define _COMPUTERSTORE_H

#include "Computer.h"
#include "ConsultantUtils.h"

class ComputerStore {
public:
	ComputerStore(const char* storeName);
	ComputerStore(const char* storeName, const Computer* computers, size_t size);
	ComputerStore();
	ComputerStore(const ComputerStore& other);
	ComputerStore& operator=(const ComputerStore& other);
	~ComputerStore();

	void setStoreName(const char* storeName);
	void setComputers(const Computer* computers, size_t size);

	const char* getStoreName() const;
	const Computer* getComputers() const;
	size_t getSize() const;

	void addComputer(const Computer& computer);
	void printAll() const;
	void buy(const char* brand, double money);
	void printAvailable(bool travel = false, bool gaming = false) const;

private:
	char* storeName;
	Computer* computers;
	size_t size;
	size_t capacity;

	void resize();
	void copyFrom(const ComputerStore& other);
	void freeComputers();
	void freeStoreName();
	void free();
};

#endif // !_COMPUTERSTORE_H