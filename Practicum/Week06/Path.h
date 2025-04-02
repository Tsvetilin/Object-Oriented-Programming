#ifndef _PATH_H
#define _PATH_H

#include "Town.h"

class Path {
public:
	Path(size_t size, size_t capacity, Town* towns);
	Path();
	Path(const Path& other);
	Path& operator=(const Path& other);
	~Path();

	void setSize(size_t size);
	void setCapacity(size_t capacity);
	void setTowns(const Town* towns);

	size_t getSize() const;
	size_t getCapacity() const;
	const Town* getTowns() const;
	
	bool townExists(size_t id);
	void addTown(const Town& newTown);
	size_t getTownIndex(const Town& town);
	void removeTown(const Town& toBeRemoved);

	void printPath();

	Path unite(const Path& other);
	Path intersect(const Path& other);
	bool containSameTowns(const Path& path1, const Path& path2) const;
	bool isPathEmpty(const Path& path) const;
	size_t countTownsInPath(const Path& path) const;
	bool containsTown(size_t index) const;
	size_t* getIdsOfAllTownsInPath(const Path& path) const;

private:
	size_t size;
	size_t capacity;
	Town* towns;

	void copyFrom(const Path& other);
	void free();
	void resizePath();
	size_t binarySearchAlgorithm(int id) const; // for most optimal searching for town - the algorithm is taken from: https://www.programiz.com/dsa/binary-search
};

#endif // !_PATH_H