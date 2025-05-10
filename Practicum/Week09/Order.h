#ifndef _ORDER_H
#define _ORDER_H

#include<cstring>
#include<stdexcept>
#include "String.h"

class Order {
public:
	Order(const char* restaurantName, size_t productsCount, String* products, size_t productsCapacity);
	Order();
	Order(const Order& other);
	Order& operator=(const Order& other);
	Order(Order&& other) noexcept;
	Order& operator=(Order&& other) noexcept;
	~Order();

	void setRestaurantName(const char* restaurantName);
	void setProducts(size_t productsCount, const String* products, size_t productsCapacity);

	const char* getRestaurantName() const;
	size_t getProductsCount() const;
	size_t getProductsCapacity() const;
	const String* getProducts() const;

	void addNewProduct(const String& product);
	size_t calcDeliveryTime() const;

	void printOrder() const;

private:
	char* restaurantName;
	size_t productsCount;
	String* products;
	size_t productsCapacity;

	void resizeOrder();
	void copyFrom(const Order& other);
	void moveFrom(Order&& other) noexcept;
	void freeRestaurantName();
	void freeProducts();
	void free();
};

#endif // !_ORDER_H
