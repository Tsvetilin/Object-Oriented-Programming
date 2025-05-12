#include "ProductsDatabase.h"

void ProductsDatabase::copyFrom(const ProductsDatabase& other)
{
	products = new Product[other.size];
	size = other.size;
	for (size_t i = 0; i < size; i++)
	{
		products[i] = other.products[i];
	}
}

void ProductsDatabase::free()
{
	delete[] products;
	products = nullptr;
	size = 0;
}

ProductsDatabase::ProductsDatabase()
{
	products = new Product[0];
	size = 0;
}
ProductsDatabase::ProductsDatabase(Product* products, size_t size)
{
	this->products = new Product[size];
	this->size = size;
	for (size_t i = 0; i < size; i++)
	{
		this->products[i] = products[i];
	}
}
ProductsDatabase::ProductsDatabase(const ProductsDatabase& other)
{
	copyFrom(other);
}
ProductsDatabase& ProductsDatabase::operator=(const ProductsDatabase& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
ProductsDatabase::~ProductsDatabase()
{
	free();
}

State ProductsDatabase::addProduct(Product product)
{
	if (size + 1 > maxProducts) return State::ProductFull;
	size++;
	Product* res = new Product[size];
	for (size_t i = 0; i < size-1; i++)
	{
		res[i] = products[i];
	}
	delete[] products;
	res[size - 1] = product;
	products = res;
	return State::OK;
}

size_t ProductsDatabase::itemsOwned(size_t id, size_t prodId)
{
	size_t cnt = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (products[i].getOwnerId() == id && products[i].getProductId() == prodId) cnt++;
	}
	return cnt;
}

State ProductsDatabase::update(size_t id, size_t productId, int update)
{
	for (size_t i = 0; i < size; i++)
	{
		if (products[i].getOwnerId() == id && products[i].getProductId() == productId)
		{
			if (update < 0 && products[i].getQuantity() + update < 0) return State::NegativeQuantity;
			products[i].updateQuantity(update);
			return State::OK;
		}
	}
	return State::ProductNotFound;
}

State ProductsDatabase::existProduct(size_t id)
{
	for (size_t i = 0; i < size; i++)
	{
		if (products[i].getProductId() == id)
		{
			return State::OK;
		}
	}
	return State::ProductNotFound;
}

