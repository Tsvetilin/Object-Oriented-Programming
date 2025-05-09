#include "Price.h"

Price::Price()
{
	productId = 0;
	price = 0;
}
Price::Price(size_t productId, double price)
{
	this->productId = productId;
	this->price = price;
}
Price::~Price()
{
	productId = 0;
	price = 0;
}

double Price::getPrice() const { return price; }
size_t Price::getId() const { return productId; }
State Price::updatePrice(double amount)
{
	if (price + amount < 0) return State::NegativePrice;
	price += amount;
	return State::OK;
}

