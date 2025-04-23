#pragma once
#include "Product.h"
#include "States.h"

class ProductsDatabase
{
	const size_t maxProducts = 100;
public:
	void copyFrom(const ProductsDatabase& other);
	void free();
	ProductsDatabase();
	ProductsDatabase(Product* products,size_t size);
	ProductsDatabase(const ProductsDatabase& other);
	ProductsDatabase& operator=(const ProductsDatabase& other);
	~ProductsDatabase();

	State addProduct(Product product);
	size_t itemsOwned(size_t id, size_t prodId);
	State update(size_t id, size_t productId, int update);
	State existProduct(size_t id);

private:
	Product* products;
	size_t size;
};