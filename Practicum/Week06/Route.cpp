#include "Route.h"

void Route::copyFrom(const Route& other)
{
	size = other.size;
	towns = new Town[size];
	for (size_t i = 0; i < size; i++)
	{
		towns[i] = other.towns[i];
	}
}

void Route::free()
{
	delete[] towns;
	size = 0;
}

Route::Route()
{
	towns = nullptr;
	size = 0;
}

Route::Route(Town* towns, size_t size)
{
	this->size = size;
	this->towns = new Town[size];
	for (size_t i = 0; i < size; i++)
	{
		this->towns[i] = towns[i];
	}
}

Route::Route(const Route& other)
{
	copyFrom(other);
}

Route& Route::operator=(const Route& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Route::~Route()
{
	free();
}

void Route::addTown(Town town)
{
	size++;
	Town* res = new Town[size];
	for (size_t i = 0; i < size-1; i++)
	{
		res[i] = towns[i];
	}
	res[size - 1] = town;
	delete[] towns;
	towns = res;
}

void Route::removeTown(Town town)
{
	Town* res = new Town[--size];
	for (size_t i = 0; i < size; i++)
	{
		res[i] = towns[i];
	}
	delete[] towns;
	towns = res;
}

bool Route::isInRoute(Town town) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (towns[i].getId() == town.getId()) return true;
	}
	return false;
}

Route Route::unify(const Route& other) const  
{  
  size_t resSize = size + other.size;  
  Town* res = new Town[resSize];  
  for (size_t i = 0; i < resSize; i++)  
  {  
	  if (i < size)
	  {
		res[i] = towns[i];  
		continue;
	  }
      res[i] = other.towns[i - size];
  }  
  return Route(res, resSize);  
}

Route Route::cut(const Route& other) const
{
	size_t resSize = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		if (other.isInRoute(towns[i]))
		{
			resSize++;
		}
	}
	Town* res = new Town[resSize];
	for (size_t i = 0; i < resSize; i++)
	{
		for (size_t j = 0; i < this->size; i++)
		{
			if (other.isInRoute(towns[j]))
			{
				res[i] = towns[j];
			}
		}
	}
	return Route(res, resSize);
}

bool Route::haveSameTowns(const Route& other) const
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (!other.isInRoute(towns[i])) return false;
	}
	return true;
}


bool Route::hasTowns() const
{
	return !size;
}

bool Route::exists(size_t townId) const
{
	Town a; 
	a.setId(townId);
	return isInRoute(a);
}


size_t Route::getTownsCnt() const
{
	return size;
}

size_t* Route::getTownsIds() const
{
	size_t* res = new size_t[size];
	for (size_t i = 0; i < size; i++)
	{
		res[i] = towns->getId();
	}
	return res;
}


