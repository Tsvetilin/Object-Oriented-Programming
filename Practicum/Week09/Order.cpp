#include "Order.h"
#pragma warning(disable: 4996)

Order::~Order() {
	this->free();
}

void Order::setRestaurantName(const char* restaurantName) {
	if (restaurantName == nullptr) {
		throw std::invalid_argument("The restaurant name cannot be nullptr!");
	}

	delete[] this->restaurantName;

	this->restaurantName = new char[strlen(restaurantName) + 1];
	strcpy(this->restaurantName, restaurantName);
}

void Order::setProducts(size_t productsCount, const String* products, size_t productsCapacity) {
	if (products == nullptr) {
		throw std::invalid_argument("The products cannot be null!");
	}

	if (productsCount > productsCapacity) {
		throw std::invalid_argument("The size of your products list cannot be more of its capacity!");
	}

	delete[] this->products;

	this->productsCount = productsCount;
	this->productsCapacity = productsCapacity;
	this->products = new String[productsCapacity];
	for (size_t i = 0; i < productsCount; ++i) {
		this->products[i] = products[i];
	}
}

const char* Order::getRestaurantName() const {
	return this->restaurantName;
}

size_t Order::getProductsCount() const {
	return this->productsCount;
}

size_t Order::getProductsCapacity() const {
	return this->productsCapacity;
}

const String* Order::getProducts() const {
	return this->products;
}

void Order::addNewProduct(const String& product) {
	if (this->productsCount == this->productsCapacity) {
		resizeOrder();
	}

	this->products[this->productsCount] = product;
	++this->productsCount;
}

size_t Order::calcDeliveryTime() const {
	size_t deliveryTime = this->productsCount;
	for (size_t i = 0; i < this->productsCount; ++i) {
		deliveryTime += this->products[i].calcStrLen(this->products[i].getString());
	}

	return deliveryTime;
}

void Order::printOrder() const {
	std::cout << "This order is for restaurant '" << this->restaurantName << "' and it contains " << this->productsCount << " products." << std::endl;
	std::cout << "They are:" << std::endl;
	for (size_t i = 0; i < this->productsCount; ++i) {
		std::cout << this->products[i].getString() << std::endl;
	}
	std::cout << std::endl;
}

void Order::resizeOrder() {
	size_t newCapacity = this->productsCapacity * 2;
	String* newProducts = new String[newCapacity];

	for (size_t i = 0; i < this->productsCount; ++i) {
		newProducts[i] = this->products[i];
	}

	delete[] this->products;
	this->products = newProducts;
	this->productsCapacity = newCapacity;
}

void Order::copyFrom(const Order& other) {
	if (other.restaurantName == nullptr) {
		throw std::invalid_argument("The restaurant name cannot be nullptr!");
	}

	this->restaurantName = new char[strlen(other.restaurantName) + 1];
	strcpy(this->restaurantName, other.restaurantName);


	if (other.products == nullptr) {
		throw std::invalid_argument("The products cannot be null!");
	}

	if (other.productsCount > other.productsCapacity) {
		throw std::invalid_argument("The size of your products list cannot be more of its capacity!");
	}

	this->productsCount = other.productsCount;
	this->productsCapacity = other.productsCapacity;
	this->products = new String[other.productsCapacity];
	for (size_t i = 0; i < other.productsCount; ++i) {
		this->products[i] = other.products[i];
	}
}

void Order::moveFrom(Order&& other) noexcept {
	this->restaurantName = other.restaurantName;
	this->productsCount = other.productsCount;
	this->productsCapacity = other.productsCapacity;
	this->products = other.products;

	other.restaurantName = nullptr;
	other.productsCount = 0;
	other.productsCapacity = 0;
	other.products = nullptr;

}

void Order::freeRestaurantName() {
	delete[] this->restaurantName;
	this->restaurantName = nullptr;
}

void Order::freeProducts() {
	delete[] this->products;
	this->products = nullptr;
	this->productsCount = 0;
	this->productsCapacity = 0;
}

void Order::free() {
	this->freeRestaurantName();
	this->freeProducts();
}

Order::Order(const char* restaurantName, size_t productsCount, String* products, size_t productsCapacity) {
	setRestaurantName(restaurantName);
	setProducts(productsCount, products, productsCapacity);
}

Order::Order() {
	this->restaurantName = new char[1];
	this->restaurantName[0] = '\0';
	this->productsCount = 0;
	this->productsCapacity = 1;
	this->products = new String[this->productsCapacity];
}

Order::Order(const Order& other) {
	this->copyFrom(other);
}

Order& Order::operator=(const Order& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

Order::Order(Order&& other) noexcept {
	this->moveFrom(std::move(other));
}

Order& Order::operator=(Order&& other) noexcept {
	if (this != &other) {
		this->free();
		this->moveFrom(std::move(other));
	}

	return *this;
}