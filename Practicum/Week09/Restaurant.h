#ifndef _RESTAURANT_H
#define _RESTAURANT_H

#include "String.h"
#include "Order.h"
#include<iostream>
#include<stdexcept>
#include<cstring>

const size_t MAX_RESTAURANT_NAME_LEN = 25;

class Restaurant {
public:
	Restaurant(const char* name, const String* productList, size_t productListSize, size_t productListCapacity);
	Restaurant();
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(Restaurant&& other) noexcept;
	~Restaurant();

	void setName(const char* name);
	void setProductList(const String* productList, size_t productListSize, size_t productListCapacity);

	const char* getName() const;
	const String* getProductList() const;
	size_t getProductListSize() const;
	size_t getProductListCapacity() const;

	void addNewProductToList(const String& newPoroduct);
	void receiveOrder(const Order& order) const;

private:
	char name[MAX_RESTAURANT_NAME_LEN + 1];
	String* productList;
	size_t productListSize;
	size_t productListCapacity;

	void resizeProductList();
	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&& other) noexcept;
	void freeProductList();
	void free();
};

#endif // !_RESTAURANT_H
