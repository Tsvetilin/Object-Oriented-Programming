#ifndef _FOODPANDA_H
#define _FOODPANDA_H

#include "Restaurant.h"
#include "Order.h"
#include<stdexcept>

class Foodpanda {
public:
	Foodpanda(Restaurant* restaurants, size_t restaurantsCount, size_t restaurantsCapacity);
	Foodpanda();
	Foodpanda(const Foodpanda& other);
	Foodpanda& operator=(const Foodpanda& other);
	Foodpanda(Foodpanda&& other) noexcept;
	Foodpanda& operator=(Foodpanda&& other) noexcept;
	~Foodpanda();

	void setRestaurants(Restaurant* restaurants, size_t restaurantsCount, size_t restaurantsCapacity);

	const Restaurant* getRestaurants() const;
	size_t getRestaurantsCount() const;
	size_t getRestaurantsCapacity() const;

	void addNewRestaurant(const Restaurant& newRestaurant);
	void addNewOrder(const Order& newOrder);

private:
	Restaurant* restaurants;
	size_t restaurantsCount;
	size_t restaurantsCapacity;

	void resizeRestaurants();
	void copyFrom(const Foodpanda& other);
	void moveFrom(Foodpanda&& other);
	void freeRestaurants();
};

#endif // !_FOODPANDA_H
