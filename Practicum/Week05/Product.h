#pragma once
#include "States.h"

class Product
{
public:
	Product();
	void copyFrom(const Product& other);
	void free();
	Product(const char* name, size_t ownedId, size_t quantity, size_t productId);
	Product& operator=(const Product& other);
	Product(const Product& other);
	~Product();

	size_t getQuantity() const;
	State updateQuantity(int amount);
	size_t getProductId() const;
	size_t getOwnerId() const;

private:
	char* name;
	size_t ownedId;
	size_t quantity;
	size_t productId;
};