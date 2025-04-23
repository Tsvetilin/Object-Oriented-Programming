#pragma once
#include "Town.h"


class Route
{
private:
	Town* towns = nullptr;
	size_t size;

	void copyFrom(const Route& other);
	void free();
public:
	Route();
	Route(Town* towns, size_t size);
	Route(const Route& other);
	Route& operator=(const Route& other);
	~Route();

	void addTown(Town town);
	void removeTown(Town town);
	bool isInRoute(Town town) const;
	Route unify(const Route& other) const ;
	Route cut(const Route& other) const ;
	bool haveSameTowns(const Route& other) const;
	bool hasTowns()const;
	bool exists(size_t townId) const;
	size_t getTownsCnt() const;
	size_t* getTownsIds() const;

};

