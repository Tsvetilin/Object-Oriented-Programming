#pragma once
#include "User.h"
#include "Product.h"
#include "Price.h"
#include "UserDatabase.h"
#include "ProductsDatabase.h"
#include "PricesDatabase.h"


class SalesSystem
{
public:
	void copyFrom(const SalesSystem& other);
	void free();
	SalesSystem();
	SalesSystem& operator=(const SalesSystem& other);
	SalesSystem(const SalesSystem& other);
	~SalesSystem();

	State addUser(User user);
	State addProduct(Product product);
	State addPrice(Price price);

	State sell(size_t idFrom, size_t IdTo, size_t productId, size_t quantity);

private:
	UserDatabase users;
	ProductsDatabase products;
	PricesDatabase prices;
};